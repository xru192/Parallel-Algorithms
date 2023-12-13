#include "gtest/gtest.h"
#include "AddThreeIntegersAlgorithm.h"

template<int BITS>
void testAllAddThreeInputs() {
    AddThreeIntegersAlgorithm<BITS> addThreeAlg{};
    for (int x = 0; x < pow(2, BITS); x++) {
        for (int y = 0; y < pow(2, BITS); ++y) {
            for (int z = 0; z < pow(2, BITS); ++z) {
                int result = addThreeAlg.add(x, y, z);
                ASSERT_EQ((x + y + z) % (int) pow(2, BITS), result);
            }
        }
    }
}

TEST(AddThreeIntegersAlgorithmTestSuite, Add1Bits) {
    testAllAddThreeInputs<1>();
}

TEST(AddThreeIntegersAlgorithmTestSuite, Add4Bits) {
    testAllAddThreeInputs<4>();
}

TEST(AddThreeIntegersAlgorithmTestSuite, Add5Bits) {
    testAllAddThreeInputs<5>();
}

template<int BITS>
void testAddThreeRandomInputs(int trials) {
    AddThreeIntegersAlgorithm<BITS> addThreeAlg{};
    for (int i = 0; i < trials; ++i) {
        int a = rand() % (int) pow(2, BITS);
        int b = rand() % (int) pow(2, BITS);
        int c = rand() % (int) pow(2, BITS);
        int result = addThreeAlg.add(a, b, c);
        ASSERT_EQ(result, (a + b + c) % (int) pow(2, BITS))
                                    << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
    }
}

TEST(AddThreeIntegersAlgorithmTestSuite, Add16Bits) {
    testAddThreeRandomInputs<16>(1000);
}

TEST(AddThreeIntegersAlgorithmTestSuite, Add20Bits) {
    testAddThreeRandomInputs<20>(2000);
}
