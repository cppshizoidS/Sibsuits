namespace my_is_same {

    template<typename T, typename U>
    struct is_same {
        static constexpr bool value = false;
    };

    template<typename T>
    struct is_same<T, T> {
        static constexpr bool value = true;
    };

    template<typename T, typename U>
    inline constexpr bool is_same_v = is_same<T, U>::value;

}