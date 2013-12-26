#include "julian.h"
#include "kattistime.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdexcept>
#include <stdlib.h>
#include <time.h>

namespace lab2 {

Julian::Julian() {
	k_time(&mytime);
	t = gmtime(&mytime);
	setJDN(
			julian_gregorian_interface::calendar_to_jd(t->tm_year + 1900,
					t->tm_mon + 1, t->tm_mday));
}

Julian::Julian(int day) {
	if (day < 0 || day > 31)
		throw std::out_of_range("Illegal day");
	k_time(&mytime);
	t = gmtime(&mytime);
	setJDN(
			julian_gregorian_interface::calendar_to_jd(t->tm_year + 1900,
					t->tm_mon + 1, day));
}

Julian::Julian(int month, int day) {
	if (month <= 0 || month > MONTH_PER_YEAR || day > 31 || day <= 0)
		throw std::out_of_range("Illegal day or month number");
	k_time(&mytime);
	t = gmtime(&mytime);
	setJDN(
			julian_gregorian_interface::calendar_to_jd(t->tm_year + 1900, month,
					day));
}

Julian::Julian(int year, int month, int day) {
	if (year <= 0 || month <= 0 || month > MONTH_PER_YEAR || day > 31
			|| day <= 0
			|| (ndays_in_month[month - 1] + (month == 2 && isLeap(year) ? 1 : 0))
					< day)
		throw std::out_of_range("Illegal");
	setJDN(julian_gregorian_interface::calendar_to_jd(year, month, day));
}

Julian::Julian(const Date & d) {
	operator=(d);
}

int Julian::year() const {
	return 0;
}

int Julian::month() const {
	return 0;
}

int Julian::day() const {
	return 0;
}

Date& Julian::operator=(const Date & d) {
	getJDNref() = (d.mod_julian_day() + 2400000.5);
	return *this;
}

Date& Julian::operator++(int) {
	++(this->getJDNref());
	return *this;

}
Date& Julian::operator--(int) {
	--(this->getJDNref());
	return *this;
}

int Julian::isLeap(int year) const {
	return (year % 4 == 0);
}

double Julian::calendar_to_jd(int year, int month, int day) const {
	/* algorithm used from: http://en.wikipedia.org/wiki/Julian_day */

	if (month <= 2) {
		year--;
		month += 12;
	}

	return ((floor(365.25 * (year + 4716)))
			+ floor((30.6001 * (month + 1)) + day) - 1524.5);
}

}

