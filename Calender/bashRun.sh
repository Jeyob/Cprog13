#!/bin/bash
 echo "Generating testfile..."
 cxxtestgen --error-printer -o templateTester.cpp testSuite_Julian.cpp
 echo ""
 echo "Testfile generation done!"
 echo ""
 echo "Compiling testfile..."
 g++ -g -O2 -static -std=gnu++0x -o templateTester.out -I ./cxxtest/ templateTester.cpp julian.h julian.cpp julian_gregorian_cal.h julian_gregorian_cal.cpp kattistime.h kattistime.cpp
 echo ""
 echo "Compilation done!"
 echo
 echo "Running tests.."
 ./templateTester.out -v
