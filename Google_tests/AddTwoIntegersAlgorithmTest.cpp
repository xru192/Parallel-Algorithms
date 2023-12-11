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

//TEST(AddTwoIntegersAlgorithmTestSuite, Add8Bits) {
//    testAllInputs<8>();
//}