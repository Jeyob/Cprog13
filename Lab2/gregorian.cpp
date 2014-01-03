#include "gregorian.h"
#include "kattistime.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdexcept>
#include <stdlib.h>
#include <time.h>

using namespace std;

namespace lab2 {

Gregorian::Gregorian() {
	k_time(&mytime);
	t = gmtime(&mytime);
	setJDN(calendar_to_jd(t->tm_year + 1900, t->tm_mon + 1, t->tm_mday));
}

Gregorian::Gregorian(int day) {
	if (day < 0 || day > 31)
		throw std::out_of_range("Illegal day");
	k_time(&mytime);
	t = gmtime(&mytime);
	setJDN(calendar_to_jd(t->tm_year + 1900, t->tm_mon + 1, day));

}
Gregorian::Gregorian(int month, int day) {
	if (month <= 0 || month > MONTH_PER_YEAR || day > 31 || day <= 0)
		throw std::out_of_range("Illegal day or month number");
	k_time(&mytime);
	t = gmtime(&mytime);
	setJDN(calendar_to_jd(t->tm_year + 1900, month, day));
}

Gregorian::Gregorian(int year, int month, int day) {
	if (year <= 0 || month <= 0 || month > MONTH_PER_YEAR || day > 31
			|| day <= 0
			|| (ndays_in_month[month - 1] + (month == 2 && isLeap(year) ? 1 : 0))
					< day)
		throw std::out_of_range("Illegal");
	setJDN(calendar_to_jd(year, month, day));
}

Gregorian::Gregorian(const Date & d) {
	operator=(d);
}


Date& Gregorian::operator=(const Date & d) {
	getJDNref() = (d.mod_julian_day() + 2400000.5);
	return *this;
}


Gregorian& Gregorian::operator++(int){
		++(this->getJDNref());
		return *this;

	}
Gregorian& Gregorian::operator--(int){
		Gregorian old(*this);
		--(this->getJDNref());
		return *this;
}




int Gregorian::year() const {
	int z, w, x, a, b, c, d, e, m;
	z = getJDN() + 0.5;
	w = (z - 1867216.25) / 36524.25;
	x = w / 4;
	a = z + 1 + w - x;
	b = a + 1524;
	c = (b - 122.1) / 365.25;
	d = 365.25 * c;
	e = (b - d) / 30.6001;
	m = e - 1 <= 12 ? e - 1 : e - 13;
	return ((m == 1 || m == 2) ? c - 4715 : c - 4716);
}

int Gregorian::month() const {
	int z, w, x, a, b, c, d, e;
	z = getJDN() + 0.5;
	w = (z - 1867216.25) / 36524.25;
	x = w / 4;
	a = z + 1 + w - x;
	b = a + 1524;
	c = (b - 122.1) / 365.25;
	d = 365.25 * c;
	e = (b - d) / 30.6001;
	return ((e - 1) <= 12 ? e - 1 : e - 13);
}

int Gregorian::day() const {
	int z, w, x, a, b, c, d, e, f;
	z = getJDN() + 0.5;
	w = (z - 1867216.25) / 36524.25;
	x = w / 4;
	a = z + 1 + w - x;
	b = a + 1524;
	c = (b - 122.1) / 365.25;
	d = 365.25 * c;
	e = (b - d) / 30.6001;
	f = 30.6001 * e;
	return (b - d - f);

}

/* Algoritm från http://www.hermetic.ch/cal_stud/jdn.htm#comp */
double Gregorian::calendar_to_jd(int year, int month, int day) const {
	return (1721425.5 - 1) + (365 * (year - 1)) + floor((year - 1) / 4)
			+ (-floor((year - 1) / 100)) + floor((year - 1) / 400)
			+ floor(
					(((367 * month) - 362) / 12)
							+ ((month <= 2) ? 0 : (isLeap(year) ? -1 : -2))
							+ day);
}
int Gregorian::isLeap(int year) const {
	if (year < 0)
		throw std::out_of_range("illegal");
	return ((year % 4) == 0) && (!(((year % 100) == 0) && ((year % 400) != 0)));
}

}

