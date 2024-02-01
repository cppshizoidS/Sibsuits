#include <stdio.h>
#include <math.h>

int calculateTriangleProperties(double a, double b, double c, double *perimeter, double *area) {
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        return 0; // Треугольник не существует
    }

    *perimeter = a + b + c;

    double s = *perimeter / 2;
    *area = sqrt(s * (s - a) * (s - b) * (s - c));

    return 1; // Треугольник существует
}

int main() {
    double side1, side2, side3, perimeter, area;

    printf("Введите длины сторон треугольника: ");
    scanf("%lf %lf %lf", &side1, &side2, &side3);

    if (calculateTriangleProperties(side1, side2, side3, &perimeter, &area)) {
        printf("Периметр: %lf\n", perimeter);
        printf("Площадь: %lf\n", area);
    } else {
        printf("Треугольник не существует.\n");
    }

    return 0;
}
