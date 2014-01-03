#ifndef CALENDAR_H_
#define CALENDAR_H_

#include <cstring>
#include "date.h"
#include <type_traits>
#include "kattistime.h"
#include <map>

namespace lab2 {

template <typename T> class Calendar {
//	static_assert(std::is_base_of<Date,T>::value,"Class must be derived of Date");

private:
 Date * basePtr;
 double __date__;


public:

	Calendar(): basePtr(new T()) {}

	bool set_date(int year, int month, int day);

	/*
	 * Returns a boolean
	 *
	 * true - if successful
	 * false - otherwise
	 *
	 */
	bool add_event(std::string event);
	bool add_event(std::string event, int day);
	bool add_event(std::string event, int day, int month);
	bool add_event(std::string event, int day, int month, int year);


//	Calendar<T>& operator=(const Calendar<T>&);

	/*
	 * Returns a boolean
	 *
	 *	true - if successful
	 *	false - otherwise
	 *
	 */
	bool remove_event(std::string event);
	bool remove_event(std::string event, int day);
	bool remove_event(std::string event, int day, int month);
	bool remove_event(std::string event, int day, int month, int year);

};

//template<typename T>
//Calendar<T>& Calendar<T>::operator=(const Calendar<Date>& other) {
//	delete[] this->basePtr;
//	this->basePtr = other.basePtr;
//	return *this;
//}
//
//template<typename T>
//bool Calendar<T>::set_date( int year, int month, int day ) {
//	try {
//		T tmp(year, month, day);
//		__date__ = basePtr->calendar_to_jd(year, month, day );
//	}catch(std::exception& e) {
//		return false;
//	}
//	return true;
//}
//
//template<typename T>
//bool Calendar<T>::add_event( std::string event ) {
//	return false;
//}
//
//template<typename T>
//bool Calendar<T>::add_event( std::string event, int day ) {
//	return false;
//}
//
//template<typename T>
//bool Calendar<T>::add_event( std::string event, int day, int month ) {
//	return false;
//}
//
//template<typename T>
//bool Calendar<T>::add_event( std::string event, int day, int month, int year ) {
//	return false;
//}
//
//template<typename T>
//bool Calendar<T>::remove_event( std::string event ) {
//	return false;
//}
//
//template<typename T>
//bool Calendar<T>::remove_event( std::string event, int day ) {
//	return false;
//}
//
//template<typename T>
//bool Calendar<T>::remove_event( std::string event, int day, int month ) {
//	return false;
//}
//
//template<typename T>
//bool Calendar<T>::remove_event( std::string event, int day, int month, int year ){
//	return false;
//}

}

#endif /* CALENDAR_H_ */
