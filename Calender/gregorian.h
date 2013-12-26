
#ifndef GREGORIAN_H_
#define GREGORIAN_H_
#include "julian_gregorian_cal.h"
using namespace std;

namespace lab2 {

class Gregorian: public julian_gregorian_interface  {

public:

	Gregorian();

	Gregorian(int day);

	Gregorian(int month, int day);

	Gregorian(int year, int month, int day);

	Gregorian(const Date &);

	Date & operator=(const Date &);

	Gregorian& operator++(int);
	Gregorian& operator--(int);

	virtual ~Gregorian() {

	}
	virtual int year() const;
	virtual int month() const;
	virtual int day() const;

private:
	int isLeap(int year) const;
	double calendar_to_jd(int year, int month, int day) const;
	friend class TemplateTestSuite; /* used for cxxtest */
};

}
#endif /* GREGORIAN_H_ */
