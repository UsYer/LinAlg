#include <iostream>
#include "include/Matrix.hpp"
#include "UnitTest++.h"
#include "include/MatrixTest.hpp"
#include "include/VectorTest.hpp"
#include "include/FunctionTests.hpp"
using namespace std;
// Implement range access to matrices and vectors
int main()
{
    LinAlg::Matrix<int> m = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    std::cout << m << "\n" << LinAlg::transpose(m) << "\n";
    LinAlg::Vector<int> v = {1, 2, 3, 4};
    std::cout << v << LinAlg::transpose(v) << "\n";
    return UnitTest::RunAllTests();
}
