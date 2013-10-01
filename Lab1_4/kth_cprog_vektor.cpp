#include <memory>
#include <cstddef>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <cstdlib>
#include <initializer_list>
#include <sstream>
#include <functional>

#ifndef VECTOR_H_
#define VECTOR_H_

#define spareCapacity 20

template<class T>
class Vector {

public:
	friend class TemplateTestSuite; /* used for cxxtest */

	Vector() :
			_size_(0), _capacity_(spareCapacity), _elemAry_(
					new T[spareCapacity]) {
	}

	explicit Vector(const size_t size) :
			_size_(size), _capacity_(_size_ + spareCapacity), _elemAry_(
					new T[size + spareCapacity]()) {
	}

	Vector(size_t size, T init_val) :
			_size_(size), _capacity_(size + spareCapacity), _elemAry_(
					new T[size + spareCapacity]) {

		for (unsigned int i = 0; i < _size_ + spareCapacity; ++i) {
			_elemAry_[i] = init_val;
		}
	}
	;

	Vector(const Vector<T>& other) :
			_elemAry_(NULL) { //copy constructor
		operator =(other); //forward to assignment operator
	}

	Vector(Vector<T> && other) //move constructor
			: _size_(other._size_),
			_capacity_(other._capacity_),
			_elemAry_(other._elemAry_)
			{

			//leave in a destructable state
			other._elemAry_ = NULL;
			other._size_ = 0;
			other._capacity_ = 0;
		}

		~Vector() { //Destructor
			delete[] _elemAry_;
		}

		Vector<T>& operator=(const Vector<T>&); // copy assignment operator
		Vector<T>& operator=(Vector<T>&&);//move assignment operator
		Vector<T>& operator=(std::initializer_list<T>);
		T& operator[](const size_t);
		const T& operator[](const size_t) const;
		void push_back(T);
		size_t size() const {return _size_;} //number of acutal items
		size_t capacity() {return _capacity_;} //capacity of vecotr
		void insert(size_t, T);//insert item T, before item at pos size_t
		void clear();//clears all items in array
		void erase(size_t);//erase items at position
		void erase(T* start, T* end);
		bool exists(const T &);//check existens
		void sort(bool ascending = true);
		void unique_sort(bool ascending = true);
		T* begin() {return _elemAry_;}
		T* end() {return _elemAry_+_size_;}

		std::string showVector() const { //skriver ut vår vekor
			std::stringstream ss;
			std::string vStr = "";
			for (size_t i = 0; i < _size_; i++) {
				ss << _elemAry_[i] << " ";
			}
			return ss.str();
		}
	private:

		void _free_() {
			delete[] _elemAry_; //free memory!
			_elemAry_ = NULL;
			_capacity_ = 0;
			_size_ = 0;
		}

		void reserve(const size_t);

		void check_need_alloc() {
			if(_size_ == _capacity_) {
				if (_capacity_ == 0) {
					reserve(spareCapacity);
				} else {
					reserve(2*_capacity_);
				}
			}
		}

		/**
		 * shift_right
		 *
		 * @param: this parameter tells us the pivotal point
		 */
		void shift_right( const size_t );

		/***
		 * shift_left
		 *
		 * @param shift contents of the array to the left
		 */
		void shift_left( const size_t );

		size_t _size_; //filled items
		size_t _capacity_;//vCapacity of number of elements
		T* _elemAry_;//pointer to array of unsigned int's

	};

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this != &other) { //check self assignment
		_free_(); //free current vector

		_size_ = other._size_;
		_capacity_ = other._capacity_;
		_elemAry_ = new T[_capacity_]();

		size_t pos = 0;
		for( int pos = 0; pos != other._size_; ++pos ) {
			_elemAry_[pos] = other[pos];
		}

//		memcpy(_elemAry_, other._elemAry_, sizeof(T) * _size_);

	}
	return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T> && other) {

	if( this != &other ) { //check for self-assignment
			delete[] _elemAry_;//free dynamic memory
			_size_ = other._size_;
			_capacity_ = other._capacity_;
			_elemAry_ = other._elemAry_;

			//leave other in a destructable state
			other._elemAry_ = NULL;
		}

		return *this;
	}

