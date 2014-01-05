#ifndef CALENDAR_H_
#define CALENDAR_H_

#include <cstring>
#include "date.h"
#include <type_traits>
#include "kattistime.h"
#include <map>
#include <list>
#include <vector>

using namespace std;

namespace lab2 {

template<typename T> struct sEventColl {
	T _date;
	list<string> event_list;

	template<typename U>
	friend struct sEventColl;

	sEventColl(T d, const string& eventStr) :
			_date(d) {
		event_list.push_back(eventStr);
	}

	template<typename U>
	sEventColl(const sEventColl<U>& other) {
		_date = other._date;
		this->event_list.clear();
		for (typename list<string>::const_iterator it = other.event_list.cbegin();
				it != other.event_list.cend();
				it++) {
			event_list.push_back(*it);
		}
	}

	~sEventColl() {
	}

	bool operator<(const T & d) const {
		return (_date <  d );
	}

	bool operator>(const T & d) const {
		return ( _date > d );
	}

	bool operator==(const T & d) const {
		return _date==d;
	}
	bool operator<=(const T & d) const {
		return (operator ==(d) || operator <(d));
	}

	bool operator>=(const T & d) const {
		return (operator ==(d) || operator >(d));
	}

	bool removeEvent(string eventText) {

		for (typename list<string>::iterator it = event_list.begin();
				it != event_list.end(); it++) {
			if (*it == eventText) {
				event_list.erase(it);
				return true;
			}
		}
		return false;
	}

	bool addEvent(const string event) {

		/* Check if object already exist */
		for (typename list<string>::const_iterator it = event_list.begin();
				it != event_list.end(); it++) {
			if (event == *it)
				return false;
		}
		event_list.push_back(event);
		return true;
	}

	bool isEmpty() {
		return event_list.empty();
	}

	friend ostream& operator<<(ostream & os, const sEventColl & ecoll) {
		for (list<string>::const_iterator it = ecoll.event_list.cbegin();
				it != ecoll.event_list.cend(); it++) {
			os << ecoll._date << " : " << *it << endl;
		}
		return os;
	}
};

template<typename T> class Calendar {
	static_assert(is_base_of<lab2::Date,T>::value,"Class must be derived of Date");

private:
	T cur_date;
	vector<sEventColl<T>> e_list;
	template<typename U>
	friend class Calendar;

public:

	Calendar();

	template<typename U>
	Calendar(const Calendar<U> & other);

	~Calendar();

	bool set_date(int year, int month, int day);

	template<typename U>
	Calendar& operator=(const Calendar<U>&);

	bool add_event(string event);
	bool add_event(string event, int day);
	bool add_event(string event, int day, int month);
	bool add_event(string event, int day, int month, int year);

	bool remove_event(string event);
	bool remove_event(string event, int day);
	bool remove_event(string event, int day, int month);
	bool remove_event(string event, int day, int month, int year);


	friend ostream& operator<<(ostream & os, const Calendar& c){
		typename std::vector<sEventColl<T>>::const_iterator it = c.e_list.begin();

		for (; it!=c.e_list.end(); it++) {
			if( it->_date > c.cur_date)
				os << *it;
		}

		return os;
	}

};

template<typename T>
Calendar<T>::Calendar() {
	T tmp;
	cur_date = tmp;
}

template<typename T>
template<typename U>
Calendar<T>::Calendar(const Calendar<U> & other ) {
	operator =(other);
}
template<typename T>
Calendar<T>::~Calendar() {
}

template<typename T>
template<typename U>
Calendar<T>& Calendar<T>::operator=(const Calendar<U>& other) {
	this->cur_date = other.cur_date;

	typename vector<sEventColl<U>>::const_iterator it = other.e_list.cbegin();
	for(; it!=other.e_list.end(); it++ ){
		sEventColl<T> d(*it);
		e_list.push_back(d);
	}

	return *this;
}

template<typename T>
bool Calendar<T>::set_date(int year, int month, int day) {

	try {
		 T d(year, month, day);
		cur_date = d;
	} catch (exception& e) {
		return false;
	}
	return true;
}

template<typename T>
bool inline Calendar<T>::add_event(string event) {
	return add_event(event, cur_date.day(), cur_date.month(), cur_date.year());
}

template<typename T>
bool inline Calendar<T>::add_event(string event, int day) {
	return add_event(event, day, cur_date.month(), cur_date.year());
}

template<typename T>
bool inline Calendar<T>::add_event(string event, int day, int month) {
	return add_event(event, day, month, cur_date.year());
}

template<typename T>
bool inline Calendar<T>::add_event(string event, int day, int month, int year) {

	try {
		T d(year, month, day);
		typename vector<sEventColl<T>>::iterator it = e_list.begin();
		while ( it != e_list.end() && it->_date <= d) {
			if(it->_date == d) {
				return it->addEvent(event);
			}
			it++;
		}

		sEventColl<T> e(d,event);

		if (it!=e_list.end()) {
			e_list.insert(it, e);
		} else {
			e_list.push_back(e);
		}

		return true;

	} catch (exception& e) {
		return false;
	}
}

template<typename T>
bool inline Calendar<T>::remove_event(string event) {
	return remove_event(event, cur_date.day(), cur_date.month(),
			cur_date.year());
}

template<typename T>
bool inline Calendar<T>::remove_event(string event, int day) {
	return remove_event(event, day, cur_date.month(), cur_date.year());
}

template<typename T>
bool inline Calendar<T>::remove_event(string event, int day, int month) {
	return remove_event(event, day, month, cur_date.year());
}

template<typename T>
bool inline Calendar<T>::remove_event(string event, int day, int month,
		int year) {

	try {
		T d(year, month, day);
		typename vector<sEventColl<T>>::iterator it = e_list.begin();
		for(;it!= e_list.end(); it++) {
			if (*it == d) {
				bool isRemoved = it->removeEvent(event);
				if (isRemoved && it->isEmpty()) {
					e_list.erase(it);
				}
				return isRemoved;
			}
		}
		return false;
	} catch (exception& e) {
		return false;
	}
}



}

#endif /* CALENDAR_H_ */
