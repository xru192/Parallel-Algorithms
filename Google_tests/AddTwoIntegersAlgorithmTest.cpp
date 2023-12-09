#include "gtest/gtest.h"
#include "AddTwoIntegersAlgorithm.h"

TEST(AddTwoIntegersAlgorithmTestSuite, Add4Bits) {
    const int numBits = 4;
    AddTwoIntegersAlgorithm<numBits> addTwoAlg {};

    for (int a = 0; a < pow(2, numBits); a++) {
        for (int b = 0; b < pow(2, numBits); ++b) {
            int result = addTwoAlg.add(a, b);
            std::cout << a << " + " << b << " = " << result << std::endl;
            assert((a + b) % (int)pow(2, numBits) == result);
        }
    }
}

TEST(AddTwoIntegersAlgorithmTestSuite, Add5Bits) {
    const int numBits = 5;
    AddTwoIntegersAlgorithm<numBits> addTwoAlg {};

    for (int a = 0; a < pow(2, numBits); a++) {
        for (int b = 0; b < pow(2, numBits); ++b) {
            int result = addTwoAlg.add(a, b);
            std::cout << a << " + " << b << " = " << result << std::endl;
            assert((a + b) % (int)pow(2, numBits) == result);
        }
    }
}