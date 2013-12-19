#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <initializer_list>
#include <cstdlib>
#include <stdexcept>
#include <string.h>
#include <string>

#define spareCapacity 20

class Vector {

public:



	Vector(): aryPtr(new unsigned int[spareCapacity]()), vSize(0), vCapacity(spareCapacity)  {
//		for(unsigned int i = 0; i < vCapacity; ++i){
//			aryPtr[i] = 0;
//		}


	}

	//explicit constructor for avoiding implicit type conversions
	explicit Vector(const size_t size) : vSize(size){
		vCapacity = (vSize + spareCapacity);
		aryPtr = new unsigned int[vCapacity]();

//		for(unsigned int i = 0; i < vCapacity; ++i){
//			aryPtr[i] = 0;
//		}
	}

	/*
	 *
	 * Copy constructor
	 *
	 */
	Vector(const Vector& other) :
			aryPtr(NULL) {
		operator=(other); //pass it on to assigment constructor.
	}

	/*
	 *
	 * Move constructor
	 *
	 */

	Vector(Vector&& other):
		aryPtr(other.aryPtr),
		vSize(other.vSize),
		vCapacity(other.vCapacity)
	{
		other.aryPtr = NULL;
	}

	/*
	 *
	 * Destructor
	 *
	 */
	~Vector() {
		delete[] aryPtr; //free memory used by array
	}


	/*
	 *
	 * Assignment operator
	 *
	 * Allows assignment of vectors of different sizes as well.
	 *
	 */
	Vector& operator=(const Vector&);

	/*
	 *
	 * Move assignment operator
	 *
	 */
	Vector& operator=(Vector&&);

	Vector& operator=(std::initializer_list<unsigned int>);

	/*
	 *
	 * Index operator for fast access of element
	 *
	 * Throws an exception if index out-of-bounds
	 *
	 *
	 */
	unsigned int& operator[](const size_t);

	/*
	 *
	 * Index operator respecting the constentness restriction
	 *
	 */
	const unsigned int& operator[](const size_t) const;


	void resize(const size_t);

	void reservera(const size_t);

	size_t push_back(unsigned int);


	void showVector() const { //skriver ut vår vekor
		for (size_t i = 0; i < vSize; i++) {
			std::cout << aryPtr[i] << " ";
		}
		std::cout << std::endl;
	}

	void print() {

		std::cout<< "Test" <<std::endl;
	}

private:

	void shift_right(const size_t, const size_t, size_t);

	unsigned int * aryPtr; //pointer to array of unsigned int's
	size_t vSize; //filled items
	size_t vCapacity; //vCapacity of number of elements

}; /* END OF Vector header */



#endif /* VECTOR_H_ */
