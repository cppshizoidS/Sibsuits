//
// Created by cppshizoid on 11.09.23.
//
#include <stdio.h>

int main() {
    int age;

    printf("enter your age: ");
    scanf("%d", age);

    //if (age > 18) {
    //    age += 100;
    // } else {
    //    age -= 100;
    //}

    age = age > 18 ? 100000 : -10000;
    printf("%d", age);

    return 0;
}