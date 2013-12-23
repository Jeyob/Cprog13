
#ifndef DATE_H_
#define DATE_H_


#include <string>
#include <math.h>
#include <iostream>

using namespace std;
namespace lab2 {
class Date {

public:

	friend ostream& operator<<(ostream& os, const Date& d);

	/* Getters - readonly therefore "const" */
	virtual int year() const = 0;
	virtual int month() const = 0; //First month respresented by 1
	virtual int day() const = 0; // First day represented by 1
	virtual int days_per_week() const = 0;
	virtual int days_this_month() const = 0;
	virtual int months_per_year() const = 0;
	virtual std::string week_day_name() const = 0;
	virtual std::string month_name() const = 0;
	virtual int week_day() const = 0; //monday = 1

	/* #### Setters ##### */
	virtual Date& add_year(int n = 1) = 0;
	virtual Date& add_month(int n = 1) = 0;
	/* #### End setters #### */
	Date() {
	}
	Date(double _JDN) :
		JDN(_JDN) {
	}
	virtual ~Date() = default;

	Date(const Date & d):JDN(d.get_julian_day_number()){}

	void operator=(const Date & d) {
		JDN = d.get_julian_day_number();
	}

	/* ###### Operators ###### */

	Date& operator++() {
		JDN += 1;
		return *this;
	}
	Date& operator--() {
		JDN -= 1;
		return *this;
	}
	Date& operator+=(int n) {
		JDN += n;
		return *this;
	}
	Date& operator-=(int n) {
		JDN -= n;
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

	/* ##### End Operators ####### */

	int mod_julian_day() const {
		return JDN - 2400000.5;
	}

	double get_julian_day_number() const
	{
		return JDN;
	}

protected:
	double JDN; //julian day number

};


}
#endif /* DATE_H_ */

