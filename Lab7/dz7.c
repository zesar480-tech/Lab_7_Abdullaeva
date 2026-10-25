#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int isLeapYear(int year);
int daysInMonth(int month, int leap);

int main()
{
    int month, year, leap, days;

    setlocale(LC_ALL, "");
    printf("/n ===== Домашняя работа =====/n");

    printf("Введите номер месяца (1-12): ");
    scanf("%d", &month);
    printf("Введите год: ");
    scanf("%d", &year);

    leap = isLeapYear(year);
    days = daysInMonth(month, leap);

    printf("%d год - %s\n", year, leap ? "високосный" : "невисокосный");

    switch (days)
    {
    case -1:
        printf("Ошибка: месяца с номером %d не существует\n", month);
        break;
    default:
        printf("В %d-м месяце %d %s\n", month, days, (days == 31) ? "день" : "дней");
        break;
    }

    return 0;
}

int isLeapYear(int year)
{
    int leap;

    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    return leap;
}


int daysInMonth(int month, int leap)
{
    int days;

    switch (month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        days = 31;
        break;
    case 4: case 6: case 9: case 11:
        days = 30;
        break;
    case 2:
        days = leap ? 29 : 28;
        break;
    default:
        days = -1;
        break;
    }

    return days;
}