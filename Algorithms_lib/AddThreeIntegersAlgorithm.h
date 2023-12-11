#ifndef PARALLELALGORITHMS_ADDTHREEINTEGERSALGORITHM_H
#define PARALLELALGORITHMS_ADDTHREEINTEGERSALGORITHM_H

#include "AddTwoIntegersAlgorithm.h"
#include <future>

template<int BITS>
class AddThreeIntegersAlgorithm {

public:
    int add(int x, int y, int z);


private:
    AddTwoIntegersAlgorithm<BITS> addTwoAlg{};

    std::array<std::array<int, BITS>, 3> data{};

    std::array<int, BITS> evenSumData{};    // stores E(x) + E(y) + E(z), where E(x) = x with odd bits set to 0
    std::array<int, BITS> oddSumData{};     // stores O(x) + O(y) + O(z), where O(x) = x with even bits set to 0

    // performs x[bit] + y[bit] + z[bit] and updates bits b and b+1 in evenSumData
    void computeEvenSumBits(int bit);

    // performs x[bit] + y[bit] + z[bit] and updates bits b and b+1 in oddSumData
    void computeOddSumBits(int bit);

};

template<int BITS>
int AddThreeIntegersAlgorithm<BITS>::add(int x, int y, int z) {
    // reset data from previous computation
    evenSumData.fill(0);
    oddSumData.fill(0);

    std::array<int, BITS> xBitArray = utils::intToBitArray<BITS>(x);
    std::array<int, BITS> yBitArray = utils::intToBitArray<BITS>(y);
    std::array<int, BITS> zBitArray = utils::intToBitArray<BITS>(z);

    data = {xBitArray, yBitArray, zBitArray};

    std::vector<std::future<void>> futures;
    // compute even and odd sums in parallel
    for (int evenBit = 0; evenBit < BITS; evenBit += 2) {
        futures.push_back(std::async(std::launch::async, [evenBit, this]() {
            computeEvenSumBits(evenBit);
        }));
    }

    for (int oddBit = 1; oddBit < BITS; oddBit += 2) {
        futures.push_back(std::async(std::launch::async, [oddBit, this]() {
            computeOddSumBits(oddBit);
        }));
    }

    for (const auto &future: futures) {
        future.wait();
    }

    int a = utils::bitArrayToInt<BITS>(evenSumData);
    int b = utils::bitArrayToInt<BITS>(oddSumData);


    return addTwoAlg.add(a, b);
}

template<int BITS>
void AddThreeIntegersAlgorithm<BITS>::computeEvenSumBits(int bit) {
    assert(bit % 2 == 0);
    int xBit = data[0][bit];
    int yBit = data[1][bit];
    int zBit = data[2][bit];
    evenSumData[bit] = data[0][bit] ^ data[1][bit] ^ data[2][bit];
    if (bit + 1 < BITS) {
        evenSumData[bit + 1] = (xBit & yBit) | (xBit & zBit) | (yBit & zBit);
    }
}

template<int BITS>
void AddThreeIntegersAlgorithm<BITS>::computeOddSumBits(int bit) {
    assert(bit % 2 == 1);
    int xBit = data[0][bit];
    int yBit = data[1][bit];
    int zBit = data[2][bit];
    oddSumData[bit] = data[0][bit] ^ data[1][bit] ^ data[2][bit];
    if (bit + 1 < BITS) {
        oddSumData[bit + 1] = (xBit & yBit) | (xBit & zBit) | (yBit & zBit);
    }
}


#endif //PARALLELALGORITHMS_ADDTHREEINTEGERSALGORITHM_H
