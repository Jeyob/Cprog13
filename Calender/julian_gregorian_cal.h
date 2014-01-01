
#ifndef ABSTRACT_JULIAN_GREGORIAN_CAL_H_
#define ABSTRACT_JULIAN_GREGORIAN_CAL_H_

#include "date.h"
#include <iostream>
#include <math.h>
#include <stdio.h>

namespace lab2 {

#define DAYS_PER_WEEK 7
#define MONTH_PER_YEAR 12

class julian_gregorian_interface: public Date {

public:

	int days_per_week() const;
	int months_per_year() const;
	int days_this_month() const;
	virtual int week_day() const;

	Date& add_year(int n = 1);
	Date& add_month(int n = 1);

	string week_day_name() const;
	string month_name() const;

	virtual int year() const = 0;
	virtual int month() const = 0;
	virtual int day() const= 0;
	void printJDN(){
		printf("%6.1f\n",JDN);
	}



  virtual double calendar_to_jd(int year, int month, int day) const = 0;

protected:
	static const int ndays_in_month[12];
	static const int offset[4];
	static const string month_names[12];
	static const string week_days[7];
	time_t mytime;
	struct tm * t;

	virtual int isLeap(int year) const = 0; //Gregorian and Julian differs in how leap years are caculated


	void setJDN(double val){
		JDN = val;
	}
	void addJDN(double val) {
		JDN += val;
	}
	double getJDN() const {
		return JDN;
	}
	double & getJDNref() {
		return JDN;
	}

	int diff_julian__to_gregorian();

};

}

#endif /* ABSTRACT_JULIAN_GREGORIAN_CAL_H_ */
