#ifndef DATE_H_
#define DATE_H_

#include <string>
#include <math.h>
#include <iostream>

using namespace std;

namespace lab2 {
class Date {

public:
	friend class Calendar;
	friend ostream& operator<<(ostream& os, const Date& d);

	/* Getters - readonly therefore "const" */
	virtual int year() const = 0;
	virtual int month() const = 0;
	virtual int day() const = 0;
	virtual int days_per_week() const = 0;
	virtual int days_this_month() const = 0;
	virtual int months_per_year() const = 0;
	virtual std::string week_day_name() const = 0;
	virtual std::string month_name() const = 0;
	virtual int week_day() const = 0;

	/* Setters - not decleared const since we can't change state */
	virtual Date& add_year(int n = 1) = 0; //Kräver att vi vet hur lång år&månad är.
	virtual Date& add_month(int n = 1) = 0;

	Date() {
	}
	explicit Date(double _JDN) :
			JDN(_JDN) {
	}
	Date(const Date & d) :
			JDN((d.mod_julian_day() + 2400000.5)) {
	}

	virtual ~Date() {}

	/* Operators */

	void operator=(const Date & d) {
		JDN = (d.mod_julian_day()+2400000.5);
	}

	Date& operator++() {
		++JDN;
		return *this;
	}

	Date& operator--() {
		--JDN;
		return *this;
	}

	virtual bool operator<(const Date & d) const {
		return mod_julian_day() < d.mod_julian_day();
	}
	virtual bool operator>(const Date& d) const {
		return mod_julian_day() > d.mod_julian_day();
	}
	virtual bool operator==(const Date & d) const {
		return mod_julian_day() == d.mod_julian_day();
	}
	virtual int operator-(const Date & d) const {
		return mod_julian_day() - d.mod_julian_day();
	}

	virtual bool operator!=(const Date & d) const {
		return !operator==(d);
	}

	virtual bool operator<=(const Date & d) const {
		return (operator==(d) || operator<(d));
	}

	virtual bool operator>=(const Date & d) const {
		return (operator==(d) || operator>(d));
	}

	virtual Date& operator+=(int i) {
		JDN+=i;
		return *this;
	}

	virtual Date& operator-=(int i) {
		JDN-=i;
		return *this;
	}

	int mod_julian_day() const {
		return (JDN - 2400000.5f);
	}

protected:

	double JDN; //julian day number
	virtual double calendar_to_jd(int year, int month, int day) const = 0;

};

}
#endif /* DATE_H_ */

