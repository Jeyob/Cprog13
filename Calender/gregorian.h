
#ifndef GREGORIAN_H_
#define GREGORIAN_H_
#include "Date.h"

using namespace std;

namespace lab2 {
#define DAYS_PER_WEEK 7
#define MONTH_PER_YEAR 12

class Gregorian: public Date {

public:

	Gregorian();

	Gregorian(int day);

	Gregorian(int month, int day);

	Gregorian(int year, int month, int day);

	Gregorian(const Date &);

	Date & operator=(const Date &);

	virtual ~Gregorian() {

	}
	virtual int year() const;
	virtual int month() const;
	virtual int day() const;
	virtual int days_this_month() const;
	virtual int days_per_week() const;
	virtual int months_per_year() const;
	virtual string week_day_name() const;
	virtual string month_name() const;
	virtual int week_day() const;
	virtual Date& add_year(int n = 1);
	virtual Date& add_month(int n = 1);

private:
	static const int ndays_in_month[12];
	static const int offset[4];
	static const string month_names[12];
	static const string week_days[7];
	time_t mytime;
	struct tm * t;

	void init();
	double gregorian_to_jd(int year, int month, int day) const;
	int leap_gregorian(int year) const;
};

}
#endif /* GREGORIAN_H_ */
