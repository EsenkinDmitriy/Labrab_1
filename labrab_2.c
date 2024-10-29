#include <stdio.h>

double compute_series_sum(double epsilon) {
    double sum = 0.0;
    double term = 1.0; // Начальный элемент ряда (1/0!)
    int n = 0;

    while (term > epsilon) {
        sum += term;
        n++;
        term /= n; // Вычисляем следующий член ряда на основе предыдущего (term = term * 1/n)
    }

    return sum;
}

int main() {
    double epsilon;

    printf("Введите значение точности E: ");
    scanf("%lf", &epsilon);

    if (epsilon <= 0) {
        printf("Точность должна быть положительной.\n");
        return 1;
    }

    double result = compute_series_sum(epsilon);
    printf("Сумма ряда с точностью %.10f равна: %.10f\n", epsilon, result);

    return 0;
}
