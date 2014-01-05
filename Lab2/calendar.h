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

//struct sEvent {
//
//	string eventTxt;
//
//	sEvent() {
//	}
//
//	explicit sEvent(string eventTxt) :
//			eventTxt(eventTxt) {
//	}
//
//	sEvent(const sEvent& other) {
//		this->eventTxt = other.eventTxt;
//	}
//
//	template<typename U>
//	sEvent& operator=(const sEvent& other) {
//		this->eventTxt = other.eventTxt;
//		return *this;
//	}
//
//	bool operator==(const sEvent& other) const {
//		return (this->eventTxt == other.eventTxt);
//	}
//
//	friend ostream& operator<<(ostream & os, const sEvent e) {
//		os << e.eventTxt;
//		return os;
//	}
//};

template<typename T> struct sEventColl {
	T _date;
	list<string>  event_list;


	sEventColl(T d, const string& eventStr) :
			_date(d) {
		event_list.push_back(eventStr);
	}

	template<typename U>
	sEventColl(const sEventColl<U>& other) {
		_date = other.__d__;

		 this->event_list.clear();

		for (typename list<string>::const_iterator it =
				other.event_list.crbegin(); it != other.event_list.crend();
				it++) {
			event_list.push_back(*it);
		}
	}

	 ~sEventColl(){}

	bool operator<=(const T & d) const {
		return ((d == _date) || (_date < d));
	}

	bool operator>=(const T & d) const {
		return ((_date == d) || (_date > (d)));
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

template<typename T>
class Calendar;

template<typename T>
ostream& operator<<(ostream& out, const Calendar<T>& cal);

template<typename T> class Calendar {
	static_assert(is_base_of<lab2::Date,T>::value,"Class must be derived of Date");

private:
	T cur_date;
	vector<sEventColl<T>> e_list;

public:

	Calendar();
	~Calendar();

	bool set_date(int year, int month, int day);

	Calendar& operator=(const Calendar<Date>&);

	bool add_event(string event);
	bool add_event(string event, int day);
	bool add_event(string event, int day, int month);
	bool add_event(string event, int day, int month, int year);

	bool remove_event(string event);
	bool remove_event(string event, int day);
	bool remove_event(string event, int day, int month);
	bool remove_event(string event, int day, int month, int year);

};

template<typename T>
Calendar<T>::Calendar() {
	T tmp;
	cur_date = tmp;
}

template<typename T>
Calendar<T>::~Calendar() {
}

template<typename T>
Calendar<T>& Calendar<T>::operator=(const Calendar<Date>& other) {
	return *this;
}

template<typename T>
bool Calendar<T>::set_date(int year, int month, int day) {

	try {
		cur_date = new T(year, month, day);
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
bool inline Calendar<T>::add_event(string event, int day, int month,
		int year) {

	try {
		T d(year, month, day);
		typename vector<sEventColl<T>>::iterator it = e_list.begin();
		while (it != e_list.end() && (d > *it || d != *it)) {
			it++;
		}

		if (*it == d) {
			return it->addEvent(event);
		} else {
			e_list.insert(it, new sEventColl<T>(d, event));
			return true;
		}

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
		while ((it++) != e_list.end()) {
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
