#include "gtest/gtest.h"
#include "AddTwoIntegersAlgorithm.h"

template<int BITS>
void testAllInputs() {
    AddTwoIntegersAlgorithm<BITS> addTwoAlg{};
    for (int a = 0; a < pow(2, BITS); a++) {
        for (int b = 0; b < pow(2, BITS); ++b) {
            int result = addTwoAlg.add(a, b);
            ASSERT_EQ((a + b) % (int) pow(2, BITS), result);
        }
    }
}

TEST(AddTwoIntegersAlgorithmTestSuite, Add1Bits) {
    testAllInputs<1>();
}

TEST(AddTwoIntegersAlgorithmTestSuite, Add4Bits) {
    testAllInputs<4>();
}

TEST(AddTwoIntegersAlgorithmTestSuite, Add5Bits) {
    testAllInputs<5>();
}

template<int BITS>
void testRandomInputs(int trials) {
    AddTwoIntegersAlgorithm<BITS> addTwoAlg{};
    for (int i = 0; i < trials; ++i) {
        int a = rand() % (int) pow(2, BITS);
        int b = rand() % (int) pow(2, BITS);
        int result = addTwoAlg.add(a, b);
        ASSERT_EQ(result, (a + b) % (int) pow(2, BITS)) << "a: " << a << ", b: " << b << std::endl;
    }
}


TEST(AddTwoIntegersAlgorithmTestSuite, Add16Bits) {
    testRandomInputs<16>(1000);
}

TEST(AddTwoIntegersAlgorithmTestSuite, Add20Bits) {
    testRandomInputs<20>(2000);
}
