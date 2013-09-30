/*
 * vector.h
 *
 *  Created on: 28 sep 2011
 *      Author: his-royalhighness
 */

#ifndef VECTOR_H_
#define VECTOR_H_

/*
 * Vektor.h
 *
 *  Created on: 18 sep 2011
 *      Author: his-royalhighness
 */

/*
 * Vector.cpp
 *
 *  Created on: 22 sep 2011
 *      Author: his-royalhighness
 */

#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <cstdlib>

#define spareCapacity 20

template<class T>

class Vector {

public:

	Vector() :
			vSize(0), vCapacity(vSize + spareCapacity), elem(new T[vCapacity]()) {
	}
	; /* kapacitet sätts till dubbelt som vSize */

	Vector(size_t vSize, T ini_value) :
			vSize(vSize), vCapacity(vSize + spareCapacity), elem(
					new T[vCapacity]) {
		for (size_t i = 0; i < vSize; i++)
			elem[i] = ini_value;
	}

	explicit Vector(size_t vSize) :
			vSize(vSize), vCapacity(vSize + spareCapacity), elem(
					new T[vCapacity]()) {
	}
	; // explicit för att undvika implicit conversions

	Vector(const Vector<T> & v):elem(0) {
		operator =(v); /* Eftersom tilldelning och kopiering gör samma sak så skickar vi vidare den */
	}

	~Vector() {
		delete[] elem;
	}

	T& operator[](const size_t&);

	const T& operator[](const size_t&) const; // Eftersom const objekt kräver att man har en operator som tar hänsyn till const egenskapen.

	Vector<T>& operator=(const Vector<T>&);

	Vector<T>& operator<(const Vector<T>&);

	int push_back(T);

	void insert(const size_t& i, T);

	void erase(size_t i);

	void clear() { //skapar en ny vektor med default storlek, men inte så användaren är medveten om
		delete[] elem;
		vCapacity = spareCapacity;
		vSize = 0;
		elem = new T[vCapacity];
	}

	size_t size() const {
		return vSize;
	}

	void sort(bool);

	void resize(const size_t& i); /* När vektorn behöver växa */

	void reservera(const size_t& newCapacity);

	void shift_right(const size_t& pos, const size_t& end, T* array);
	/*******************************************/

	void showVector();

private:
	size_t vSize; /* antal element i vektorn */
	size_t vCapacity; /* Kapaciteten sätts till ett större tal än vSize så vi slipper skapa en ny array för varje gång det ska läggas in något */
	//size_t nElem; /* Antal element i listan */
	T * elem; /* Vår array som håller objekt av godtycklig typ */

};

/******************************************************************************************************************************/
/*****************************************END OF CLASS DEFINITON ************************************************************************/
/******************************************************************************************************************************/

//template<class T>
//Vector<T>::Vector(size_t vSize) : //använder mig av explicit fär att undvika implicit conversions
//                vSize(vSize), vCapacity(vSize + spareCapacity), elem(new T[vCapacity]()) {
//} //annan konstruktur som tar antal element
/*template<class T>
 Vector<T>::Vector(const Vector<T> & v) :
 vSize(v.vSize), vCapacity(v.vCapacity), elem(new T[vSize]) //Koperingskonstruktur och eftersim den avänds implicit så ska man inte sätta den till explicit
 {

 for (size_t i = 0; i < vSize; i++)
 elem[i] = v.elem[i];
 }
 */
/************************************** OPERATOR OVERLOAD *****************************************************************/

//Så länge vi returnear en referens så kan vi hade opertor [] på både vänster(write) och höger sida(read)
template<class T>
T& Vector<T>::operator[](const size_t& i) {
	if (i >= vSize)
		throw std::out_of_range("subscript out of bounds");
	else
		return elem[i];
}

