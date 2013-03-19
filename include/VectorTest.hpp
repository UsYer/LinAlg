#ifndef VECTORTEST_HPP_INCLUDED
#define VECTORTEST_HPP_INCLUDED
#include "Functions.hpp"
SUITE(VectorTest)
{
TEST(PreallocateMemory)
{
 LinAlg::Vector<int> v(20);
 CHECK_EQUAL(20u, v.size());
 CHECK(!v.empty());
}
TEST(DefaultConstruct)
{
 LinAlg::Vector<int> v;
 CHECK_EQUAL(0u, v.size());
 CHECK(v.empty());
}

TEST(ConstructWithInitializerList)
{
    LinAlg::Vector<int> v = {1, 2, 3, 4};
    CHECK_EQUAL(4u, v.size());
    CHECK_EQUAL(3, v[2]);
}
TEST(ConstructFilled)
{
    LinAlg::Vector<int> v(4,13);
    CHECK_EQUAL(4u, v.size());
    CHECK_EQUAL(13, v[0]);
    CHECK_EQUAL(13, v[1]);
    CHECK_EQUAL(13, v[2]);
    CHECK_EQUAL(13, v[3]);
}
TEST(AccessFirstElement)
{
    LinAlg::Vector<int> v(10);
    CHECK_EQUAL(0, v[0]);
}
TEST(ModificationOfElement)
{
    LinAlg::Vector<int> v(3);
    v[2] = 13;
    CHECK_EQUAL(13, v[2]);
}
TEST(EquivalenceInitializerList)
{
    LinAlg::Vector<int> v = {1, 2, 3};
    auto vals = {1, 2, 3};
    bool res = (vals == v);
    CHECK(res);
}
TEST(Transpose)
{
    LinAlg::Vector<int> v = {1, 2, 3};
    CHECK(v.is_col_vec());
    v.transpose();
    CHECK(!v.is_col_vec());
}
TEST(AssignAdd)
{
    LinAlg::Vector<int> v = {1, 2, 3};
    v += {1, 2, 3};
    CHECK_EQUAL(2, v[0]);
    CHECK_EQUAL(4, v[1]);
    CHECK_EQUAL(6, v[2]);
}
TEST(AssignAddDiffDimensions)
{
    LinAlg::Vector<int> v = {1, 2, 3};
    CHECK_THROW(v += LinAlg::transpose(v), std::invalid_argument);
}
TEST(Add)
{
    LinAlg::Vector<int> v = {1, 2, 3};
    v = v + LinAlg::Vector<int>{1, 2, 3};
    CHECK_EQUAL(2, v[0]);
    CHECK_EQUAL(4, v[1]);
    CHECK_EQUAL(6, v[2]);
}
TEST(AddDiffDimensions1)
{
    LinAlg::Vector<int> v = {1, 2, 3};
    LinAlg::Vector<int> v2 = {1, 2};
    CHECK_THROW(v + v2, std::invalid_argument);
}
TEST(AddDiffDimensions2)
{
    LinAlg::Vector<int> v = {1, 2, 3};
    CHECK_THROW(v + LinAlg::transpose(v), std::invalid_argument);
}
TEST(AssignSub)
{
    LinAlg::Vector<int> v = {1, 2, 3};
    v -= {1, 2, 3};
    CHECK_EQUAL(0, v[0]);
    CHECK_EQUAL(0, v[1]);
    CHECK_EQUAL(0, v[2]);
}
TEST(AssignSubDiffDimensions)
{
    LinAlg::Vector<int> v = {1, 2, 3};
    CHECK_THROW(v -= LinAlg::transpose(v), std::invalid_argument);
}
TEST(Sub)
{
    LinAlg::Vector<int> v = {1, 2, 3};
    v = v - LinAlg::Vector<int>{1, 2, 3};
    CHECK_EQUAL(0, v[0]);
    CHECK_EQUAL(0, v[1]);
    CHECK_EQUAL(0, v[2]);
}
TEST(SubDiffDimensions1)
{
    LinAlg::Vector<int> v = {1, 2, 3};
    LinAlg::Vector<int> v2 = {1, 2};
    CHECK_THROW(v - v2, std::invalid_argument);
}
TEST(SubDiffDimensions2)
{
    LinAlg::Vector<int> v = {1, 2, 3};
    CHECK_THROW(v - LinAlg::transpose(v), std::invalid_argument);
}
TEST(ScalarMult)
{
    LinAlg::Vector<int> v = {1, 2, 3};
    LinAlg::Vector<int> res = {5, 10, 15};
    CHECK((v * 5) == res);
}
TEST(ScalarMultCommutative)
{
    LinAlg::Vector<int> v = {1, 2, 3};
    CHECK((v * 5) == (5 * v));
}
}
#endif // VECTORTEST_HPP_INCLUDED
