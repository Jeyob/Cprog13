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

	Julian& operator=(const Date &);
	Julian& operator++(int);
	Julian& operator--(int);

	virtual int year() const;
	virtual int month() const;
	virtual int day() const;
	int week_day() const;

private:
	double calendar_to_jd(int year, int month, int day) const;
	int isLeap(int year) const;
};}

#endif /* JULIAN_H_ */