template<typename T>
Vector<T>& Vector<T>::operator=(std::initializer_list<T> list) {
	if (list.size() > 0) {
		clear();

		for (typename std::initializer_list<T>::iterator iter = list.begin();
				iter != list.end(); ++iter) {
			push_back(*iter);
		}
	}
	return *this;
}

template<typename T>
T& Vector<T>::operator[](const size_t pos) {
	if (pos >= _size_) {
		throw std::out_of_range("subscript out of bounds");
	}
	return _elemAry_[pos];
}

template<typename T>
const T& Vector<T>::operator[](const size_t pos) const {
	if (pos >= _size_) {
		throw std::out_of_range("subscript out of bounds");
	}

	return _elemAry_[pos];
}

template<typename T>
void Vector<T>::insert(size_t before, T elem) {
	if (before > _size_) {
		throw std::out_of_range("subscript out of bounds");
	}

	shift_right(before); //shift all element one step to right from pos

	_elemAry_[before] = elem;
	++_size_;
}

template<typename T>
void Vector<T>::push_back(T element) {
	//control vector size
	check_need_alloc();

	//insert and increment
	_elemAry_[_size_++] = element;

}

//moves all elements 1 step to the right starting at "start"
template<typename T>
void Vector<T>::shift_right(const size_t start) {
	try {
		//check space
		check_need_alloc();

		int pos = this->_size_-1;
		for( T* currPtr = this->end()-1; currPtr!=(this->begin()+start)-1; --currPtr, --pos ){
			this->_elemAry_[pos+1] = this->_elemAry_[pos];
		}

//		//shift elements
//		memmove(_elemAry_ + start + 1, _elemAry_ + start,
//				sizeof(T) * ( _size_ - start));

	} catch (std::exception& e) {
		std::cout << "Shift not possible" << std::endl;
	}
}

template<typename T>
void Vector<T>::shift_left( const size_t start ) {
	try {

		int pos = start;
		for( T* currPtr = this->begin() + pos; currPtr!=this->end(); ++currPtr, ++pos ){
			this->_elemAry_[pos-1] = this->_elemAry_[pos];
		}

	}catch (std::exception& e) {

	}
}

template<typename T>
void Vector<T>::reserve(const size_t capacity) {

	T* tmp = _elemAry_;
	_elemAry_ = new T[capacity]();
	//copy elements

	for( size_t i = 0; i < this->size(); ++i ) { _elemAry_[i] = tmp[i]; }
	_capacity_ = capacity;

	tmp = NULL;
//	memcpy(_elemAry_, tmp, sizeof(T) * _size_);
	//clean up
//	delete[] tmp;

}

template<typename T>
void Vector<T>::sort(bool ascending) {
	std::sort(this->begin(), this->end(), std::less<T>());
	if (!ascending) {
		std::reverse(this->begin(), this->end() );
	}
}

template<typename T>
void Vector<T>::unique_sort(bool ascending) {

	/* perform a normal sort */
	sort(ascending);

	/* remove any duplicates */
	T* It = std::unique(this->begin(), this->end());
	erase(It, this->end()); //delete all elements beyond It.
	_size_ = std::distance(this->begin(), It);

}

template<typename T>
void Vector<T>::clear() {
	_free_();
}

template<typename T>
void Vector<T>::erase(size_t pos) {
	if (pos >= _size_) {
		throw std::out_of_range("index position out of bounds");
	}
	try {
		//call destructor on element
		_elemAry_[pos].~T();

		//last element in array?
		if (_size_ - 1) {
			//if we get here not last element in array

			//erasing last element?
			if (_size_ != pos + 1) {
				shift_left(pos + 1);
//				memmove(_elemAry_ + pos, _elemAry_ + (pos + 1),
//						sizeof(T) * (_size_ - pos)); //shift to left
			}
		}
			--_size_;

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

template<typename T>
void Vector<T>::erase(T* start, T* end) {
	int iters = 0;
	for (T * last = end-1; last != start-1; last--, iters++ ) {
		erase( std::distance(this->begin(), last)); //invoke call to erase in order to move a collection of values
	}
}

template<typename T>
bool Vector<T>::exists(const T& item) {

	return (std::find(this->begin(), this->end(), item) != this->end());

}

#endif /* VECTOR_H_ */
