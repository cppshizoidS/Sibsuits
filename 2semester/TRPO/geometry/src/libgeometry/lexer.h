#pragma once
#include <stdbool.h>
#include <stdio.h>

#define RED_COLOR(X) "\e[1;31m" X "\e[0m"
#define MAGENTA_COLOR(X) "\e[1;35m" X "\e[0m"
#define NUM_LEN 25

enum Errors {
    END_OF_NAME,
    _FILE,
    NOT_FILE,
    ER_NAME,
    ER_NOT_DOUBLE,
    ER_R_PARENTNESIS,
    ER_UNEXPECT_TOKEN,
    ER_EXPECT_COMMA,
    ER_UNEXPECT_COMMA,
    ER_NEGATIVE_R
};

bool unexpect_char(char ch, char unexpected, FILE* file);
int read_str_number(char temp[], int* column, FILE* file);
int count_char(char ch, char exp_ch, int* cnt);
void print_error(int column, int status, int is_file, FILE* file);
void to_lower_string(char* string);
void del_space(int* column, FILE* file);
double get_number(int* column, int is_file, FILE* file);
bool expect(char expect, int* column, int status, int is_file, FILE* file);
bool unexpect(char unexpect, int* column, int status, int is_file, FILE* file);
void end_of_line(int* column, int is_file, FILE* file);
void get_point(Point* point, int* column, int is_file, FILE* file);