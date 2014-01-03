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
	setJDN((mytime / 86400.0 ) + 2440587.5);
}

Julian::Julian(int day) {
	if (day < 0 || day > 31)
		throw std::out_of_range("Illegal day");
	k_time(&mytime);
	 setJDN((mytime / 86400.0 ) + 2440587.5);
	 setJDN(calendar_to_jd(year(),
					month(), day));
}

Julian::Julian(int month, int day) {
	if (month <= 0 || month > MONTH_PER_YEAR || day > 31 || day <= 0)
		throw std::out_of_range("Illegal day or month number");
	k_time(&mytime);
	setJDN((mytime / 86400.0 ) + 2440587.5);
	setJDN(calendar_to_jd(year(), month,
					day));
}

Julian::Julian(int year, int month, int day) {
	if (year <= 0 || month <= 0 || month > MONTH_PER_YEAR || day > 31
			|| day <= 0
			|| (ndays_in_month[month - 1] + (month == 2 && isLeap(year) ? 1 : 0))
					< day)
		throw std::out_of_range("Illegal");
	setJDN(calendar_to_jd(year, month, day));
}

Julian::Julian(const Date & d) {
	operator=(d);
}

int Julian::year() const {
		double tmp_JDN = JDN;
		tmp_JDN+=0.5;
	    int z = floor(tmp_JDN);

	    int a = z;
	    int b = a + 1524;
	    int c = floor((b - 122.1) / 365.25);
	    int d = floor(365.25 * c);
	    int e = floor((b - d) / 30.6001);

	    int month = floor((e < 14) ? (e - 1) : (e - 13));
	    int year = floor((month > 2) ? (c - 4716) : (c - 4715));

	    return year;
}

int Julian::month() const {

	double tmp_JDN = JDN;
	tmp_JDN+=0.5;
    int z = floor(tmp_JDN);

    int a = z;
    int b = a + 1524;
    int c = floor((b - 122.1) / 365.25);
    int d = floor(365.25 * c);
    int e = floor((b - d) / 30.6001);

    int month = floor((e < 14) ? (e - 1) : (e - 13));

    return month;
}

int Julian::day() const {
	double tmp_JDN = JDN;
	tmp_JDN+=0.5;
    int z = floor(tmp_JDN);

    int a = z;
    int b = a + 1524;
    int c = floor((b - 122.1) / 365.25);
    int d = floor(365.25 * c);
    int e = floor((b - d) / 30.6001);

    int day = b - d - floor(30.6001 * e);

    return day;
}

/* Returns the weekday
 *
 * 0: Monday 1:Tuesday etc..
 *
 */
int Julian::week_day() const {
	int reminder;
	return (reminder = (int)(JDN + 1.5) % 7) == 0 ? 7 :reminder ;
}

Julian& Julian::operator=(const Date & d) {
	getJDNref() = (d.mod_julian_day() + 2400000.5);
	return *this;
}

Julian& Julian::operator++(int) {
	++(this->getJDNref());
	return *this;

}
Julian& Julian::operator--(int) {
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

