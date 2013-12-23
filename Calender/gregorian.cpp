#include "gregorian.h"
#include "kattistime.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdexcept>
#include <stdlib.h>

using namespace std;

namespace lab2 {

//Month numbers. February is depening on leap year either 28 or 29
const int Gregorian::ndays_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30,
		31, 30, 31 };

const int Gregorian::offset[4] = { 8, 6, 4, 2 }; //DOOMSDAYS
const string Gregorian::month_names[12] = { "january", "february", "march",
		"april", "may", "june", "july", "august", "september", "october",
		"november", "december" };

const string Gregorian::week_days[7] = { "monday", "tuesday", "wednesday",
		"thursday", "friday", "saturday", "sunday" };

Gregorian::Gregorian() {
	//time(&mytime);
	//set_k_time(mytime);
	k_time(&mytime);
	t = gmtime(&mytime);
	JDN = gregorian_to_jd(t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
}

Gregorian::Gregorian(int day) {
	if (day < 0 || day > 31)
		throw std::out_of_range("Illegal day");
	//time(&mytime);
	//set_k_time(mytime);
	k_time(&mytime);
	t = gmtime(&mytime);
	JDN = gregorian_to_jd(t->tm_year + 1900, t->tm_mon + 1, day);

}
Gregorian::Gregorian(int month, int day) {
	if (month <= 0 || month > MONTH_PER_YEAR || day > 31 || day <= 0)
		throw std::out_of_range("Illegal day or month number");
	//time(&mytime);
	//set_k_time(mytime);
	k_time(&mytime);
	t = gmtime(&mytime);
	JDN = gregorian_to_jd(t->tm_year + 1900, month, day);

}

Gregorian::Gregorian(int year, int month, int day) {
	if (year <= 0 || month <= 0 || month > MONTH_PER_YEAR || day > 31
			|| day <= 0
			|| (ndays_in_month[month - 1]
					+ (month == 2 && leap_gregorian(year) ? 1 : 0)) < day)
		throw std::out_of_range("Illegal");
	JDN = gregorian_to_jd(year, month, day);
}

Gregorian::Gregorian(const Date & d) {
	operator=(d);
}

Date& Gregorian::operator=(const Date & d) {

	JDN = d.get_julian_day_number();
	return *this;
}

int Gregorian::year() const {
	int z, w, x, a, b, c, d, e, m;
	z = JDN + 0.5;
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
	z = JDN + 0.5;
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
	z = JDN + 0.5;
	w = (z - 1867216.25) / 36524.25;
	x = w / 4;
	a = z + 1 + w - x;
	b = a + 1524;
	c = (b - 122.1) / 365.25;
	d = 365.25 * c;
	e = (b - d) / 30.6001;
	f = 30.6001 * e;
	return b - d - f;

}
int Gregorian::days_this_month() const {
	int m = (month() - 1);

	if (m == 1 && leap_gregorian(year())) {
		return 29;
	} else {
		return ndays_in_month[m];
	}
}

int Gregorian::days_per_week() const {
	return DAYS_PER_WEEK;
}
int Gregorian::months_per_year() const {
	return MONTH_PER_YEAR;
}
string Gregorian::week_day_name() const {
	return week_days[week_day() - 1];
}
string Gregorian::month_name() const {
	return month_names[month() - 1];
}

Date& Gregorian::add_year(int n) {
	int curr_year = year(), m = month(), d = day();
	bool isLeap = leap_gregorian(curr_year), nextLeap = leap_gregorian(
			curr_year + n);
	int _i = n < 0 ? -1 : 1;

	if (nextLeap && isLeap) // leap --> leap
		JDN += (static_cast<int>(gregorian_to_jd((curr_year + n), m, d) - JDN));
	else {
		for (int i = 1; i < abs(n) + 1; i++) {
			nextLeap = leap_gregorian(curr_year + (i * _i));
			isLeap = leap_gregorian(year());
			m = month();
			d = day();

			if (isLeap && m <= 2) // leap --> normal, where month<=2
					{
				if (m == 2) //April?
						{
					if (d > 28) {

						JDN += (_i < 0 ? 366 * _i : 365 * _i);
					} else {
						JDN += (_i < 0 ? 365 * _i : 366 * _i);
					}
				} else //januari
				{
					JDN += (_i < 0 ? 365 * _i : 366 * _i);
				}
			} else if ((m <= 2 && nextLeap) || (m > 2 && isLeap)) {
				JDN += (_i < 0 ? 366 * _i : 365 * _i);
			} else if (m > 2 && nextLeap) //leap-->normal eller normal --> leap where month>2
					{
				JDN += (_i < 0 ? 365 * _i : 366 * _i);
			} else {
				JDN += 365 * _i; // normal --> normal
			}
		}
	}
	return *this;
}

Date& Gregorian::add_month(int n) {

	int curr_month, monthOffset, ndays_nextMonth, _year, nextMonthOffset, ndays, today;
	int _i = n < 0 ? -1 : 1;
	curr_month = monthOffset = ndays_nextMonth = _year = nextMonthOffset = ndays = today = 0;

	for (int j = abs(n); j>0 ; j--){

		curr_month = month(); monthOffset = curr_month-1;_year = year();
		nextMonthOffset = monthOffset+_i;
		ndays = days_this_month();
		today = day();

		ndays_nextMonth =
				(((nextMonthOffset = (nextMonthOffset<0 ? 11:nextMonthOffset)) % 12) == 1 && leap_gregorian(_year) ?
						(ndays_in_month[(nextMonthOffset) % 12] + 1) :
						ndays_in_month[nextMonthOffset % 12]); //nästa månads dagantal
		if (day() <= ndays_nextMonth){
			if(_i<0) //dra av månad
				JDN -= ndays_nextMonth;
			else
				JDN+=ndays;
		}
		else
				JDN += 30*_i;
		}

	return *this;
}


int Gregorian::week_day() const {
	int _year = year(), _day = day(), _month = month();
	int offset[] = { 8, 6, 4, 2 };
	int _leap = leap_gregorian(_year);
	int doomsday[] = { 3 + _leap, 28 + _leap, 7, 4, 9, 6, 11, 8, 5, 10, 7, 12 };
	int twoLeastsig = _year % 100;
	int twoMostsig = floor(_year / 100);
	int refday = (offset[(twoMostsig % 4)] + twoLeastsig
			+ (int) floor(twoLeastsig / 4)) % 7;
	int d;

	if (_day < (d = doomsday[_month - 1]))
		return ((((7 - (d - _day) % 7) + refday) % 7) + 1);
	else
		return (((((_day - d) % 7) + refday) % 7) + 1);
}

//int Gregorian::week_day() const {
//	return static_cast<int>(JDN+1.5) % 7;
//}

/* Algoritm från http://www.hermetic.ch/cal_stud/jdn.htm#comp */
double Gregorian::gregorian_to_jd(int year, int month, int day) const {
	return (1721425.5 - 1) + (365 * (year - 1)) + floor((year - 1) / 4)
			+ (-floor((year - 1) / 100)) + floor((year - 1) / 400)
			+ floor(
					(((367 * month) - 362) / 12)
							+ ((month <= 2) ?
									0 : (leap_gregorian(year) ? -1 : -2)) + day);
}
int Gregorian::leap_gregorian(int year) const {
	if (year < 0)
		throw std::out_of_range("illegal");

	return ((year % 4) == 0) && ( !( ( (year % 100) == 0) && ( (year % 400) != 0) ) );
}

}

