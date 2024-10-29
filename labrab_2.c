#include <stdio.h>

double compute_series_sum(double epsilon) {
    double sum = 0.0;
    double term = 1.0; // ��������� ������� ���� (1/0!)
    int n = 0;

    while (term > epsilon) {
        sum += term;
        n++;
        term /= n; // ��������� ��������� ���� ���� �� ������ ����������� (term = term * 1/n)
    }

    return sum;
}

int main() {
    double epsilon;

    printf("������� �������� �������� E: ");
    scanf("%lf", &epsilon);

    if (epsilon <= 0) {
        printf("�������� ������ ���� �������������.\n");
        return 1;
    }

    double result = compute_series_sum(epsilon);
    printf("����� ���� � ��������� %.10f �����: %.10f\n", epsilon, result);

    return 0;
}
