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