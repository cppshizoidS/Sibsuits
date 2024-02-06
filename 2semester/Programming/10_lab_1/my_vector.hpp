#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <algorithm>
#include <cstring>
#include <stdexcept>
#include "my_copy.hpp"
#include "my_swap.hpp"

namespace my_vector {

template <typename T> class my_vector {
public:
  using size_type = std::size_t;
  using iterator = T *;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const iterator>;

  constexpr my_vector() noexcept : m_data(nullptr), m_size(0), m_capacity(0) {}

  constexpr my_vector(size_type count, const T &value)
      : m_size(count), m_capacity(count) {
    m_data = new T[m_capacity];
    std::fill_n(m_data, m_size, value);
  }

  template <typename InputIt>
  constexpr my_vector(InputIt first, InputIt last)
      : m_size(last - first), m_capacity(last - first) {
    m_data = new T[m_capacity];
    my_copy(first, last, m_data);
  }

  constexpr my_vector(const my_vector &other)
      : m_size(other.m_size), m_capacity(other.m_capacity) {
    m_data = new T[m_capacity];
    my_copy(other.m_data, other.m_data + other.m_size, m_data);
  }

  constexpr my_vector &operator=(const my_vector &other) noexcept {
    if (this != &other) {
      delete[] m_data;
      m_size = other.m_size;
      m_capacity = other.m_capacity;
      m_data = new T[m_capacity];
      my_copy(other.m_data, other.m_data + other.m_size, m_data);
    }
    return *this;
  }

  ~my_vector() { delete[] m_data; }

  constexpr void push_back(const T &value) {
    if (m_size == m_capacity) {
      reserve(m_capacity == 0 ? 1 : m_capacity * 2);
    }
    m_data[m_size++] = value;
  }

  constexpr void pop_back() {
    if (m_size > 0) {
      --m_size;
    }
  }

  constexpr void resize(size_type count, const T &value) {
    if (count > m_capacity) {
      reserve(count);
    }
    if (count > m_size) {
      std::fill(m_data + m_size, m_data + count, value);
    }
    m_size = count;
  }

  constexpr void reserve(size_type new_capacity) {
    if (new_capacity > m_capacity) {
      T *new_data = new T[new_capacity];
      my_copy(m_data, m_data + m_size, new_data);
      delete[] m_data;
      m_data = new_data;
      m_capacity = new_capacity;
    }
  }

  constexpr void emplace_back(T &&value) {
    if (m_size == m_capacity) {
      reserve(m_capacity == 0 ? 1 : m_capacity * 2);
    }
    m_data[m_size++] = my_move(value);
  }

  constexpr void shrink_to_fit() {
    if (m_capacity > m_size) {
      reserve(m_size);
    }
  }

  [[nodiscard]] constexpr size_type size() const noexcept { return m_size; }

  [[nodiscard]] constexpr bool empty() const noexcept { return m_size == 0; }

  constexpr T &operator[](size_type pos) {
    if (pos >= m_size) {
      throw std::out_of_range("Index out of range");
    }
    return m_data[pos];
  }

  [[nodiscard]] constexpr const T &operator[](size_type pos) const {
    if (pos >= m_size) {
      throw std::out_of_range("Index out of range");
    }
    return m_data[pos];
  }

  [[nodiscard]] constexpr iterator begin() const noexcept { return m_data; }

  [[nodiscard]] constexpr iterator end() const noexcept {
    return m_data + m_size;
  }

  [[nodiscard]] constexpr reverse_iterator rbegin() noexcept {
    return reverse_iterator(end());
  }

  [[nodiscard]] constexpr reverse_iterator rend() noexcept {
    return reverse_iterator(begin());
  }

  [[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept {
    return const_reverse_iterator(end());
  }

  [[nodiscard]] constexpr const_reverse_iterator rend() const noexcept {
    return const_reverse_iterator(begin());
  }

  constexpr void swap(my_vector &other) noexcept {
    my_swap(m_data, other.m_data);
    my_swap(m_size, other.m_size);
    my_swap(m_capacity, other.m_capacity);
  }

private:
  T *m_data;
  size_type m_size;
  size_type m_capacity;
};

template <typename T>
[[nodiscard]] constexpr bool operator==(const my_vector<T> &lhs,
                                        const my_vector<T> &rhs) {
  if (lhs.size() == rhs.size()) {
    for (std::size_t idx = 0; idx < lhs.size(); ++idx) {
      if (lhs[idx] != rhs[idx]) {
        return false;
      }
    }
    return true;
  }
  return false;
}

} // namespace my_vector

#endif // MY_VECTOR_HPP
