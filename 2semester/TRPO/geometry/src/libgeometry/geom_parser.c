#include <inttypes.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/calculate.h>
#include <libgeometry/geom_parser.h>
#include <libgeometry/intersect.h>
#include <libgeometry/lexer.h>

void take_info_circle(Circle* circle, int* column, int is_file, FILE* file)
{
    get_point(&circle->point, column, is_file, file);
    expect(',', column, ER_EXPECT_COMMA, is_file, file);

    circle->radius = get_number(column, is_file, file);

    if (circle->radius < 0 || circle->radius == -0) {
        print_error(*column - 2, ER_NEGATIVE_R, is_file, file);
        exit(EXIT_FAILURE);
    }

    expect(')', column, ER_R_PARENTNESIS, is_file, file);

    end_of_line(column, is_file, file);

    circle_calculate(circle);
}

void show_info_circle(Circle* circle)
{
    printf("%d. %s(%.2f %.2f, %.2f)\n",
           circle->number,
           circle->name,
           circle->point.x,
           circle->point.y,
           circle->radius);
    printf("\tarea = %.4f\n", circle->area);
    printf("\tperimeter = %.4f\n", circle->perimeter);
}

void take_info_triangle(Triangle* tr, int* column, int is_file, FILE* file)
{
    expect('(', column, ER_R_PARENTNESIS, is_file, file);
    get_point(&tr->p1, column, is_file, file);
    expect(',', column, ER_EXPECT_COMMA, is_file, file);
    get_point(&tr->p2, column, is_file, file);
    expect(',', column, ER_EXPECT_COMMA, is_file, file);
    get_point(&tr->p3, column, is_file, file);
    expect(',', column, ER_EXPECT_COMMA, is_file, file);
    get_point(&tr->p4, column, is_file, file);
    expect(')', column, ER_R_PARENTNESIS, is_file, file);
    expect(')', column, ER_R_PARENTNESIS, is_file, file);

    end_of_line(column, is_file, file);

    triangle_calculate(tr);
}

void show_info_triangle(Triangle* tr)
{
    printf("%d. %s((%.1f %.1f, %.1f %.1f, %.1f %.1f, %.1f %.1f))\n",
           tr->number,
           tr->name,
           tr->p1.x,
           tr->p1.y,
           tr->p2.x,
           tr->p2.y,
           tr->p3.x,
           tr->p3.y,
           tr->p4.x,
           tr->p4.y);
    printf("\tarea = %.3f\n", tr->area);
    printf("\tperimeter = %.3f\n", tr->perimeter);
}

Circle
circle_process(char* geom, int* column, int is_file, FILE* file, int number)
{
    Circle circle = {.number = number};
    strcpy(circle.name, geom);
    take_info_circle(&circle, column, is_file, file);
    return circle;
}

Triangle
triangle_process(char* geom, int* column, int is_file, FILE* file, int number)
{
    Triangle triangle = {.number = number};
    strcpy(triangle.name, geom);
    take_info_triangle(&triangle, column, is_file, file);
    return triangle;
}

int read_str(int* column, char ch, char geom[], FILE* file)
{
    *column = 0;
    do {
        if (ch == '(' || ch == ' ') {
            return END_OF_NAME;
        }
        if (ch == ')')
            return ER_R_PARENTNESIS;

        geom[*column] = ch;
        *column += 1;
    } while ((ch = getc(file)) != '\n');
    return ER_NAME;
}

void str_clear(char* str, size_t size)
{
    for (int i = 0; i < size; i++)
        str[i] = '\0';
}

void print_itersect_circles(Circle* circle, Circle arr[], int ci_cnt, int j)
{
    for (int i = 0; i < ci_cnt; i++) {
        if (j == i)
            continue;
        if (is_intersect_circles(*circle, arr[i]))
            printf("\t%d. %s\n", arr[i].number, arr[i].name);
    }
}

void print_itersect_circle_tr(Circle* circle, Triangle arr[], int tr_cnt)
{
    for (int i = 0; i < tr_cnt; i++) {
        if (is_intersect_circle_triangle(*circle, arr[i]))
            printf("\t%d. %s\n", arr[i].number, arr[i].name);
    }
}

void print_itersect_triangles(Triangle* tr, Triangle arr[], int tr_cnt, int j)
{
    for (int i = 0; i < tr_cnt; i++) {
        if (i == j)
            continue;
        if (is_intersect_triangles(*tr, arr[i]))
            printf("\t%d. %s\n", arr[i].number, arr[i].name);
    }
}

void print_intersect_tr_circle(Triangle* tr, Circle arr[], int ci_cnt)
{
    for (int i = 0; i < ci_cnt; i++) {
        if (is_intersect_circle_triangle(arr[i], *tr))
            printf("\t%d. %s\n", arr[i].number, arr[i].name);
    }
}

void print_output(
        Circle circles[],
        Triangle trs[],
        uint8_t arr[],
        int tr_cnt,
        int cir_cnt)
{
    for (int i = 1, k = 0, m = 0; i <= tr_cnt + cir_cnt; i++) {
        if (arr[i] == CIRCLE) {
            show_info_circle(&circles[k]);
            printf("\tintersects:\n");
            print_itersect_circles(&circles[k], circles, cir_cnt, k);
            print_itersect_circle_tr(&circles[k], trs, tr_cnt);
            printf("\n");
            k++;
        } else if (arr[i] == TRIANGLE) {
            show_info_triangle(&trs[m]);
            printf("\tintersects:\n");
            print_itersect_triangles(&trs[m], trs, tr_cnt, m);
            print_intersect_tr_circle(&trs[m], circles, cir_cnt);
            printf("\n");
            m++;
        }
    }
}

void parser(FILE* file, int is_file)
{
    char geom[NAME_SIZE] = {0};
    Circle circles[N_CIRCLE];
    Triangle triangles[N_TRIANGLE];
    uint8_t arr[N_CIRCLE + N_TRIANGLE] = {0};
    char ch;
    int column, c_cnt = 0, tr_cnt = 0, cnt = 1;

    if (is_file == NOT_FILE)
        puts("Enter a geometric shape (or q for exit):");

    while ((ch = getc(file)) != EOF && ch != 'q') {
        int result = read_str(&column, ch, geom, file);
        if (result == END_OF_NAME) {
            to_lower_string(geom);
            column++;
            if (strcmp(geom, "circle") == 0) {
                if (c_cnt > N_CIRCLE) {
                    printf("The maximum number of circles has been entered\n");
                    continue;
                }
                circles[c_cnt++]
                        = circle_process(geom, &column, is_file, file, cnt);
                arr[cnt++] = CIRCLE;
            } else if (strcmp(geom, "triangle") == 0) {
                if (tr_cnt > N_TRIANGLE) {
                    printf("The maximum number of triangles has been "
                           "entered\n");
                    continue;
                }
                triangles[tr_cnt++]
                        = triangle_process(geom, &column, is_file, file, cnt);
                arr[cnt++] = TRIANGLE;
            } else
                print_error(0, ER_NAME, is_file, file);
        } else if (result == ER_R_PARENTNESIS) {
            print_error(column, ER_R_PARENTNESIS, is_file, file);
        } else {
            print_error(0, ER_NAME, is_file, file);
        }

        str_clear(geom, NAME_SIZE);

        if (is_file == NOT_FILE)
            puts("Enter a new geometric shape (or q for exit):");
    }

    print_output(circles, triangles, arr, tr_cnt, c_cnt);
}
