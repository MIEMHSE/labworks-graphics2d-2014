#include "gtest/gtest.h"
#include "vector.h"

using namespace pashazz;
using namespace std;
class VectorTest : public ::testing::Test
{
protected:
    virtual ~VectorTest(){}
    VectorTest ()
    {
        i = Point2D(1,0);
        j = Point2D (0, 1);
        k = Point2D (1, 2);
        cout << i << " " << j << " " << k << endl;
    }
    Point2D i;
    Point2D j;
    Point2D k;
};

TEST_F(VectorTest, ConstructorTest)
{
    EXPECT_EQ(i.x, 1.0);
    EXPECT_EQ(i.y, 0.0);
}
TEST_F(VectorTest, TestAngle)
{
    EXPECT_DOUBLE_EQ(i.angle(), 0.0);

    EXPECT_DOUBLE_EQ(j.angle(), M_PI/2);

}

TEST_F(VectorTest, TestTranslation)
{
    Point2D j_to90 = Point2D(-1, 0);
    EXPECT_DOUBLE_EQ(j_to90.x, j.rotate(M_PI/2).x);

    Point2D k_to90 = Point2D(-2, 1);
    EXPECT_DOUBLE_EQ(k_to90.y, k.rotate(M_PI / 2).y);
    EXPECT_DOUBLE_EQ(k_to90.x, k.rotate(M_PI / 2).x);

    Point2D itok =Point2D(0, -2);
    EXPECT_DOUBLE_EQ(itok.x, k.translate(i).x);
    EXPECT_DOUBLE_EQ(itok.y, k.translate(i).y);

}

TEST_F(VectorTest, TestMultiplication)
{
    Point2D exp_k = {2,4};
    EXPECT_DOUBLE_EQ(exp_k.x, (2*k).x);
    EXPECT_DOUBLE_EQ(exp_k.y, (2*k).y);
}
