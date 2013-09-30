//#include "vector.h"
#include <stdexcept>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <initializer_list>

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this != &other) { //check self assignment
		_size_ = other._size_;
		_capacity_ = other._capacity_;

		free(); //free current vector

		_elemAry_ = new T[_capacity_]();

		memcpy(_elemAry_, other._elemAry_, sizeof(T) * _size_);

	}
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> && other) {
	if( this!= other ) {
		_size_ = other._size_;
		_capacity_ = other._capacity_;
		_elemAry_ = other._elemAry_;

		other._elemAry_ = NULL;
	}
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(std::initializer_list<T> list) {
	if ( list.size() > 0 ) {
		clear();

		for( typename std::initializer_list<T>::iterator iter = list.begin();
				iter != list.end(); iter++ ) {
			push_back(*iter);
		}
	}
	return *this;
}

template <typename T>
T& Vector<T>::operator[](const size_t pos) {
	if (pos >= _size_) {
		throw std::out_of_range("subscript out of bounds");
	}
	return _elemAry_[pos];
}

template <typename T>
const T& Vector<T>::operator[](const size_t pos) const {
	if (pos >= _size_) {
		throw std::out_of_range("subscript out of bounds");
	}

	return _elemAry_[pos];
}

template <typename T>
void Vector<T>::insert(size_t before, T elem) {
	if (before >= _size_ || before < 0) {
		throw std::out_of_range("subscript out of bounds");
	}

		shift_right(before); //shift all element one step to right from pos

		_elemAry_[before] = elem;
		++_size_;
	}


template <typename T>
void Vector<T>::push_back(T element) {
	//control vector size
	check_need_alloc();

	//insert and increment
	_elemAry_[_size_++] = element;

}

//moves all elements 1 step to the right starting at "start"
template <typename T>
void Vector<T>::shift_right(const size_t start) {
	try {
		//check space
		check_need_alloc();

		//shift elements
		memmove(_elemAry_ + start + 1, _elemAry_ + start,
				sizeof(T) * (_size_ - start));
	} catch (std::exception& e) {
		std::cout << "Shift not possible" << std::endl;
	}
}


template <typename T>
void Vector<T>::reserve(const size_t capacity) {

	if(capacity < 0){
		throw std::invalid_argument("negativ capacity not allowed");
	}

	T* tmp = _elemAry_;
	_elemAry_ = new T[capacity]();

	//copy elements
	memcpy(_elemAry_,tmp, sizeof(T)*_size_);

	_capacity_ = capacity;

	//clean up
	delete[] tmp;

}

template <typename T>
void Vector<T>::sort(bool ascending) {
	if(ascending) {
		std::sort(this->begin(),this->end(),std::less<T>());
	}else {
		std::sort(this->begin(),this->end(),std::greater<T>());
	}
}

template <typename T>
void Vector<T>::clear(){
	free();
}

template <typename T>
void Vector<T>::erase(size_t pos) {

	if( pos > _size_ || pos < 0) {
		throw std::out_of_range("index position out of bounds");
	}

	try {
		_elemAry_[pos].~T();

		if(_size_-1) {
			memmove(_elemAry_+pos, _elemAry_+(pos+1),sizeof(T)*(_size_-pos));
			--_size_;
		}

	}catch(std::exception& e) {
		std::cout<<e.what()<<std::endl;
	}
}


