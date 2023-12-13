#ifndef PARALLELALGORITHMS_ADDTWOINTEGERSALGORITHM_H
#define PARALLELALGORITHMS_ADDTWOINTEGERSALGORITHM_H

#include <array>
#include <vector>
#include <cmath>
#include <future>
#include "Utils.h"

template<int BITS>
class AddTwoIntegersAlgorithm {

public:
    static constexpr int LOG_BITS = utils::logBits(BITS) + 1;

    AddTwoIntegersAlgorithm() = default;

    int add(int a, int b);

    int add(std::array<int, BITS> aBitArray, std::array<int, BITS> bBitArray);

private:
    const int STAR = -1;
    std::array<std::array<int, LOG_BITS + 1>, BITS> data{};

    void recurrence(int i, int k);

};

template<int BITS>
int AddTwoIntegersAlgorithm<BITS>::add(int a, int b) {
    // Reset data from previous computation
    for (auto &arr: data) {
        arr.fill(0);
    }

    std::array<int, BITS> aBitArray = utils::intToBitArray<BITS>(a);
    std::array<int, BITS> bBitArray = utils::intToBitArray<BITS>(b);

    data[0][0] = 0;
    for (std::size_t i = 1; i < BITS; ++i) {
        if (aBitArray[i - 1] == 1 && bBitArray[i - 1] == 1) {
            data[i][0] = 1;
        } else if (aBitArray[i - 1] != bBitArray[i - 1]) {
            data[i][0] = STAR;
        }
    }

    for (int k = 1; k < LOG_BITS + 1; ++k) {
        std::vector<std::future<void>> threads;
        threads.reserve(BITS);
        for (int i = 0; i < BITS; ++i) {
            threads.push_back(std::async(std::launch::async, [i, k, this]() {
                recurrence(i, k);
            }));
        }

        for (auto &future: threads) {
            future.wait();
        }
    }

    a = utils::bitArrayToInt(aBitArray);    // in case a originally had more than BITS bits
    b = utils::bitArrayToInt(bBitArray);
    int c = 0;
    for (int i = 0; i < BITS; ++i) {
        c += data[i][LOG_BITS] * (int) pow(2, i);
    }

    return a ^ b ^ c;
}

template<int BITS>
int AddTwoIntegersAlgorithm<BITS>::add(std::array<int, BITS> aBitArray, std::array<int, BITS> bBitArray) {
    // Reset data from previous computation
    for (auto &arr: data) {
        arr.fill(0);
    }

    data[0][0] = 0;
    for (std::size_t i = 1; i < BITS; ++i) {
        if (aBitArray[i - 1] == 1 && bBitArray[i - 1] == 1) {
            data[i][0] = 1;
        } else if (aBitArray[i - 1] != bBitArray[i - 1]) {
            data[i][0] = STAR;
        }
    }

    for (int k = 1; k < LOG_BITS + 1; ++k) {
        std::vector<std::future<void>> threads;
        threads.reserve(BITS);
        for (int i = 0; i < BITS; ++i) {
            threads.push_back(std::async(std::launch::async, [i, k, this]() {
                recurrence(i, k);
            }));
        }

        for (auto &future: threads) {
            future.wait();
        }
    }

    int a = utils::bitArrayToInt(aBitArray);    // in case a originally had more than BITS bits
    int b = utils::bitArrayToInt(bBitArray);
    int c = 0;
    for (int i = 0; i < BITS; ++i) {
        c += data[i][LOG_BITS] * (int) pow(2, i);
    }

    return a ^ b ^ c;
}

template<int BITS>
void AddTwoIntegersAlgorithm<BITS>::recurrence(int i, int k) {
    if (data[i][k - 1] != STAR) {
        data[i][k] = data[i][k - 1];
    } else {
        int q = i - (int) pow(2, k - 1);
        data[i][k] = data[q][k - 1];
    }
}

#endif //PARALLELALGORITHMS_ADDTWOINTEGERSALGORITHM_H