template<class T>
const T& Vector<T>::operator[](const size_t& i) const {

	if (i >= vSize)
		throw std::out_of_range("subscript out of bounds");
	else
		return elem[i];
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v) {

	if (this != &v) { /* v = v? weird, why would you do that */
		vSize = v.vSize;
		vCapacity = v.vCapacity;
		delete[] elem; /* Tar bort den tidigare arrayen och skapar ny, annars kommer det bli en minnesläcka om vi bara pekar om */
		elem = new T[vCapacity];
		for (size_t i = 0; i < vSize; i++)
			elem[i] = v.elem[i];
	}
	return *this;
}

/******************************************** END OPERATOR OVERLOAD ****************************************************/

template<class T>

void Vector<T>::reservera(const size_t& newCapacity) {
	T * tmp = elem; // Det som elem pekar på ska tmp peka på, ingen minnesläcka

	vCapacity = newCapacity;
	elem = new T[vCapacity];
	for (size_t x = 0; x < vSize; x++)
		elem[x] = tmp[x];

	delete[] tmp; //clean up
}

template<class T>
void Vector<T>::resize(const size_t& i) { // i nystorlek

	if (i > vCapacity) // Behöver vi utöka kapaciteten?
		reservera(2 * i + 1);

	vSize = i; //storleken måste uppdateras
}

/********************************** INSERTATION/DELETATION *************************************************/

template<class T>
int Vector<T>::push_back(T el) {

	if (vSize == vCapacity) //Kollar om vi behöver utöka
		reservera(2 * vSize);

	elem[vSize] = el;
	vSize++;
	return 0;
}

/*
 *	19/10/2011: Changed: removed the equal sign in the first conditional
 */
template<class T>
void Vector<T>::insert(const size_t& pos, T obj) {
	if (pos <= vSize && pos >= 0) {
		if (pos == vSize) // om platsen vi ska sätta in den på är antal element i listan
			push_back(obj);
		else {
			if (vSize >= vCapacity)
				reservera(2 * vSize);

			shift_right(pos, vSize, elem); //flyttar alla elemnet tillhöger om pos till höger
			elem[pos] = obj;
			vSize++;
		}
	} else
		throw std::out_of_range("Index of of bounds");
}

template<class T>
void Vector<T>::erase(size_t index) {
	if (vSize < index || index < 0)
		throw std::out_of_range("subscript out of bounds");
	else {
		try {
			//delete &elem[index - 1];
			if (vSize == 1) {
				delete[] elem;
				vSize--;
			} else {
				elem[index].~T(); // invoke destructur
				for (; index < vSize; index++) //shiftar allt till höger
					elem[index] = elem[index + 1];
				vSize--;
			}
		} catch (std::exception& e) {
			for (; index < vSize; index++) //shiftar allt till höger
				elem[index] = elem[index + 1];
			vSize--;
		}

	}
}

/************************************* END INSERTATION **********************************************/

template<class T>
void Vector<T>::shift_right(const size_t& pos, const size_t& end, T* array) {
	int diff = (pos == 0 ? end : (end - pos) + 1);
	T tmp[diff];

	for (size_t i = pos, j = 0; i < end; i++, j++) //Flyttar över alla element från den från den gamla till den nya (större)
		tmp[j] = array[i];

	for (size_t j = (pos + 1), k = 0; j < end + 1; j++, k++)
		array[j] = tmp[k];

}

template<class T>
void Vector<T>::sort(bool ascending = true) { //Bubbelsort O(n²)
	size_t n = vSize;
	for (size_t j = 1; j < n; j++) {
		for (size_t i = 0; i < n - j; i++) {
			if (ascending) {
				if (elem[i + 1] < elem[i]) {
					T temp = elem[i];
					elem[i] = elem[i + 1];
					elem[i + 1] = temp;
				}
			} else {
				if (elem[i] < elem[i + 1]) {
					T temp = elem[i + 1];
					elem[i + 1] = elem[i];
					elem[i] = temp;
				}
			}

		}
	}
}

template<class T>

void Vector<T>::showVector() { //skriver ut vår vekor
		for (size_t i = 0; i < vSize; i++) {
			std::cout << elem[i] << " ";
		}
		std::cout << std::endl;
	}

#endif /* VECTOR_H_ */
