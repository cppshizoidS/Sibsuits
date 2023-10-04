#include <stdio.h>
#include <math.h>

double f(double x) {
    return pow(x, 2) / (10 + pow(x, 3));
}

double trapezoidal_rule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }
    return sum * h;
}

double simpson_rule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i += 2) {
        double x = a + i * h;
        sum += 4 * f(x);
    }
    for (int i = 2; i < n; i += 2) {
        double x = a + i * h;
        sum += 2 * f(x);
    }
    return sum * h / 3.0;
}

int main() {
    int N = 100;
    double a = -2.0;
    double b = 5.0;
    double x[N+1];
    double y[N+1];
    double h = (b - a) / N;
    for (int i = 0; i <= N; i++) {
        x[i] = a + i * h;
        y[i] = f(x[i]);
    }
    double trapezoidal_result = trapezoidal_rule(a, b, N);
    double simpson_result = simpson_rule(a, b, N);
    printf("Trapezoidal rule result: %lf\n", trapezoidal_result);
    printf("Simpson rule result: %lf\n", simpson_result);
    return 0;
}