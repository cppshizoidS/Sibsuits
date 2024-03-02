#include "../include/geometry.h"
#include "../include/parser.h"
#include <stdio.h>
#include <string.h>

const int MAX_FIGURES = 10;
const int MAX_INPUT_LENGTH = 100;
const int MAX_VERTICES = 10;

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: %s <input_file_path>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    Figure figures[MAX_FIGURES];
    int num_figures = 0;

    char input[MAX_INPUT_LENGTH];
    while (fgets(input, sizeof(input), file) != NULL) {
        input[strcspn(input, "\n")] = '\0';

        if (strstr(input, "circle") != NULL) {
            if (num_figures < MAX_FIGURES) {
                figures[num_figures].type = CIRCLE;
                figures[num_figures].shape.circle = parse_circle(input);
                num_figures++;
            } else {
                printf("Maximum number of figures reached (%d)\n", MAX_FIGURES);
                break;
            }
        } else if (strstr(input, "triangle") != NULL) {
            if (num_figures < MAX_FIGURES) {
                figures[num_figures].type = TRIANGLE;
                figures[num_figures].shape.triangle = parse_triangle(input);
                num_figures++;
            } else {
                printf("Maximum number of figures reached (%d)\n", MAX_FIGURES);
                break;
            }
        } else if (strstr(input, "polygon") != NULL) {
            if (num_figures < MAX_FIGURES) {
                figures[num_figures].type = POLYGON;
                figures[num_figures].shape.polygon = parse_polygon(input);
                num_figures++;
            } else {
                printf("Maximum number of figures reached (%d)\n", MAX_FIGURES);
                break;
            }
        }
    }

    fclose(file);

    for (int i = 0; i < num_figures; ++i) {
        printf("%d. ", i + 1);

        switch (figures[i].type) {
        case CIRCLE:
            // Вывод информации о круге
            printf("circle(");
            printf("%.2f %.2f, %.2f)\n",
                   figures[i].shape.circle.center.x,
                   figures[i].shape.circle.center.y,
                   figures[i].shape.circle.radius);
            printf("  perimeter = %.4f\n",
                   circle_perimeter(figures[i].shape.circle));
            printf("  area = %.4f\n", circle_area(figures[i].shape.circle));
            break;

        case TRIANGLE:
            // Вывод информации о треугольнике
            printf("triangle((");
            for (int k = 0; k < 3; ++k) {
                printf("%.2f %.2f",
                       figures[i].shape.triangle.vertices[k].x,
                       figures[i].shape.triangle.vertices[k].y);
                if (k < 2) {
                    printf(", ");
                }
            }
            printf("))\n");
            printf("  perimeter = %.4f\n",
                   triangle_perimeter(figures[i].shape.triangle));
            printf("  area = %.4f\n", triangle_area(figures[i].shape.triangle));
            break;

        case POLYGON:
            // Вывод информации о многоугольнике
            printf("polygon(");
            for (int k = 0; k < figures[i].shape.polygon.num_vertices; ++k) {
                printf("%.2f %.2f",
                       figures[i].shape.polygon.vertices[k].x,
                       figures[i].shape.polygon.vertices[k].y);
                if (k < figures[i].shape.polygon.num_vertices - 1) {
                    printf(", ");
                }
            }
            printf("))\n");
            printf("  perimeter = %.4f\n",
                   polygon_perimeter(figures[i].shape.polygon));
            printf("  area = %.4f\n", polygon_area(figures[i].shape.polygon));
            break;
        }
    }

    return 0;
}
