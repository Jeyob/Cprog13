#include <cxxtest/TestSuite.h>
#include "gregorian.h"
#include "kattistime.h"
#include <time.h>

using namespace lab2;

class TemplateTestSuite : public CxxTest::TestSuite
{

public: 

	void test_year() {

	}

	void test_month() {

	}

	void test_day() {

	}

	void test_calendar_to_jd() {


	}

	void test_MJD() {

		Gregorian j(1989,7,18);
		Gregorian h(1990,11,11);
		Gregorian ed(1995,4,30);
		Gregorian w(1966,11,10);
		Gregorian ey(1962,7,10);

		TS_TRACE(j.mod_julian_day());
		TS_ASSERT_EQUALS(j.mod_julian_day(), 47725);

		TS_TRACE(h.mod_julian_day());
		TS_ASSERT_EQUALS(h.mod_julian_day(), 48206);

		TS_TRACE(ed.mod_julian_day());
		TS_ASSERT_EQUALS(ed.mod_julian_day(), 49837);

		TS_TRACE(w.mod_julian_day());
		TS_ASSERT_EQUALS(w.mod_julian_day(), 39439);
		
		TS_TRACE(ey.mod_julian_day());
		TS_ASSERT_EQUALS(ey.mod_julian_day(), 37855);

	}

	void testLeap_Year() {
		time_t timer;
		time(&timer);
		set_k_time(timer);
		Gregorian g;
		TS_TRACE(g.isLeap(440));
	}
};
