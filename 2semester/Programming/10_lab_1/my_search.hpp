#ifndef MY_SEARCH_HPP
#define MY_SEARCH_HPP

template <typename ForwardIt1, typename ForwardIt2>
ForwardIt1 my_search(ForwardIt1 first1, ForwardIt1 last1,
                         ForwardIt2 first2, ForwardIt2 last2) {
    while (first1 != last1) {
        ForwardIt1 it1 = first1;
        ForwardIt2 it2 = first2;

        while (*it1 == *it2) {
            ++it1;
            ++it2;

            if (it2 == last2) {
                // Found a match
                return first1;
            }

            if (it1 == last1) {
                // Reached the end of the first range
                return last1;
            }
        }

        ++first1;
    }

    // No match found
    return last1;
}

#endif