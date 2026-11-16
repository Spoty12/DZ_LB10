#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

// Функция вычисления площади треугольника
float area_triangle(int a) {
    return (float)(a * a) / 2;
}

// Функция рисования перевернутого прямоугольного треугольника
void draw_triangle(int a, char symbol) {
    printf("\n");

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (i == 0 || j == 0 || j == a - i - 1) {
                printf("%c ", symbol);
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Функция ввода размера треугольника
int get_side() {
    int a;

    do {
        printf("Введите длину стороны треугольника: ");
        scanf("%d", &a);

        if (a <= 0) {
            printf("Размер должен быть положительным.\n");
        }
    } while (a <= 0);

    return a;
}

// Функция сравнения двух треугольников по площади
int compare_triangle(int a, int b) {
    if (area_triangle(a) > area_triangle(b))
        return 1;
    else if (area_triangle(a) < area_triangle(b))
        return -1;
    else
        return 0;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int a, choice;
    char symbol;

    printf("Программа работы с треугольником\n");

    a = get_side();

    do {
        printf("\n===== МЕНЮ =====\n");
        printf("1. Рассчитать площадь\n");
        printf("2. Вывести определение фигуры\n");
        printf("3. Нарисовать фигуру\n");
        printf("0. Выход\n");
        printf("Выберите операцию: ");

        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Площадь треугольника: %.2f\n",
                area_triangle(a));
            break;

        case 2:
            printf("\nПрямоугольный равнобедренный треугольник — ");
            printf("это фигура, у которой один угол равен 90 градусов, ");
            printf("а две стороны, образующие этот угол, равны.\n");
            printf("Площадь вычисляется по формуле S = a * a / 2.\n");
            break;

        case 3:
            printf("Введите символ для рисования: ");
            scanf(" %c", &symbol, 1);

            draw_triangle(a, symbol);
            break;

        case 0:
            printf("Программа завершена.\n");
            break;

        default:
            printf("Неверный пункт меню! Повторите ввод.\n");
        }

    } while (choice != 0);

    return 0;
}
