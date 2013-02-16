#ifndef MATRIXTEST_HPP_INCLUDED
#define MATRIXTEST_HPP_INCLUDED
SUITE(MatrixTest)
{
TEST(PreallocateMemory)
{
 LinAlg::Matrix<int> m(20,20);
 CHECK_EQUAL(400, m.size());
 CHECK(!m.empty());
}
TEST(DefaultConstruct)
{
 LinAlg::Matrix<int> m;
 CHECK_EQUAL(0, m.size());
 CHECK(m.empty());
}
TEST(ConstructWithInitializerList)
{
    LinAlg::Matrix<int> m = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    CHECK_EQUAL(8, m.size());
    CHECK_EQUAL(2, m.col_size());
    CHECK_EQUAL(4, m.row_size());
}
TEST(ConstructFilled)
{
    LinAlg::Matrix<int> m(2,2,13);
    CHECK_EQUAL(4, m.size());
    CHECK_EQUAL(2, m.col_size());
    CHECK_EQUAL(2, m.row_size());
    CHECK_EQUAL(13, m[0]);
    CHECK_EQUAL(13, m[1]);
    CHECK_EQUAL(13, m[2]);
    CHECK_EQUAL(13, m[3]);
}
TEST(VerfiyNoOfRows)
{
    LinAlg::Matrix<int> m(20,10);
    CHECK_EQUAL(20, m.row_size());
}

TEST(VerfiyNoOfCols)
{
    LinAlg::Matrix<int> m(20,10);
    CHECK_EQUAL(10, m.col_size());
}

TEST(AccessFirstElement)
{
    LinAlg::Matrix<int> m(20,10);
    CHECK_EQUAL(0, m[0]);
}
TEST(CalculationOfIndex)
{
    LinAlg::Matrix<int> m(10,10);
    CHECK_EQUAL(0, m[10]);
}
TEST(ModificationOfElement)
{
    LinAlg::Matrix<int> m(2,2,13);
    CHECK_EQUAL(13, m[0]);
    CHECK_EQUAL(13, m[1]);
    CHECK_EQUAL(13, m[2]);
    CHECK_EQUAL(13, m[3]);
    m[2] = 26;
    CHECK_EQUAL(13, m[0]);
    CHECK_EQUAL(13, m[1]);
    CHECK_EQUAL(26, m[2]);
    CHECK_EQUAL(13, m[3]);
}
}
#endif // MATRIXTEST_HPP_INCLUDED
