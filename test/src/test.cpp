//#include "pch.h"
#include "gtest/gtest.h"
#include "Calculator.h"

TEST(TestSum, Test1) {
    Calculator* calculator = new Calculator(1);
    EXPECT_EQ(calculator->sum(3, 2), 5);
}

TEST(TestSum, Test2) {
    Calculator *calculator = new Calculator(1);
    EXPECT_EQ(calculator->sum(1, 2), 3);
}

TEST(TestMul, Test1) {
    Calculator* calculator = new Calculator(1);
    EXPECT_EQ(calculator->mul(1, 2), 2);
}

TEST(TestMul, Test2) {
    Calculator* calculator = new Calculator(1);
    EXPECT_EQ(calculator->mul(10, 9), 90);
}