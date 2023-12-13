#include "gtest/gtest.h"
#include "MultiplyTwoIntegersAlgorithm.h"

template<int BITS>
void testAllMultiplyTwoInputs() {
    MultiplyTwoIntegersAlgorithmTest<BITS> multTwoAlg{};
    for (int a = 0; a < pow(2, BITS); ++a) {
        for (int b = 0; b < pow(2, BITS); ++b) {
            int result = multTwoAlg.multiply(a, b);
            ASSERT_EQ((a * b) % (int) pow(2, BITS), result) << "a: " << a << ", b: " << b << std::endl;
        }
    }
}

TEST(MultiplyTwoIntegersAlgorithmTestSuite, Multiply1Bits) {
    testAllMultiplyTwoInputs<1>();
}

TEST(MultiplyTwoIntegersAlgorithmTestSuite, Multiply4Bits) {
    testAllMultiplyTwoInputs<4>();
}

TEST(MultiplyTwoIntegersAlgorithmTestSuite, Multiply5Bits) {
    testAllMultiplyTwoInputs<5>();
}

template<int BITS>
void testMultiplyTwoRandomInputs(int trials) {
    MultiplyTwoIntegersAlgorithmTest<BITS> addTwoAlg{};
    for (int i = 0; i < trials; ++i) {
        int a = rand() % (int) pow(2, BITS);
        int b = rand() % (int) pow(2, BITS);
        int result = addTwoAlg.multiply(a, b);
        ASSERT_EQ(result, (a * b) % (int) pow(2, BITS)) << "a: " << a << ", b: " << b << std::endl;
    }
}


TEST(MultiplyTwoIntegersAlgorithmTestSuite, Multiply8Bits) {
    testMultiplyTwoRandomInputs<8>(1000);
}

TEST(MultiplyTwoIntegersAlgorithmTestSuite, Multiply15Bits) {
    testMultiplyTwoRandomInputs<15>(2000);
}