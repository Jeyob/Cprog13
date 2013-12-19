# #!/bin/bash

# echo "Generating testfile..."
# cxxtestgen --error-printer -o templateTester.cpp testSuite.cpp
# echo ""
# echo "Testfile generation done!"
# echo ""
# echo "Compiling testfile..."
# g++ -g -O2 -static -std=gnu++0x -o templateTester.out -I ./cxxtest/ templateTester.cpp vector.h Problematic.cpp
# echo ""
# echo "Compilation done!"
# echo
# echo "Running tests.."
# ./templateTester.out -v
