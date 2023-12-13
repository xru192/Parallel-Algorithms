#include "gtest/gtest.h"
#include "AddThreeIntegersAlgorithm.h"

TEST(AddThreeIntegersAlgorithmTestSuite, Add4Bits) {
    const int numBits = 4;
    AddThreeIntegersAlgorithm<numBits> addThreeAlg{};

    for (int x = 0; x < pow(2, numBits); x++) {
        for (int y = 0; y < pow(2, numBits); ++y) {
            for (int z = 0; z < pow(2, numBits); ++z) {
                int result = addThreeAlg.add(x, y, z);
                ASSERT_EQ((x + y + z) % (int) pow(2, numBits), result);
            }
        }
    }
}

TEST(AddThreeIntegersAlgorithmTestSuite, Add5Bits) {
    const int numBits = 5;
    AddThreeIntegersAlgorithm<numBits> addThreeAlg{};

    for (int x = 0; x < pow(2, numBits); x++) {
        for (int y = 0; y < pow(2, numBits); ++y) {
            for (int z = 0; z < pow(2, numBits); ++z) {
                int result = addThreeAlg.add(x, y, z);
                ASSERT_EQ((x + y + z) % (int) pow(2, numBits), result);
            }
        }
    }
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


TEST(AddThreeIntegersAlgorithmTestSuite, Add16Bits) {
    testRandomInputs<16>(1000);
}

TEST(AddThreeIntegersAlgorithmTestSuite, Add20Bits) {
    testRandomInputs<20>(2000);
}
