#include <stdio.h>
#include <math.h>

// Функция для вычисления натурального логарифма ln(x)
double LnFunction(double x) {
    return log(x); // Возвращаем значение ln(x)
}

// Функция для проверки корректности ввода
int IsValidInput() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if ((ch < '0' || ch > '9') && ch != '-' && ch != '.') {
            return 0; // Неверный ввод
        }
    }
    return 1; // Корректный ввод
}

// Функция для вычисления интеграла методом трапеций
double IntegrateUsingTrapezoids(double a, double b, double e) {
    int numIntervals = 1; // Начальное количество подынтервалов
    double intervalWidth, sum, prevSum;

    intervalWidth = (b - a) / numIntervals;
    sum = (LnFunction(a) + LnFunction(b)) / 2.0; // Начальное значение интеграла

    do {
        prevSum = sum;
        sum = 0.0;

        // Расчет суммы по всем подынтервалам
        for (int j = 1; j < numIntervals; j++) {
            sum += LnFunction(a + j * intervalWidth);
        }

        sum = (intervalWidth / 2.0) * (LnFunction(a) + 2.0 * sum + LnFunction(b));

        // Проверка на точность
        if (fabs(sum - prevSum) < e) {
            break; // Достигнута требуемая точность
        }

        numIntervals *= 2; // Увеличиваем количество подынтервалов
        intervalWidth = (b - a) / numIntervals; // Обновляем ширину подынтервала
    } while (1);

    return sum; // Возвращаем значение интеграла
}

int main() {
    double a, b, e;

    // Ввод границ интегрирования
    printf("Введите пределы интегрирования a и b (a < b): ");
    while (1) {
        if (scanf("%lf %lf", &a, &b) == 2 && a < b) {
            break; // Успешный ввод
        }
        printf("Некорректный ввод. Попробуйте снова: ");
        while (getchar() != '\n'); // Очищаем ввод
    }

    // Ввод максимально допустимой погрешности
    printf("Введите максимально допустимую погрешность E: ");
    while (1) {
        if (IsValidInput() && scanf("%lf", &e) == 1 && e > 0) {
            break; // Успешный ввод
        }
        printf("Некорректный ввод. Попробуйте снова: ");
        while (getchar() != '\n'); // Очищаем ввод
    }

    // Вычисляем интеграл
    double result = IntegrateUsingTrapezoids(a, b, e);
    printf("Значение интеграла = %.6f\n", result); // Вывод результата

    return 0; // Завершение программы
}
