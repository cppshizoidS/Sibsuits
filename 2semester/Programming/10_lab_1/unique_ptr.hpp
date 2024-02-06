#include <cstddef>
#include <memory>
#include <type_traits>
#include <utility>
#include "is_array.hpp"
namespace my_unique_ptr {


template<typename Contained, typename Deleter = std::default_delete<Contained>>
class unique_ptr {
public:
    constexpr unique_ptr() noexcept = default;
    explicit constexpr unique_ptr(Contained* data) noexcept : data(data) {}
    constexpr unique_ptr(std::nullptr_t) noexcept {}

    ~unique_ptr() noexcept {
        reset();
    }

    constexpr unique_ptr(unique_ptr&& other) noexcept : data(std::exchange(other.data, nullptr)) {}
    /*hui*/
    constexpr unique_ptr& operator=(unique_ptr&& other) noexcept {
        if (this != &other) {
            reset();
            data = std::exchange(other.data, nullptr);
        }
        return *this;
    }

    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    template <typename NewDeleter>
    void set_deleter(NewDeleter&& d) noexcept {
        deleter = std::forward<NewDeleter>(d);
    }

    template<typename ArrayType = Contained, typename = std::enable_if<is_array::is_array<ArrayType>::value>>
    void reset() noexcept {
        deleter(data);
        data = nullptr;
    }

    void reset(Contained* newData) noexcept {
        reset();
        data = newData;
    }

    Contained* release() noexcept {
        auto released = data;
        data = nullptr;
        return released;
    }

    Contained* get() const noexcept {
        return data;
    }

    Contained& operator*() const noexcept {
        return *data;
    }

    Contained* operator->() const noexcept {
        return data;
    }

    explicit operator bool() const noexcept {
        return data != nullptr;
    }

private:
    Contained* data = nullptr;
    Deleter deleter;
};

// comparison operators
template <typename Contained1, typename Deleter1,
          typename Contained2, typename Deleter2>
bool operator==(const unique_ptr<Contained1, Deleter1>& lhs,
                const unique_ptr<Contained2, Deleter2>& rhs) {
    return lhs.get() == rhs.get();
}

template <typename Contained1, typename Deleter1,
          typename Contained2, typename Deleter2>
bool operator!=(const unique_ptr<Contained1, Deleter1>& lhs,
                const unique_ptr<Contained2, Deleter2>& rhs) {
    return lhs.get() != rhs.get();
};
}