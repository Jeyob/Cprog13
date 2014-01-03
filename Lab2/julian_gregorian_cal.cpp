#include "julian_gregorian_cal.h"
#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <stdexcept>

using namespace std;
namespace lab2 {

const int julian_gregorian_interface::ndays_in_month[12] = { 31, 28, 31, 30, 31,
		30, 31, 31, 30, 31, 30, 31 };
const int julian_gregorian_interface::offset[4] = { 8, 6, 4, 2 }; //DOOMSDAYS
const string julian_gregorian_interface::month_names[12] = { "january",
		"february", "march", "april", "may", "june", "july", "august",
		"september", "october", "november", "december" };

const string julian_gregorian_interface::week_days[7] = { "monday", "tuesday",
		"wednesday", "thursday", "friday", "saturday", "sunday" };

int julian_gregorian_interface::days_this_month() const {
	int m = (month() - 1);

	if (m == 1 && isLeap(year())) {
		return 29;
	} else {
		return ndays_in_month[m];
	}
}

int julian_gregorian_interface::days_per_week() const {
	return DAYS_PER_WEEK;
}
int julian_gregorian_interface::months_per_year() const {
	return MONTH_PER_YEAR;
}
string julian_gregorian_interface::week_day_name() const {
	return week_days[week_day() - 1];
}
string julian_gregorian_interface::month_name() const {
	return month_names[month() - 1];
}

Date& julian_gregorian_interface::add_year(int n) {
	int curr_year = year(), m = month(), d = day();
	bool _isLeap = isLeap(curr_year), nextLeap = isLeap(curr_year + n);
	int _i = n < 0 ? -1 : 1;

	if ( (nextLeap && _isLeap) || (!nextLeap && !_isLeap) || ( nextLeap && !_isLeap ) ) // leap --> leap
		JDN += (static_cast<double>(calendar_to_jd((curr_year + n), m, d) - JDN));

	else {
		for ( int i = 1; i < abs(n) + 1; i++ ) {
			nextLeap = isLeap(curr_year + (i * _i));
			_isLeap = isLeap(year());
			m = month();
			d = day();

			if (_isLeap && m <= 2) // leap --> normal, where month<=2
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
			} else if ((m <= 2 && nextLeap) || (m > 2 && _isLeap)) {
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

Date& julian_gregorian_interface::add_month(int n) {

	int curr_month, monthOffset, ndays_nextMonth, _year, nextMonthOffset, ndays,
			today;
	int _i = n < 0 ? -1 : 1;
	curr_month = monthOffset = ndays_nextMonth = _year = nextMonthOffset =
			ndays = today = 0;

	for (int j = abs(n); j > 0; j--) {

		curr_month = month();
		monthOffset = curr_month - 1;
		_year = year();
		nextMonthOffset = monthOffset + _i;
		ndays = days_this_month();
		today = day();

		ndays_nextMonth =
				(((nextMonthOffset =
						(nextMonthOffset < 0 ? 11 : nextMonthOffset)) % 12) == 1
						&& isLeap(_year) ?
						(ndays_in_month[(nextMonthOffset) % 12] + 1) :
						ndays_in_month[nextMonthOffset % 12]); //nästa månads dagantal
		if (day() <= ndays_nextMonth) {
			if (_i < 0) //dra av månad
				JDN -= ndays_nextMonth;
			else
				JDN += ndays;
		} else
			JDN += 30 * _i;
	}

	return *this;
}

int julian_gregorian_interface::week_day() const {
	int _year = year(), _day = day(), _month = month();
	int offset[] = { 8, 6, 4, 2 };
	int _leap = isLeap(_year);
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

int julian_gregorian_interface::diff_julian__to_gregorian(){
	int mjd = mod_julian_day();
	if(mjd>=-21434 && mjd<=15090)
		return 12;
	else if(mjd>=15091 && mjd<=88140)
		return 13;
	else if(mjd>=88141 && mjd<=124665)
		return 14;
	else if(mjd>=124666 && mjd<=161190)
		return 15;
	else if(mjd>=161191 && mjd<=197715)
		return 16;
	else if(mjd>=161192 && mjd<=270765)
		return 17;
	else
		throw out_of_range("har bara stöd för datum upp till 2600");
}

}
