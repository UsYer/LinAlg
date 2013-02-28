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
    LinAlg::Matrix<int> m = {{1, 1},{2, 2},{3,3}};
    CHECK_EQUAL(6, LinAlg::norm(m,1));
}

TEST(MatrixNorm2)
{
    LinAlg::Matrix<int> m = {{1, 1},{2, 2},{3,3}};
    CHECK_CLOSE(5.2915, LinAlg::norm(m,2), 0.0001);
}
TEST(MatrixNormInf)
{
    LinAlg::Matrix<int> m = {{1, 1},{2, 2},{3,3}};
    CHECK_EQUAL(6, LinAlg::norm(m,LinAlg::Norm::inf));
}
TEST(MatrixTranspose)
{
    LinAlg::Matrix<int> m = {{1, 3, 5},{2, 4, 6}};
    auto m_t = LinAlg::transpose(m);
    CHECK_EQUAL(1, m_t[0]);
    CHECK_EQUAL(2, m_t[1]);
    CHECK_EQUAL(3, m_t[2]);
    CHECK_EQUAL(4, m_t[3]);
    CHECK_EQUAL(5, m_t[4]);
    CHECK_EQUAL(6, m_t[5]);
}
TEST(MaxVectorCol)
{
 LinAlg::Vector<int> v = {1, 3, 2};
 CHECK_EQUAL(3, LinAlg::max(v));
}
TEST(MaxVectorRow)
{
 LinAlg::Vector<int> v = {1, 3, 2};
 CHECK_EQUAL(3, LinAlg::max(v.transpose()));
}
TEST(SumVector)
{
 LinAlg::Vector<int> v = {1, 3, 2};
 CHECK_EQUAL(6, LinAlg::sum(v));
}
TEST(SumMatrix)
{
 LinAlg::Matrix<int> m = {{1, 3, 5},{2, 4, 6}};
 LinAlg::Vector<int> v = LinAlg::sum(m);
 CHECK_EQUAL(9, v[0]);
 CHECK_EQUAL(12, v[1]);
}
#endif // FUNCTIONTESTS_HPP_INCLUDED
