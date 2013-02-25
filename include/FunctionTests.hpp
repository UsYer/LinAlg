#ifndef FUNCTIONTESTS_HPP_INCLUDED
#define FUNCTIONTESTS_HPP_INCLUDED
#include "Functions.hpp"

TEST(VectorNorm1)
{
 LinAlg::Vector<int> v = {1, 2, 3};
 CHECK_CLOSE(3.7417, LinAlg::norm(v,2), 0.0001);
}
TEST(MatrixNorm1)
{
    LinAlg::Matrix m = {{1, 1},{2, 2},{3,3}};
    CHECK_EQUAL(6, LinAlg::norm(m,1));
}

TEST(MatrixNorm2)
{
    LinAlg::Matrix m = {{1, 1},{2, 2},{3,3}};
    CHECK_CLOSE(5.2915, LinAlg::norm(m,2), 0.0001);
}
TEST(MatrixNormInf)
{
    LinAlg::Matrix m = {{1, 1},{2, 2},{3,3}};
    CHECK_EQUAL(6, LinAlg::norm(m,Norm::inf));
}


#endif // FUNCTIONTESTS_HPP_INCLUDED
