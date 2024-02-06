#include <cstddef>
#include <type_traits>
namespace is_array {
template<class T>
struct is_array : std::false_type {};

template<class T, std::size_t N>
struct is_array<T[N]> : std::true_type {};

template<class T>
struct is_array<T[]> : std::true_type {};

}