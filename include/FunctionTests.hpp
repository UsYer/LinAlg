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
    LinAlg::Matrix<int> m = {{1, 1},{-5, 2},{3,3}};
    CHECK_EQUAL(7, LinAlg::norm(m,1));
}

TEST(MatrixNorm2)
{
    LinAlg::Matrix<int> m = {{1, 1},{2, 2},{3,3}};
    CHECK_CLOSE(5.2915, LinAlg::norm(m,2), 0.0001);
}
TEST(MatrixNormInf)
{
    LinAlg::Matrix<int> m = {{1, 1},{-5, 2},{3,3}};
    CHECK_EQUAL(9, LinAlg::norm(m,LinAlg::Norm::inf));
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
TEST(MaxMatrix)
{
 LinAlg::Matrix<int> m = {{1, 3, 5},{2, 4, 6}};
 LinAlg::Vector<int> v = LinAlg::max(m);
 CHECK_EQUAL(2u, v.size());
 CHECK_EQUAL(5, v[0]);
 CHECK_EQUAL(6, v[1]);
}
TEST(MinVectorCol)
{
 LinAlg::Vector<int> v = {1, 3, 2};
 CHECK_EQUAL(1, LinAlg::min(v));
}
TEST(MinVectorRow)
{
 LinAlg::Vector<int> v = {1, 3, 2};
 CHECK_EQUAL(1, LinAlg::min(v.transpose()));
}
TEST(MinMatrix)
{
 LinAlg::Matrix<int> m = {{1, 3, 5},{2, 4, 6}};
 LinAlg::Vector<int> v = LinAlg::min(m);
 CHECK_EQUAL(2u, v.size());
 CHECK_EQUAL(1, v[0]);
 CHECK_EQUAL(2, v[1]);
}
TEST(MinIndexVector)
{
    //[ignore, i] = min(distances);
    LinAlg::Vector<int> v = {3, 1, 2};
    auto pos_it = v.end();
    auto res = LinAlg::min(v,pos_it);
    CHECK_EQUAL(1, res);
    CHECK_EQUAL(1, *pos_it);
}
TEST(RoundVectorCol)
{
 LinAlg::Vector<double> v = {-1.5, 3.9, 1.1};
 LinAlg::Vector<double> v_round = {-2,4,1};
 CHECK_EQUAL(v_round, LinAlg::round(v));
}
TEST(RoundVectorRow)
{
 LinAlg::Vector<double> v = {-1.5, 3.9, 1.1};
 LinAlg::Vector<double> v_round = {-2,4,1};
 CHECK_EQUAL(v_round.transpose(), LinAlg::round(v.transpose()));
}
TEST(RoundMatrix)
{
 LinAlg::Matrix<double> m = {{-1.5, 3.9, 1.1},{-1.5, 3.9, 1.1}};
 LinAlg::Matrix<double> m_round = LinAlg::round(m);
 CHECK_EQUAL(-2, m_round[0]);
 CHECK_EQUAL(4, m_round[1]);
 CHECK_EQUAL(1, m_round[2]);
 CHECK_EQUAL(-2, m_round[3]);
 CHECK_EQUAL(4, m_round[4]);
 CHECK_EQUAL(1, m_round[5]);
}
TEST(FixVectorCol)
{
 LinAlg::Vector<double> v = {-1.5, 3.9, 1.1};
 LinAlg::Vector<double> v_fix = {-1,3,1};
 CHECK_EQUAL(v_fix, LinAlg::fix(v));
}
TEST(FixVectorRow)
{
 LinAlg::Vector<double> v = {-1.5, 3.9, 1.1};
 LinAlg::Vector<double> v_fix = {-1,3,1};
 CHECK_EQUAL(v_fix.transpose(), LinAlg::fix(v.transpose()));
}
TEST(FixMatrix)
{
 LinAlg::Matrix<double> m = {{-1.5, 3.9, 1.1},{-1.5, 3.9, 1.1}};
 LinAlg::Matrix<double> m_fix = LinAlg::fix(m);
 CHECK_EQUAL(-1, m_fix[0]);
 CHECK_EQUAL(3, m_fix[1]);
 CHECK_EQUAL(1, m_fix[2]);
 CHECK_EQUAL(-1, m_fix[3]);
 CHECK_EQUAL(3, m_fix[4]);
 CHECK_EQUAL(1, m_fix[5]);
}
TEST(AbsVectorCol)
{
 LinAlg::Vector<int> v = {-1, -3, -2};
 LinAlg::Vector<int> v_abs = LinAlg::abs(v);
 CHECK_EQUAL(1, v_abs[0]);
 CHECK_EQUAL(3, v_abs[1]);
 CHECK_EQUAL(2, v_abs[2]);
}
TEST(AbsVectorRow)
{
 LinAlg::Vector<int> v = {-1, -3, -2};
 LinAlg::Vector<int> v_abs = LinAlg::abs(v.transpose());
 CHECK_EQUAL(1, v_abs[0]);
 CHECK_EQUAL(3, v_abs[1]);
 CHECK_EQUAL(2, v_abs[2]);
}
TEST(AbsMatrix)
{
 LinAlg::Matrix<int> m = {{1, 3, -5},{2, -4, 6}};
 LinAlg::Matrix<int> m_abs = LinAlg::abs(m);
 CHECK_EQUAL(1, m_abs[0]);
 CHECK_EQUAL(3, m_abs[1]);
 CHECK_EQUAL(5, m_abs[2]);
 CHECK_EQUAL(2, m_abs[3]);
 CHECK_EQUAL(4, m_abs[4]);
 CHECK_EQUAL(6, m_abs[5]);
}
TEST(SqrtVectorCol)
{
 LinAlg::Vector<int> v = {1, 9, 4};
 LinAlg::Vector<int> v_sqrt = LinAlg::sqrt(v);
 CHECK_EQUAL(1, v_sqrt[0]);
 CHECK_EQUAL(3, v_sqrt[1]);
 CHECK_EQUAL(2, v_sqrt[2]);
}
TEST(SqrtVectorRow)
{
 LinAlg::Vector<int> v = {1, 9, 4};
 LinAlg::Vector<int> v_sqrt = LinAlg::sqrt(v.transpose());
 CHECK_EQUAL(1, v_sqrt[0]);
 CHECK_EQUAL(3, v_sqrt[1]);
 CHECK_EQUAL(2, v_sqrt[2]);
}
TEST(SqrtMatrix)
{
 LinAlg::Matrix<int> m = {{1, 9, 4},{25, 16, 36}};
 LinAlg::Matrix<int> m_sqrt = LinAlg::sqrt(m);
 CHECK_EQUAL(1, m_sqrt[0]);
 CHECK_EQUAL(3, m_sqrt[1]);
 CHECK_EQUAL(2, m_sqrt[2]);
 CHECK_EQUAL(5, m_sqrt[3]);
 CHECK_EQUAL(4, m_sqrt[4]);
 CHECK_EQUAL(6, m_sqrt[5]);
}
TEST(SqrtNegative)
{
 LinAlg::Vector<int> v = {-1, -3, -2};
 CHECK_THROW(LinAlg::sqrt(v), std::invalid_argument);
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
TEST(DiagMatrix)
{
 LinAlg::Matrix<int> m = {{1, 3, 5},{2, 4, 6}};
 LinAlg::Vector<int> v = LinAlg::diag(m);
 CHECK_EQUAL(2, v.size());
 CHECK_EQUAL(1, v[0]);
 CHECK_EQUAL(4, v[1]);
}
TEST(DotVector)
{
 LinAlg::Vector<int> v1 = {-1, -3, -2};
 LinAlg::Vector<int> v2 = {2, -4, -7};
 auto res = LinAlg::dot(v1,v2);
 CHECK_EQUAL(24, res);
}
TEST(DotMatrix)
{
 LinAlg::Matrix<int> m = {{1,2,3},{4,5,6},{7,8,9}};
 LinAlg::Vector<int> v = LinAlg::dot(m,m);
 CHECK_EQUAL(14, v[0]);
 CHECK_EQUAL(77, v[1]);
 CHECK_EQUAL(194, v[2]);
}
#endif // FUNCTIONTESTS_HPP_INCLUDED
