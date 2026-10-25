#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

int checkOperation(float x, char op, float y);
float calculate(float x, char op, float y);

int main(void)
{
    float x, y, result;
    char op;
    int status;

    setlocale(LC_ALL, "");
    printf("/n ===== Задание 2 =====/n");

    printf("Операции: + - * / ^ (степень)\n");
    printf("Ввести выражение без пробелов: ");
    scanf("%f%c%f", &x, &op, &y);

    status = checkOperation(x, op, y);

    switch (status)
    {
    case 0:
        result = calculate(x, op, y);
        printf("%.2f %c %.2f = %.2f\n", x, op, y, result);
        break;
    case 1:
        printf("Ошибка: неизвестная операция '%c'\n", op);
        break;
    case 2:
        printf("Ошибка: деление на ноль\n");
        break;
    case 3:
        printf("Ошибка: ноль нельзя возводить в отрицательную степень\n");
        break;
    }

    return 0;
}

int checkOperation(float x, char op, float y)
{
    int status;

    switch (op)
    {
    case '+':
    case '-':
    case '*':
        status = 0;
        break;
    case '/':
        status = (y == 0) ? 2 : 0;
        break;
    case '^':
        status = (x == 0 && y < 0) ? 3 : 0;
        break;
    default:
        status = 1;
        break;
    }

    return status;
}

float calculate(float x, char op, float y)
{
    float result;

    switch (op)
    {
    case '+':
        result = x + y;
        break;
    case '-':
        result = x - y;
        break;
    case '*':
        result = x * y;
        break;
    case '/':
        result = x / y;
        break;
    case '^':
        result = (float)pow(x, y);
        break;
    default:
        result = 0;
        break;
    }

    return result;
}