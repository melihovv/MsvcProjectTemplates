#include "stdafx.h"
#include <gtest/gtest.h>
#include <vector>

TEST(Test, TestCase)
{
    ASSERT_EQ(true, true);
}

class VectorTest : public ::testing::Test
{
protected:
    // virtual void SetUp();
    // virtual void TearDown() {}

    std::vector<int> v_;
};

TEST_F(VectorTest, IsEmptyInitially)
{
    EXPECT_EQ(0, v_.size());
}