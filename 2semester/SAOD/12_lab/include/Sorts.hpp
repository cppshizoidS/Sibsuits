#pragma once

#include "Lists.hpp"

#include <cmath>
#include <cstddef>
#include <vector>

template <typename T> std::size_t selectSort(T &arr, std::size_t len) {
    std::size_t m = 0, c = 0;
    for (std::size_t i = 0; i < len - 1; i++) {
        int snp = i;
        for (std::size_t j = i + 1; j < len; j++) {
            if (arr[j] < arr[snp])
                snp = j;
            c++;
        }
        std::swap(arr[i], arr[snp]);
        m += 3;
    }
    return m + c;
}

template <typename T> std::size_t bubbleSort(T &arr, std::size_t len) {
    std::size_t m = 0, c = 0;
    for (std::size_t i = 0; i < len; i++) {
        for (std::size_t j = 1; j < len - i; j++) {
            if (arr[j] < arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
                m += 3;
            }
            c++;
        }
    }
    return m + c;
}

template <typename T> std::size_t shakerSort(T &arr, std::size_t len) {
    std::size_t L = 0, R = len - 1, k = len - 1;
    std::size_t m = 0, c = 0;
    do {
        for (std::size_t j = R; j > L; j--) {
            if (arr[j] < arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
                m += 3;
                k = j;
            }
            c++;
        }
        L = k;
        for (std::size_t j = L; j < R; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                m += 3;
                k = j;
            }
            c++;
        }
        R = k;
    } while (L < R);
    return m + c;
}

template <typename T> std::size_t insertSort(T &arr, std::size_t len) {
    std::size_t m = 0, c = 0;
    for (std::size_t i = 1; i < len; i++) {
        bool f = true;
        auto t = arr[i];
        long long j = i - 1;
        while (j > -1 and t < arr[j]) {
            f = false;
            arr[j + 1] = arr[j];
            j--;
            c++;
            m++;
        }
        if (f)
            c++;
        arr[j + 1] = t;
        m += 2;
    }
    return m + c;
}

template <typename T> std::size_t shellSort(T &arr, std::size_t len) {
    std::size_t m = 0, c = 0;
    std::size_t M = (int)std::log2(len) - 1;
    std::vector<int> h(M);
    h[0] = 1;
    for (int i = 1; i < M; i++)
        h[i] = 2 * h[i - 1] + 1;
    for (int a = M - 1; a >= 0; a--) {
        for (std::size_t i = h[a]; i < len; i++) {
            bool f = true;
            for (int j = i - h[a]; j >= 0 and arr[j] > arr[j + h[a]]; j -= h[a]) {
                std::swap(arr[j], arr[j + h[a]]);
                m += 3;
                f = false;
                c++;
            }
            if (f)
                c++;
        }
    }
    return m + c;
}

template <class T, class C> std::size_t shellSort(T &arr, std::size_t len, C commpare) {
    std::size_t m = 0, c = 0;
    std::size_t M = (int)std::log2(len) - 1;
    std::vector<int> h(M);
    h[0] = 1;
    for (int i = 1; i < M; i++)
        h[i] = 2 * h[i - 1] + 1;
    for (int a = M - 1; a >= 0; a--) {
        for (std::size_t i = h[a]; i < len; i++) {
            bool f = true;
            for (int j = i - h[a]; j >= 0 and commpare(arr[j], arr[j + h[a]]); j -= h[a]) {
                std::swap(arr[j], arr[j + h[a]]);
                m += 3;
                f = false;
                c++;
            }
            if (f)
                c++;
        }
    }
    return m + c;
}

template <typename T> void buildHeap(T &arr, std::size_t l, std::size_t r, std::size_t &m, std::size_t &c) {
    auto x = arr[l];
    std::size_t i = l;
    while (true) {
        std::size_t j = 2 * i;
        if (j > r)
            break;
        if (j < r and arr[j + 1] <= arr[j])
            j++;
        c++;
        if (x <= arr[j]) {
            c++;
            break;
        }
        c++;
        arr[i] = arr[j];
        m++;
        i = j;
    }
    arr[i] = x;
    m += 2;
}

