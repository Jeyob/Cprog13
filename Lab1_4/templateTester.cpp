/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
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
#include "testSuite.cpp"

static TemplateTestSuite suite_TemplateTestSuite;

static CxxTest::List Tests_TemplateTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TemplateTestSuite( "testSuite.cpp", 20, "TemplateTestSuite", suite_TemplateTestSuite, Tests_TemplateTestSuite );

static class TestDescription_suite_TemplateTestSuite_testCopying : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_testCopying() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 25, "testCopying" ) {}
 void runTest() { suite_TemplateTestSuite.testCopying(); }
} testDescription_suite_TemplateTestSuite_testCopying;

static class TestDescription_suite_TemplateTestSuite_testErase : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_testErase() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 53, "testErase" ) {}
 void runTest() { suite_TemplateTestSuite.testErase(); }
} testDescription_suite_TemplateTestSuite_testErase;

static class TestDescription_suite_TemplateTestSuite_testErase2Args : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_testErase2Args() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 99, "testErase2Args" ) {}
 void runTest() { suite_TemplateTestSuite.testErase2Args(); }
} testDescription_suite_TemplateTestSuite_testErase2Args;

static class TestDescription_suite_TemplateTestSuite_testPush_back : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_testPush_back() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 153, "testPush_back" ) {}
 void runTest() { suite_TemplateTestSuite.testPush_back(); }
} testDescription_suite_TemplateTestSuite_testPush_back;

static class TestDescription_suite_TemplateTestSuite_testDefaultValueConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_testDefaultValueConstructor() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 182, "testDefaultValueConstructor" ) {}
 void runTest() { suite_TemplateTestSuite.testDefaultValueConstructor(); }
} testDescription_suite_TemplateTestSuite_testDefaultValueConstructor;

static class TestDescription_suite_TemplateTestSuite_testMoveConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_testMoveConstructor() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 192, "testMoveConstructor" ) {}
 void runTest() { suite_TemplateTestSuite.testMoveConstructor(); }
} testDescription_suite_TemplateTestSuite_testMoveConstructor;

static class TestDescription_suite_TemplateTestSuite_testMoveAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_testMoveAssignment() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 212, "testMoveAssignment" ) {}
 void runTest() { suite_TemplateTestSuite.testMoveAssignment(); }
} testDescription_suite_TemplateTestSuite_testMoveAssignment;

static class TestDescription_suite_TemplateTestSuite_testInitConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_testInitConstructor() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 232, "testInitConstructor" ) {}
 void runTest() { suite_TemplateTestSuite.testInitConstructor(); }
} testDescription_suite_TemplateTestSuite_testInitConstructor;

static class TestDescription_suite_TemplateTestSuite_testInsert : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_testInsert() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 245, "testInsert" ) {}
 void runTest() { suite_TemplateTestSuite.testInsert(); }
} testDescription_suite_TemplateTestSuite_testInsert;

static class TestDescription_suite_TemplateTestSuite_testClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_testClear() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 288, "testClear" ) {}
 void runTest() { suite_TemplateTestSuite.testClear(); }
} testDescription_suite_TemplateTestSuite_testClear;

static class TestDescription_suite_TemplateTestSuite_testExists : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_testExists() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 306, "testExists" ) {}
 void runTest() { suite_TemplateTestSuite.testExists(); }
} testDescription_suite_TemplateTestSuite_testExists;

static class TestDescription_suite_TemplateTestSuite_testSort : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_testSort() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 343, "testSort" ) {}
 void runTest() { suite_TemplateTestSuite.testSort(); }
} testDescription_suite_TemplateTestSuite_testSort;

static class TestDescription_suite_TemplateTestSuite_testShiftRight : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_testShiftRight() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 372, "testShiftRight" ) {}
 void runTest() { suite_TemplateTestSuite.testShiftRight(); }
} testDescription_suite_TemplateTestSuite_testShiftRight;

static class TestDescription_suite_TemplateTestSuite_testShiftLeft : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_testShiftLeft() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 403, "testShiftLeft" ) {}
 void runTest() { suite_TemplateTestSuite.testShiftLeft(); }
} testDescription_suite_TemplateTestSuite_testShiftLeft;

static class TestDescription_suite_TemplateTestSuite_testUnique_sort : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_testUnique_sort() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 432, "testUnique_sort" ) {}
 void runTest() { suite_TemplateTestSuite.testUnique_sort(); }
} testDescription_suite_TemplateTestSuite_testUnique_sort;

static class TestDescription_suite_TemplateTestSuite_testUnique_sort_Big : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_testUnique_sort_Big() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 489, "testUnique_sort_Big" ) {}
 void runTest() { suite_TemplateTestSuite.testUnique_sort_Big(); }
} testDescription_suite_TemplateTestSuite_testUnique_sort_Big;

static class TestDescription_suite_TemplateTestSuite_testUnique_sort_small : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_testUnique_sort_small() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 498, "testUnique_sort_small" ) {}
 void runTest() { suite_TemplateTestSuite.testUnique_sort_small(); }
} testDescription_suite_TemplateTestSuite_testUnique_sort_small;

static class TestDescription_suite_TemplateTestSuite_testUnique_sort_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_testUnique_sort_empty() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 521, "testUnique_sort_empty" ) {}
 void runTest() { suite_TemplateTestSuite.testUnique_sort_empty(); }
} testDescription_suite_TemplateTestSuite_testUnique_sort_empty;

static class TestDescription_suite_TemplateTestSuite_testProblematic : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TemplateTestSuite_testProblematic() : CxxTest::RealTestDescription( Tests_TemplateTestSuite, suiteDescription_TemplateTestSuite, 528, "testProblematic" ) {}
 void runTest() { suite_TemplateTestSuite.testProblematic(); }
} testDescription_suite_TemplateTestSuite_testProblematic;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
