#include <cxxtest/TestSuite.h>
#include "julian.h"
#include "kattistime.h"
#include <time.h>

using namespace lab2;



class TemplateTestSuite : public CxxTest::TestSuite
{

public: 

	void test_add_month() {

		Julian j1(2004,2,29);

		j1.add_month();
		TS_TRACE(j1.week_day());
		TS_TRACE(j1.week_day_name());
		TS_TRACE(j1.year());
		TS_TRACE(j1.month());
		TS_TRACE(j1.day());

	}

	void test_year() {

	}

	void test_month() {

	}

	void test_day() {

	}

	void test_Week_day() {

		Julian j(1993,2,28);
		TS_TRACE(j.week_day());
		TS_TRACE(j.week_day_name());
		TS_TRACE(j.year());
		TS_TRACE(j.month());
		TS_TRACE(j.day());
		TS_ASSERT_EQUALS(j.week_day(), 6);

	}

	void test_calendar_to_JD() {
		TS_TRACE("1992-07-18 TO JD");
		// TS_ASSERT_EQUALS(Julian_Test_Methods::calendar_to_jd(1989,7,18), 2447738.5);
	}

	void test_mod_julian_day() {

		// Julian l1(2004, 7, 18);
		// Julian l2(1984, 7, 18);
		// Julian l3(1980, 2, 29);

		// Julian j(1989,7,18);
		// Julian h(1990,11,11);
		// Julian ed(1995,4,30);
		// Julian w(1966,11,10);
		// Julian ey(1962,7,10);

		// TS_TRACE("Test Leap Year");
		// TS_ASSERT_EQUALS(l1.mod_julian_day(), 53217);

		// TS_TRACE("Test Leap Year");
		// TS_ASSERT_EQUALS(l2.mod_julian_day(), 45912);

		// TS_TRACE("Test Leap Year");
		// TS_ASSERT_EQUALS(l3.mod_julian_day(), 44311);


		// TS_TRACE("Test none Leap years");
		// TS_TRACE(j.mod_julian_day());
		// TS_ASSERT_EQUALS(j.mod_julian_day(), 47738);

		// TS_TRACE("Test none Leap years");
		// TS_TRACE(h.mod_julian_day());
		// TS_ASSERT_EQUALS(h.mod_julian_day(), 48219);

		// TS_TRACE("Test none Leap years");
		// TS_TRACE(ed.mod_julian_day());
		// TS_ASSERT_EQUALS(ed.mod_julian_day(), 49850);

		// TS_TRACE("Test none Leap years");
		// TS_TRACE(w.mod_julian_day());
		// TS_ASSERT_EQUALS(w.mod_julian_day(), 39452);
		
		// TS_TRACE("Test none Leap years");
		// TS_TRACE(ey.mod_julian_day());
		// TS_ASSERT_EQUALS(ey.mod_julian_day(), 37868);

	}

	void test_MJD() {

		// Gregorian j(1989,7,18);
		// Gregorian h(1990,11,11);
		// Gregorian ed(1995,4,30);
		// Gregorian w(1966,11,10);
		// Gregorian ey(1962,7,10);

		// TS_TRACE(j.mod_julian_day());
		// TS_ASSERT_EQUALS(j.mod_julian_day(), 47725);

		// TS_TRACE(h.mod_julian_day());
		// TS_ASSERT_EQUALS(h.mod_julian_day(), 48206);

		// TS_TRACE(ed.mod_julian_day());
		// TS_ASSERT_EQUALS(ed.mod_julian_day(), 49837);

		// TS_TRACE(w.mod_julian_day());
		// TS_ASSERT_EQUALS(w.mod_julian_day(), 39439);
		
		// TS_TRACE(ey.mod_julian_day());
		// TS_ASSERT_EQUALS(ey.mod_julian_day(), 37855);

	}

	// void testLeap_Year() {
	// 	time_t timer;
	// 	time(&timer);
	// 	set_k_time(timer);
	// 	Julian j;
	// 	TS_TRACE(j.isLeap(440));
	// }
};
