#include "gtest/gtest.h"
#include "Utils.h"
#include <cmath>

TEST(UtilsTestSuite, intTo4BitArray) {
    std::array<int, 4> expected1{1, 0, 0, 0};
    ASSERT_EQ(utils::intToBitArray<4>(1), expected1);

    std::array<int, 4> expected10{0, 1, 0, 1};
    ASSERT_EQ(utils::intToBitArray<4>(10), expected10);

    std::array<int, 4> expected18{0, 1, 0, 0};
    ASSERT_EQ(utils::intToBitArray<4>(18), expected18);
}

TEST(UtilsTestSuite, bitArrayToInt) {
    std::array<int, 4> arr1{1, 0, 0, 0};
    ASSERT_EQ(utils::bitArrayToInt<4>(arr1), 1);

    std::array<int, 4> arr10{0, 1, 0, 1};
    ASSERT_EQ(utils::bitArrayToInt<4>(arr10), 10);

    std::array<int, 4> arr2{0, 1, 0, 0};
    ASSERT_EQ(utils::bitArrayToInt<4>(arr2), 2);
}


TEST(UtilsTestSuite, logBits) {
    for (int bits = 1; bits <= 32; ++bits) {
        EXPECT_EQ(utils::logBits(bits), ceil(log2(bits))) << "error for bits=" << bits;
    }
}

