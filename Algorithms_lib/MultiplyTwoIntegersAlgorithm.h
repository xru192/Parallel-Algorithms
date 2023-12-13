//
// Created by Ryan Xu on 12/10/23.
//

#ifndef PARALLELALGORITHMS_MULTIPLYTWOINTEGERSALGORITHM_H
#define PARALLELALGORITHMS_MULTIPLYTWOINTEGERSALGORITHM_H

#include <vector>
#include <future>
#include "Utils.h"
#include "AddThreeIntegersAlgorithm.h"

template<int BITS>
class MultiplyTwoIntegersAlgorithmTest {
    using bitarray = std::array<int, BITS>;
public:
    int multiply(int a, int b);

private:
    std::vector<std::array<int, BITS>> numsToAdd{};

    // In parallel, replace triplets of numsToAdd with pairs of numsToAdd using the reduction for adding 3 integers
    void reduceNumsToAdd();

    // In parallel, reduce the addition of 4 numbers to 3 using the reduction
    // This case must be handled slightly differently
    void reduce4NumsToAdd();
};

template<int BITS>
int MultiplyTwoIntegersAlgorithmTest<BITS>::multiply(int a, int b) {
    // reset from previous computation
    numsToAdd.clear();

    std::array<int, BITS> aBitArray = utils::intToBitArray<BITS>(a);
    std::array<int, BITS> bBitArray = utils::intToBitArray<BITS>(b);

    // Insert the numbers to add into numsToAdd

    for (int i = 0; i < BITS; ++i) {
        if (bBitArray[i] == 1) {
            bitarray term = utils::shiftBitArray(aBitArray, i);
            numsToAdd.push_back(term);
        }
    }

    // Handle edge cases when there are fewer than 2 things to add

    // when the second input is 0 return 0
    if (numsToAdd.size() == 0) {
        return 0;
    }

    if (numsToAdd.size() == 1) {
        return utils::bitArrayToInt(numsToAdd[0]);
    }

    // While there are 3 things to add or more, apply reduction from adding 3 to adding 2 integers
    while (numsToAdd.size() > 2) {
        reduceNumsToAdd();
    }

    // Now there are exactly 2 things to add, so use algorithm for adding 2 integers
    AddTwoIntegersAlgorithm<BITS> addTwoAlg{};

    return addTwoAlg.add(numsToAdd[0], numsToAdd[1]);
}

template<int BITS>
void MultiplyTwoIntegersAlgorithmTest<BITS>::reduceNumsToAdd() {
    if (numsToAdd.size() == 4) {
        reduce4NumsToAdd();
        return;
    }

    // make sure # of nums to add is divisible by 3
    while (numsToAdd.size() % 3 != 0) {
        bitarray zeros{};
        numsToAdd.push_back(zeros);
    }

    std::vector<std::future<std::pair<bitarray, bitarray>>> futures{};

    for (int i = 0; i < numsToAdd.size(); i += 3) {
        futures.push_back(std::async(std::launch::async, [this, i]() {
            AddThreeIntegersAlgorithm<BITS> addThreeAlg{};
            auto pair = addThreeAlg.reduceAdd(numsToAdd[i], numsToAdd[i + 1], numsToAdd[i + 2]);
            return pair;
        }));
    }

    std::vector<bitarray> newNumsToAdd{};

    for (auto &future: futures) {
        auto result = future.get();
        newNumsToAdd.push_back(result.first);
        newNumsToAdd.push_back(result.second);
    }

    numsToAdd = newNumsToAdd;
}

template<int BITS>
void MultiplyTwoIntegersAlgorithmTest<BITS>::reduce4NumsToAdd() {
    AddThreeIntegersAlgorithm<BITS> addThreeAlg{};
    auto pair = addThreeAlg.reduceAdd(numsToAdd[0], numsToAdd[1], numsToAdd[2]);

    std::vector<bitarray> newNumsToAdd{};

    newNumsToAdd.push_back(pair.first);
    newNumsToAdd.push_back(pair.second);
    newNumsToAdd.push_back(numsToAdd[3]);

    numsToAdd = newNumsToAdd;
}


#endif //PARALLELALGORITHMS_MULTIPLYTWOINTEGERSALGORITHM_H
