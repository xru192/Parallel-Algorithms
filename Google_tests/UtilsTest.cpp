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

TEST(UtilsTestSuite, shiftBitArray) {
    std::array<int, 4> original {1, 0, 1, 1};
    std::array<int, 4> shifted1 {0, 1, 0, 1};
    std::array<int, 4> shifted2 {0, 0, 1, 0};
    std::array<int, 4> shifted3 {0, 0, 0, 1};
    std::array<int, 4> shifted4 {0, 0, 0, 0};

    ASSERT_EQ(utils::shiftBitArray(original, 0), original);
    ASSERT_EQ(utils::shiftBitArray(original, 1), shifted1);
    ASSERT_EQ(utils::shiftBitArray(original, 2), shifted2);
    ASSERT_EQ(utils::shiftBitArray(original, 3), shifted3);
    ASSERT_EQ(utils::shiftBitArray(original, 4), shifted4);
}
