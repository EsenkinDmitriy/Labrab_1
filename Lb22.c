#include <stdio.h>
#include <math.h>

// ������� ��� ���������� ������������ ��������� ln(x)
double LnFunction(double x) {
    return log(x); // ���������� �������� ln(x)
}

// ������� ��� �������� ������������ �����
int IsValidInput() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if ((ch < '0' || ch > '9') && ch != '-' && ch != '.') {
            return 0; // �������� ����
        }
    }
    return 1; // ���������� ����
}

// ������� ��� ���������� ��������� ������� ��������
double IntegrateUsingTrapezoids(double a, double b, double e) {
    int numIntervals = 1; // ��������� ���������� �������������
    double intervalWidth, sum, prevSum;

    intervalWidth = (b - a) / numIntervals;
    sum = (LnFunction(a) + LnFunction(b)) / 2.0; // ��������� �������� ���������

    do {
        prevSum = sum;
        sum = 0.0;

        // ������ ����� �� ���� �������������
        for (int j = 1; j < numIntervals; j++) {
            sum += LnFunction(a + j * intervalWidth);
        }

        sum = (intervalWidth / 2.0) * (LnFunction(a) + 2.0 * sum + LnFunction(b));

        // �������� �� ��������
        if (fabs(sum - prevSum) < e) {
            break; // ���������� ��������� ��������
        }

        numIntervals *= 2; // ����������� ���������� �������������
        intervalWidth = (b - a) / numIntervals; // ��������� ������ ������������
    } while (1);

    return sum; // ���������� �������� ���������
}

int main() {
    double a, b, e;

    // ���� ������ ��������������
    printf("������� ������� �������������� a � b (a < b): ");
    while (1) {
        if (scanf("%lf %lf", &a, &b) == 2 && a < b) {
            break; // �������� ����
        }
        printf("������������ ����. ���������� �����: ");
        while (getchar() != '\n'); // ������� ����
    }

    // ���� ����������� ���������� �����������
    printf("������� ����������� ���������� ����������� E: ");
    while (1) {
        if (IsValidInput() && scanf("%lf", &e) == 1 && e > 0) {
            break; // �������� ����
        }
        printf("������������ ����. ���������� �����: ");
        while (getchar() != '\n'); // ������� ����
    }

    // ��������� ��������
    double result = IntegrateUsingTrapezoids(a, b, e);
    printf("�������� ��������� = %.6f\n", result); // ����� ����������

    return 0; // ���������� ���������
}
