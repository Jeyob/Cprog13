/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    status = CxxTest::Main<CxxTest::ErrorPrinter>( tmp, argc, argv );
    return status;
}
bool suite_TemplateTestSuite_init = false;
#include "testSuite_Julian.cpp"

static TemplateTestSuite suite_TemplateTestSuite;

static CxxTest::List Tests_TemplateTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TemplateTestSuite( "testSuite_Julian.cpp", 10, "TemplateTestSuite", suite_TemplateTestSuite, Tests_TemplateTestSuite );

static class TestDescription_suite_TemplateTestSuite_test_add_month : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_test_add_month() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 15, "test_add_month" ) {}
 void runTest() { suite_TemplateTestSuite.test_add_month(); }
} testDescription_suite_TemplateTestSuite_test_add_month;

static class TestDescription_suite_TemplateTestSuite_test_year : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_test_year() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 28, "test_year" ) {}
 void runTest() { suite_TemplateTestSuite.test_year(); }
} testDescription_suite_TemplateTestSuite_test_year;

static class TestDescription_suite_TemplateTestSuite_test_month : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_test_month() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 32, "test_month" ) {}
 void runTest() { suite_TemplateTestSuite.test_month(); }
} testDescription_suite_TemplateTestSuite_test_month;

static class TestDescription_suite_TemplateTestSuite_test_day : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_test_day() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 36, "test_day" ) {}
 void runTest() { suite_TemplateTestSuite.test_day(); }
} testDescription_suite_TemplateTestSuite_test_day;

static class TestDescription_suite_TemplateTestSuite_test_Week_day : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_test_Week_day() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 40, "test_Week_day" ) {}
 void runTest() { suite_TemplateTestSuite.test_Week_day(); }
} testDescription_suite_TemplateTestSuite_test_Week_day;

static class TestDescription_suite_TemplateTestSuite_test_calendar_to_JD : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_test_calendar_to_JD() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 52, "test_calendar_to_JD" ) {}
 void runTest() { suite_TemplateTestSuite.test_calendar_to_JD(); }
} testDescription_suite_TemplateTestSuite_test_calendar_to_JD;

static class TestDescription_suite_TemplateTestSuite_test_mod_julian_day : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_test_mod_julian_day() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 57, "test_mod_julian_day" ) {}
 void runTest() { suite_TemplateTestSuite.test_mod_julian_day(); }
} testDescription_suite_TemplateTestSuite_test_mod_julian_day;

static class TestDescription_suite_TemplateTestSuite_test_MJD : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_test_MJD() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 101, "test_MJD" ) {}
 void runTest() { suite_TemplateTestSuite.test_MJD(); }
} testDescription_suite_TemplateTestSuite_test_MJD;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
