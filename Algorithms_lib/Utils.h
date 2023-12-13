#ifndef PARALLELALGORITHMS_UTILS_H
#define PARALLELALGORITHMS_UTILS_H

#include <array>
#include <iostream>

namespace utils {

    /**
     * Given a non-negative integer val, returns an array a such that
     * a[i] = b_i, where val equals b_0 b_1... in binary (b_0 is least significant).
     * Note that the returned array omits bits b_n and beyond.
     * */
    template<std::size_t N>
    std::array<int, N> intToBitArray(int val);

    template<std::size_t N>
    int bitArrayToInt(std::array<int, N> arr);

    constexpr int logBits(int bits) {
        return (bits <= 1) ? 0 :
               (bits <= 2) ? 1 :
               (bits <= 4) ? 2 :
               (bits <= 8) ? 3 :
               (bits <= 16) ? 4 :
               (bits <= 32) ? 5 :
               (bits <= 64) ? 6 : 7;
    }

    template<std::size_t N>
    std::array<int, N> shiftBitArray(const std::array<int, N> &bitArray, int shift);

}

template<std::size_t N>
std::array<int, N> utils::intToBitArray(int val) {
    std::array<int, N> result{};
    std::string binary = std::bitset<N>(val).to_string();
    for (int i = 0; i < N; ++i) {
        if (binary[N - 1 - i] == '1') {
            result[i] = 1;
        }
    }

    return result;
}

template<std::size_t N>
int utils::bitArrayToInt(std::array<int, N> arr) {
    int result = 0;
    for (int i = 0; i < N; ++i) {
        if (arr[i] == 1) {
            result |= 1 << i;
        }
    }

    return result;
}

template<std::size_t N>
std::array<int, N> utils::shiftBitArray(const std::array<int, N> &bitArray, int shift) {
    std::array<int, N> result{};
    for (int i = shift; i < N; ++i) {
        result[i] = bitArray[i - shift];
    }

    return result;
}

#endif //PARALLELALGORITHMS_UTILS_H
