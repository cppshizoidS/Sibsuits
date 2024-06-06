#pragma once

#include <cstddef>
#include <cstdint>

template <typename T> long long BinarySearch1(const T &arr, std::size_t len, const T &x, std::size_t &count_of_compares) {
    count_of_compares = 0;
    std::size_t left = 0, right = len - 1;

    while (left <= right) {
        std::size_t middle = (left + right) / 2;
        count_of_compares++;
        if (arr[middle] == x)
            return (int64_t)middle;

        if (arr[middle] < x)
            left = middle + 1;
        else
            right = middle - 1;
        count_of_compares++;
    }

    return -1;
}

template <typename T> int64_t BinarySearch2(const T &arr, std::size_t len, const T &x, std::size_t &count_of_compares) {
    count_of_compares = 0;
    std::size_t left = 0, right = len - 1;

    while (left < right) {
        std::size_t middle = (left + right) / 2;
        if (arr[middle] < x)
            left = middle + 1;
        else
            right = middle;
        count_of_compares++;
    }

    count_of_compares++;
    if (arr[right] == x)
        return static_cast<int64_t>(right);
    return -1;
}
