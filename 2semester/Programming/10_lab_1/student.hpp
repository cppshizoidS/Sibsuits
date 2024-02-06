// Student.hpp
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "my_string.hpp"

struct Student {
    my_string::my_string<char> surname;
    int grades[4];

    Student(const my_string::my_string<char>& s, int g1, int g2, int g3, int g4)
        : surname(s) {
        grades[0] = g1;
        grades[1] = g2;
        grades[2] = g3;
        grades[3] = g4;
    }
};

#endif // STUDENT_HPP
