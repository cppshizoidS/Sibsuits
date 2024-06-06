#pragma once

#include <iostream>
#include <random>

template <typename T> void fillInc(T &arr, std::size_t len) {
    for (std::size_t i = 0; i < len; i++)
        arr[i] = i;
}

template <typename T> void fillDec(T &arr, std::size_t len) {
    for (std::size_t i = 0; i < len; i++)
        arr[i] = len - i - 1;
}

template <typename T> void fillRand(T &arr, std::size_t len) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 100);
    for (std::size_t i = 0; i < len; i++)
        arr[i] = dist(gen);
}

template <typename T> T checkSum(const T &arr, std::size_t len) {
    T sum = 0;
    for (std::size_t i = 0; i < len; i++)
        sum += arr[i];
    return sum;
}

template <typename T> std::size_t runNumber(const T &arr, std::size_t len) {
    std::size_t n = 1;
    for (std::size_t i = 1; i < len; i++)
        if (arr[i] < arr[i - 1])
            n++;
    return n;
}

template <typename T> void printMas(const T &arr, std::size_t len) {
    for (std::size_t i = 0; i < len; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}