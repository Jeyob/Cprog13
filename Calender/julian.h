#ifndef JULIAN_H_
#define JULIAN_H_

#include "julian_gregorian_cal.h"

namespace lab2 {

class Julian: public julian_gregorian_interface {
public:
	friend class TemplateTestSuite;

	Julian();
	Julian(int day);
	Julian(int month, int day);
	Julian(int year, int month, int day);
	Julian(const Date &);
	virtual ~Julian() {

	}

	Date & operator=(const Date &);
	Date& operator++(int);
	Date& operator--(int);

	virtual int year() const;
	virtual int month() const;
	virtual int day() const;

private:
	double calendar_to_jd(int year, int month, int day) const;
	int isLeap(int year) const;
	int hej;
};}

#endif /* JULIAN_H_ */
