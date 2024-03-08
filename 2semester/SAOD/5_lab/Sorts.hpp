#ifndef SORTS_HPP
#define SORTS_HPP

#include <cmath>
#include <cstddef>
#include <iostream>

#include "ArrFunc.hpp"

template <typename T> void Swap(T &x, T &y) {
  int temp = x;
  x = y;
  y = temp;
}

template <typename T> void PrintArr(T &A, size_t len, size_t m, size_t c) {
  std::cout << "Sort array: ";
  PrintMas(A, len);
  std::cout << "Move: " << m << std::endl;
  std::cout << "Compare: " << c << std::endl;
}

template <typename T> size_t SelectSort(T &A, size_t len) {
  size_t m = 0, c = 0;
  for (size_t i = 0; i < len - 1; i++) {
    int snp = i;
    for (size_t j = i + 1; j < len; j++) {
      if (A[j] < A[snp])
        snp = j;
      c++;
    }
    Swap(A[i], A[snp]);
    m += 3;
  }
  return m + c;
}

template <typename T> size_t BubbleSort(T &A, size_t len) {
  size_t m = 0, c = 0;
  for (size_t i = 0; i < len; i++) {
    for (size_t j = 1; j < len - i; j++) {
      if (A[j] < A[j - 1]) {
        Swap(A[j], A[j - 1]);
        m += 3;
      }
      c++;
    }
  }
  return m + c;
}

template <typename T> size_t ShakerSort(T &A, size_t len) {
  size_t L = 0, R = len - 1, k = len - 1;
  size_t m = 0, c = 0;
  do {
    for (size_t j = R; j > L; j--) {
      if (A[j] < A[j - 1]) {
        Swap(A[j], A[j - 1]);
        m += 3;
        k = j;
      }
      c++;
    }
    L = k;
    for (size_t j = L; j < R; j++) {
      if (A[j] > A[j + 1]) {
        Swap(A[j], A[j + 1]);
        m += 3;
        k = j;
      }
      c++;
    }
    R = k;
  } while (L < R);
  return m + c;
}

template <typename T> size_t InsertSort(T &A, size_t len) {
  size_t m = 0, c = 0;
  for (size_t i = 1; i < len; i++) {
    bool f = true;
    auto t = A[i];
    long long j = i - 1;
    while (j > -1 and t < A[j]) {
      f = false;
      A[j + 1] = A[j];
      j--;
      c++;
      m++;
    }
    if (f)
      c++;
    A[j + 1] = t;
    m += 2;
  }
  return m + c;
}

template <typename T> size_t ShellSort(T &A, size_t len) {
  bool F = true;
  size_t m = 0, c = 0;
  int M = static_cast<int>(std::log2(len)) - 1;
  int h[M];
  h[0] = 1;
  for (int i = 1; i < M; i++)
    h[i] = 2 * h[i - 1] + 1;
  for (int a = M - 1; a >= 0; a--) {
    for (size_t i = h[a]; i < len; i++) {
      bool f = true;
      for (int j = i - h[a]; j >= 0 and A[j] > A[j + h[a]]; j -= h[a]) {
        Swap(A[j], A[j + h[a]]);
        m += 3;
        f = false;
        c++;
      }
      if (f)
        c++;
    }
  }

  if (F) {
    printf("|%d ", M);
    for (int i = 0; i < M; i++)
      printf(" %d", h[i]);

    if (M < 6)
      printf("       ");
    else if (M < 7)
      printf("    ");

    F = false;
  }

  return m + c;
}

#endif // SORTS_HPP
