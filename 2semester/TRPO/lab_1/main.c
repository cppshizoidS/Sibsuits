#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
    int radius;
} Circle;

bool parse_circle(const char* wkt_str, Circle* circle) {
    if (sscanf(wkt_str, "CIRCLE(%d %d %d)", &circle->x, &circle->y, &circle->radius) == 3) {
        return true;
    }
    return false;
}

void print_circle(const Circle* circle) {
    printf("CIRCLE(%d %d %d)\n", circle->x, circle->y, circle->radius);
}

int main() {
    char circle_wkt[100];
    Circle circle;

    printf("Enter a circle in WKT format (e.g., CIRCLE(x y radius)): ");
    fgets(circle_wkt, sizeof(circle_wkt), stdin);

    // Remove newline character from input
    circle_wkt[strcspn(circle_wkt, "\n")] = '\0';

    if (parse_circle(circle_wkt, &circle)) {
        printf("Parsed circle: ");
        print_circle(&circle);
    } else {
        printf("Invalid WKT format for circle\n");
    }

    return 0;
}