template <typename T> std::size_t heapSort(T &arr, std::size_t len) {
    std::size_t m = 0, c = 0;
    for (long long l = len / 2; l >= 0; l--)
        buildHeap(arr, l, len - 1, m, c);
    std::size_t r = len - 1;
    while (r > 0) {
        std::swap(arr[0], arr[r--]);
        m += 3;
        buildHeap(arr, 0, r, m, c);
    }
    return m + c;
}

template <typename T> int hoaraSort(T &arr, int left, int right, std::size_t &m, std::size_t &c) {
    auto pivo = arr[(left + right) / 2];
    m++;
    while (left <= right) {
        c += 2;
        while (arr[left] < pivo) {
            left++;
            c++;
        }
        while (arr[right] > pivo) {
            right--;
            c++;
        }
        if (left <= right) {
            std::swap(arr[left++], arr[right--]);
            m += 3;
        }
    }
    return left;
}

template <typename T> void quickSort(T &arr, int start, int end, std::size_t &m, std::size_t &c) {
    if (start >= end)
        return;
    int rightStart = hoaraSort(arr, start, end, m, c);
    quickSort(arr, start, rightStart - 1, m, c);
    quickSort(arr, rightStart, end, m, c);
}

template <typename T> std::size_t quickSort(T &arr, std::size_t len) {
    std::size_t m = 0, c = 0;
    quickSort(arr, 0, len - 1, m, c);
    return m + c;
}

template <typename T> std::size_t merge(list<T> &a, std::size_t size_a, list<T> &b, std::size_t size_b, queue<T> &c) {
    std::size_t move_copare = 0;

    while (size_a > 0 and size_b > 0) {
        if (a(0) <= b(0)) {
            c.push(a.pop_front());
            size_a--;
        } else {
            c.push(b.pop_front());
            size_b--;
        }
        move_copare += 2;
    }
    while (size_a > 0) {
        c.push(a.pop_front());
        size_a--;
        move_copare++;
    }
    while (size_b > 0) {
        c.push(b.pop_front());
        size_b--;
        move_copare++;
    }

    return move_copare;
}

template <typename T> void split(const list<T> &s, list<T> &a, list<T> &b) {
    if (s.is_empty())
        return;

    bool f = true;
    for (std::size_t i = 0; i < s.get_size(); i++) {
        if (f)
            a.push_back(s(i));
        else
            b.push_back(s(i));
        f = !f;
    }
}

template <typename T> std::size_t mergeSort(list<T> &s) {
    std::size_t move_copare = 0;

    list<T> a, b;
    queue<T> c[2];

    split(s, a, b);

    std::size_t p = 1;
    std::size_t q = 0;
    std::size_t r = 0;

    while (p < s.get_size()) {
        c[0].clear();
        c[1].clear();

        int i = 0;
        std::size_t m = s.get_size();
        while (m > 0) {
            if (m >= p)
                q = p;
            else
                q = m;
            m -= q;
            if (m >= p)
                r = p;
            else
                r = m;
            m -= r;

            move_copare += merge(a, b, c[i]);
            i = 1 - i;
        }

        a.copy(c[0]);
        b.copy(c[1]);
        p *= 2;
    }

    s.copy(c[0]);

    return move_copare;
}

template <typename T> std::size_t digitalSort(list<T> &list_) {
    std::size_t m = 0;
    int count_of_queue = 256;

    for (std::size_t i = 0; i < sizeof(T); i++) {
        queue<T> Q[count_of_queue];

        for (std::size_t j = 0; j < list_.get_size(); j++) {
            int index = (list_(j) / (int)std::pow(count_of_queue, i)) % count_of_queue;
            m++;
            Q[index].push(list_(j));
        }

        list_.clear();
        for (int j = count_of_queue - 1; j >= 0; j--) {
            list_ += Q[j];
            m++;
        }
    }

    return m;
}