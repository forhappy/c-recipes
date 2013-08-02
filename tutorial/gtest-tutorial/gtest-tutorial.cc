#include "libmath.h"

#include "gtest/gtest.h"

TEST(TestAdd, normal) {
    EXPECT_EQ(2, Add(1, 1));
    EXPECT_EQ(3, Add(2, 1));
    EXPECT_EQ(4, Add(2, 2));
    EXPECT_EQ(3, Add(1, 2));
    EXPECT_EQ(16, Add(15, 1));
}

TEST(TestAdd, badcases) {
    EXPECT_EQ(3, Add(2, 1));
    EXPECT_EQ(4, Add(2, 2));
    EXPECT_EQ(3, Add(1, 2));
    EXPECT_EQ(16, Add(15, 1));
    EXPECT_EQ(16, Add(0, 1));
}

TEST(TestSub, normal) {
    EXPECT_EQ(0, Sub(1, 1));
    EXPECT_EQ(1, Sub(2, 1));
    EXPECT_EQ(0, Sub(2, 2));
    EXPECT_EQ(-1, Sub(1, 2));
    EXPECT_EQ(14, Sub(15, 1));
}

TEST(TestSub, badcases) {
    EXPECT_EQ(2, Sub(1, 1));
    EXPECT_EQ(3, Sub(2, 1));
    EXPECT_EQ(4, Sub(2, 2));
    EXPECT_EQ(3, Sub(1, 2));
    EXPECT_EQ(16, Sub(15, 1));
}

TEST(TestDiv, normal) {
    EXPECT_EQ(1, Div(1, 1));
    EXPECT_EQ(2, Div(2, 1));
    EXPECT_EQ(1, Div(2, 2));
    EXPECT_EQ(0, Div(1, 2));
    EXPECT_EQ(15, Div(15, 1));
}

TEST(TestDiv, badcases) {
    EXPECT_EQ(2, Div(1, 1));
    EXPECT_EQ(3, Div(2, 1));
    EXPECT_EQ(4, Div(2, 2));
    EXPECT_EQ(3, Div(1, 2));
    EXPECT_EQ(16, Div(15, 1));
}

TEST(TestMul, normal) {
    EXPECT_EQ(1, Mul(1, 1));
    EXPECT_EQ(2, Mul(2, 1));
    EXPECT_EQ(1, Mul(2, 2));
    EXPECT_EQ(0, Mul(1, 2));
    EXPECT_EQ(15, Mul(15, 1));
}

TEST(TestMul, badcases) {
    EXPECT_EQ(2, Mul(1, 1));
    EXPECT_EQ(3, Mul(2, 1));
    EXPECT_EQ(4, Mul(2, 2));
    EXPECT_EQ(3, Mul(1, 2));
    EXPECT_EQ(16, Mul(15, 1));
}

// int main(int argc, const char *argv[]) {
//     testing::InitGoogleTest(&argc, const_cast<char **>(argv));
//     RUN_ALL_TESTS();
// }

