#include "gtest/gtest.h"
#include "MultiplyTwoIntegersAlgorithmTest.h"

template<int BITS>
void testAllInputs() {
    MultiplyTwoIntegersAlgorithmTest<BITS> multTwoAlg{};
    for (int a = 0; a < pow(2, BITS); a++) {
        for (int b = 0; b < pow(2, BITS); ++b) {
            int result = multTwoAlg.multiply(a, b);
            ASSERT_EQ((a * b) % (int) pow(2, BITS), result);
        }
    }
}

TEST(MultiplyTwoIntegersAlgorithmTestSuite, Multiply1Bits) {
    testAllInputs<1>();
}

TEST(MultiplyTwoIntegersAlgorithmTestSuite, Multiply4Bits) {
    testAllInputs<4>();
}

TEST(MultiplyTwoIntegersAlgorithmTestSuite, Multiply5Bits) {
    testAllInputs<5>();
}

template<int BITS>
void testRandomInputs(int trials) {
    MultiplyTwoIntegersAlgorithmTest<BITS> addTwoAlg{};
    for (int i = 0; i < trials; ++i) {
        int a = rand() % (int) pow(2, BITS);
        int b = rand() % (int) pow(2, BITS);
        int result = addTwoAlg.multiply(a, b);
        ASSERT_EQ(result, (a * b) % (int) pow(2, BITS)) << "a: " << a << ", b: " << b << std::endl;
    }
}


TEST(MultiplyTwoIntegersAlgorithmTestSuite, Multiply16Bits) {
    testRandomInputs<16>(1000);
}

TEST(MultiplyTwoIntegersAlgorithmTestSuite, Multiply20Bits) {
    testRandomInputs<20>(2000);
}