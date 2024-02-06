#include "my_is_same.hpp"

template<typename T, typename U>
concept SameAs = my_is_same::is_same_v<T,U>;

