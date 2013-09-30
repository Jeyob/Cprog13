#include "vector.h"

unsigned int& Vector::operator [](const size_t pos) {
	if (pos >= vSize) {
		throw std::out_of_range("subscript out of bounds");
	} else {
		return aryPtr[pos];
	}
}

const unsigned int& Vector::operator [](const size_t pos) const {
	if (pos >= vSize) {
		throw std::out_of_range("subscript out of bounds");
	} else {
		return aryPtr[pos];
	}
}

Vector& Vector::operator=(const Vector& v) {
	if (this != &v) {
		vSize = v.vSize;
		vCapacity = v.vCapacity;

		delete[] aryPtr; //remove old ptr

		aryPtr = new unsigned int[vCapacity];

		for(unsigned int i = 0; i < vCapacity; ++i){
			aryPtr[i] = v.aryPtr[i];
		}
	}

	return *this;
}

Vector& Vector::operator=(Vector && other){

	if(this!=&other) {

		vSize = other.vSize;
		vCapacity = other.vCapacity;
		aryPtr = other.aryPtr;

		other.vSize = 0;
		other.vCapacity = 0;
		other.aryPtr = NULL;

	}
	return *this;
}

Vector& Vector::operator=(std::initializer_list<unsigned int> list){

	if(list.size()>0){

		resize(0);

		for(std::initializer_list<unsigned int>::iterator iter = list.begin(); iter!=list.end(); iter++){
			push_back(*iter);
		}
	}

	return *this;
}

void Vector::reservera(const size_t nCapacity) {

	if(nCapacity < 0){
		throw std::invalid_argument("negativ capacity not allowed");
		return;
	}

	unsigned int * tmp = aryPtr;
	aryPtr = new unsigned int[nCapacity];
	memcpy(aryPtr,tmp,sizeof(unsigned int));

	delete[] tmp;

}

size_t Vector::push_back(unsigned int value){
		//check if more space needed?
	try {
		if(vSize == vCapacity){
			reservera(2*vSize);
		}
		aryPtr[vSize] = value;
		++vSize;
	}catch(std::exception& e){
		std::cout<<e.what()<<std::endl;
	}

	return vSize-1;
}

void Vector::shift_right(const size_t pos, const size_t end, size_t inValue) {
	//How many items need be shifted
	size_t diff = ( pos == 0 ? end : (end - pos) + 1 );

	//shift memory to right starting from insertation position
	memmove(aryPtr, aryPtr+pos+1, sizeof(size_t)*diff);

	//insert value at index pos
	aryPtr[pos] = inValue;

}

void Vector::resize(const size_t size){
	if (size > vCapacity){ // Behöver vi utöka kapaciteten?
			reservera(2 * size + 1);
	}

	vSize = size; //storleken måste uppdateras
}


