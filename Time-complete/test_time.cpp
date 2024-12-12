#include <gtest/gtest.h>
#include <iostream>
#include <cassert>
#include "time.cpp" 

TEST(TimeTest, DefaultConstructor) {
    Time t1;
    EXPECT_EQ(t1.GetHours(), 0);
    EXPECT_EQ(t1.GetMinutes(), 0);
    EXPECT_EQ(t1.GetSeconds(), 0);
}
TEST(TimeTest, CopyConstructor) {
    Time t1(1, 2, 3);
    Time t2(t1);
    EXPECT_EQ(t2.GetHours(), 1);
    EXPECT_EQ(t2.GetMinutes(), 2);
    EXPECT_EQ(t2.GetSeconds(), 3);
}
//заранее неверный тест - оставить
TEST(TimeTest, AssignmentOperator) {
    Time t1(1, 2, 3);
    Time t2(4, 5, 6);
    t1 = t2;
    EXPECT_EQ(t1.GetHours(), 4);
    EXPECT_EQ(t1.GetMinutes(), 15);
    EXPECT_EQ(t1.GetSeconds(), 30);
}

TEST(TimeTest, ToSeconds) {
    Time t1(1, 2, 3);
    EXPECT_EQ(t1.ToSeconds(), 3723);
}

TEST(TimeTest, SubtractionOperator) {
    Time t1(10, 20, 30);
    Time t2(5, 10, 5);
    Time t3 = t1 - t2;
    EXPECT_EQ(t3.GetHours(), 5);
    EXPECT_EQ(t3.GetMinutes(), 10);
    EXPECT_EQ(t3.GetSeconds(), 25);
}

TEST(TimeTest, SubtractionAssignmentOperator) {
    Time t1(10, 20, 30);
    Time t2(5, 10, 5);
    t1 -= t2;
    EXPECT_EQ(t1.GetHours(), 5);
    EXPECT_EQ(t1.GetMinutes(), 10);
    EXPECT_EQ(t1.GetSeconds(), 25);
}

TEST(TimeTest, EqualityOperator) {
    Time t1(1, 2, 3);
    Time t2(1, 2, 3);
    EXPECT_TRUE(t1 == t2);
}

TEST(TimeTest, InequalityOperator) {
    Time t1(1, 2, 3);
    Time t2(4, 5, 6);
    EXPECT_TRUE(t1 != t2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
