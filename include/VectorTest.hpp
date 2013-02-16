#ifndef VECTORTEST_HPP_INCLUDED
#define VECTORTEST_HPP_INCLUDED
SUITE(VectorTest)
{
TEST(PreallocateMemory)
{
 LinAlg::Vector<int> v(20);
 CHECK_EQUAL(20, v.size());
 CHECK(!v.empty());
}
TEST(DefaultConstruct)
{
 LinAlg::Vector<int> v;
 CHECK_EQUAL(0, v.size());
 CHECK(v.empty());
}

TEST(ConstructWithInitializerList)
{
    LinAlg::Vector<int> v = {1, 2, 3, 4};
    CHECK_EQUAL(4, v.size());
    CHECK_EQUAL(3, v[2]);
}
TEST(ConstructFilled)
{
    LinAlg::Vector<int> v(4,13);
    CHECK_EQUAL(4, v.size());
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
}
#endif // VECTORTEST_HPP_INCLUDED
