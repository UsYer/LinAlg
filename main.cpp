#include <iostream>
#include "include/Matrix.hpp"
#include "UnitTest++.h"
#include "include/MatrixTest.hpp"
#include "include/VectorTest.hpp"
using namespace std;
// Implement range access to matrices and vectors
int main()
{
    LinAlg::Matrix<double> m;
    return UnitTest::RunAllTests();
}
