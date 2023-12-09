#ifndef PARALLELALGORITHMS_UTILS_H
#define PARALLELALGORITHMS_UTILS_H

#include <array>
#include <iostream>

template<typename T, std::size_t I, std::size_t J>
void printArray(const std::array<std::array<T, I>, J> &arr) {
    std::for_each(arr.begin(), arr.end(), [](std::array<T, I> a) {
        std::for_each(a.begin(), a.end(), [](T t) {
            std::cout << t << " ";
        });
        std::cout << std::endl;
    });
}

template<typename T, std::size_t N>
void printArray(const std::array<T, N> &arr) {
    std::for_each(arr.begin(), arr.end(), [](T t) {
        std::cout << t << " ";
    });
    std::cout << std::endl;
}

template<typename T, std::size_t I, std::size_t J>
std::ostream& operator<< (std::ostream &out, const std::array<std::array<T, I>, J> &arr) {
    std::for_each(arr.begin(), arr.end(), [](std::array<T, I> a) {
        std::for_each(a.begin(), a.end(), [](T t) {
            std::cout << t << " ";
        });
        std::cout << std::endl;
    });
    return out;
}

template<typename T, std::size_t N>
std::ostream& operator<< (std::ostream &out, const std::array<T, N> & arr) {
    std::for_each(arr.begin(), arr.end(), [](T t) {
        std::cout << t << " ";
    });
    std::cout << std::endl;
    return out;
}

template<std::size_t N>
std::array<int, N> intToBitArray(int val) {
    std::array<int, N> result{};
    std::string binary = std::bitset<N>(val).to_string();
    for (int i = 0; i < N; ++i) {
        if (binary[i] == '1') {
            result[i] = 1;
        }
    }

    return result;
}

constexpr int logBits(int bits) {
    return (bits < 2) ? 1 :
           (bits < 4) ? 2 :
           (bits < 8) ? 3 :
           (bits < 16) ? 4 :
           (bits < 32) ? 5 :
           (bits < 64) ? 6 : 7;
}

#endif //PARALLELALGORITHMS_UTILS_H
