#include <ctype.h>
#include <stdlib.h>

#include <libgeometry/geom_parser.h>
#include <libgeometry/lexer.h>

void print_error(int column, int status, int is_file, FILE* file)
{
    if (is_file == _FILE) {
        char temp[256];
        fseek(file, -column - 1, SEEK_CUR);
        fgets(temp, 255, file);
        printf("\n%s\n", temp);
    }

    for (int i = 0; i < column; i++) {
        putchar(' ');
    }

    printf(RED_COLOR("^") "\n");
    switch (status) {
    case ER_NAME:
        printf(RED_COLOR("Error") " at column %d: ", column);
        printf(RED_COLOR("expected 'circle' or 'triangle'") "\n");
        break;
    case ER_NOT_DOUBLE:
        printf(RED_COLOR("Error") " at column %d: ", column);
        printf(RED_COLOR("expected '<double>'") "\n");
        break;
    case ER_R_PARENTNESIS:
        printf(RED_COLOR("Error") " at column %d: ", column);
        printf(RED_COLOR("expected ')'") "\n");
        break;
    case ER_UNEXPECT_TOKEN:
        printf(RED_COLOR("Error") " at column %d: ", column);
        printf(RED_COLOR("unexpected token") "\n");
        break;
    case ER_EXPECT_COMMA:
        printf(RED_COLOR("Error") " at column %d: ", column);
        printf(RED_COLOR("expected ','") "\n");
        break;
    case ER_UNEXPECT_COMMA:
        printf(RED_COLOR("Error") " at column %d: ", column);
        printf(RED_COLOR("unexpected ','") "\n");
        break;
    case ER_NEGATIVE_R:
        printf(RED_COLOR("Error") " at column %d: ", column);
        printf(RED_COLOR("radius must be positive") "\n");
        break;
    }
    exit(EXIT_FAILURE);
}

void to_lower_string(char* string)
{
    while (*string != '\0') {
        *string = tolower(*string);
        string++;
    }
}

void del_space(int* column, FILE* file)
{
    char ch;
    while ((ch = getc(file)) == ' ') {
        *column += 1;
    }
    ungetc(ch, file);
}

int count_char(char ch, char exp_ch, int* cnt)
{
    if (ch == exp_ch)
        *cnt += 1;
    return *cnt;
}

bool unexpect_char(char ch, char unexpected, FILE* file)
{
    if (ch == unexpected) {
        ungetc(ch, file);
        return true;
    }
    return false;
}

int read_str_number(char temp[], int* column, FILE* file)
{
    char ch;
    int point_count = 0, minus_count = 0, i = 0;
    while ((ch = getc(file)) != ' ' && i < NUM_LEN) {
        temp[i] = ch;

        if (count_char(temp[i], '.', &point_count) == 2) {
            *column += i + 1;
            return ER_NOT_DOUBLE;
        }

        if (count_char(temp[i], '-', &minus_count) == 2) {
            *column += i + 1;
            return ER_NOT_DOUBLE;
        }

        if (unexpect_char(temp[i], ')', file) == true)
            break;

        if (unexpect_char(temp[i], ',', file) == true)
            break;

        if (temp[i] == '(') {
            *column += i;
            return ER_R_PARENTNESIS;
        }

        if (!isdigit(temp[i]) && temp[i] != '.' && temp[i] != '-') {
            *column += i;
            return ER_NOT_DOUBLE;
        }
        i++;
    }
    if (ch == ' ')
        i++;
    *column += i;
    return 0;
}

double get_number(int* column, int is_file, FILE* file)
{
    char temp[NUM_LEN] = {0};
    del_space(column, file);

    int result = read_str_number(temp, column, file);
    switch (result) {
    case ER_R_PARENTNESIS:
        print_error(*column, ER_R_PARENTNESIS, is_file, file);
        break;
    case ER_NOT_DOUBLE:
        print_error(*column, ER_NOT_DOUBLE, is_file, file);
        break;
    default:
        del_space(column, file);
        break;
    }
    return strtod(temp, NULL);
}

bool expect(char expect, int* column, int status, int is_file, FILE* file)
{
    char ch;
    if ((ch = getc(file)) == expect) {
        *column += 1;
        return true;
    } else {
        if (is_file == _FILE)
            print_error(*column, status, _FILE, file);
        else
            print_error(*column - 1, status, NOT_FILE, file);
    }
    return false;
}

bool unexpect(char unexpect, int* column, int status, int is_file, FILE* file)
{
    char ch;
    if ((ch = getc(file)) == unexpect)
        print_error(*column, status, is_file, file);

    ungetc(ch, file);
    return true;
}

void get_point(Point* point, int* column, int is_file, FILE* file)
{
    point->x = get_number(column, is_file, file);
    unexpect(',', column, ER_UNEXPECT_COMMA, is_file, file);

    point->y = get_number(column, is_file, file);
}

void end_of_line(int* column, int is_file, FILE* file)
{
    char ch;
    while ((ch = getc(file)) != '\n' && ch != EOF) {
        if (ch != ' ')
            print_error(*column, ER_UNEXPECT_TOKEN, is_file, file);

        *column += 1;
    }
}