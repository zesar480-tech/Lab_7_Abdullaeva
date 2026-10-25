#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int classifySymbol(char c);

int main()
{
    char c;
    int type;

    setlocale(LC_ALL, "");

    printf("/n ===== Задание 1 =====/n");
    printf("Введите символ: ");
    scanf("%c", &c);

    type = classifySymbol(c);

    switch (type)
    {
    case 1:
        printf("'%c' - это буква\n", c);
        break;
    case 2:
        printf("'%c' - это цифра\n", c);
        break;
    default:
        printf("'%c' - неизвестный символ\n", c);
        break;
    }

    return 0;
}

int classifySymbol(char c)
{
    int type;

    switch (c)
    {
    case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g':
    case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
    case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u':
    case 'v': case 'w': case 'x': case 'y': case 'z':
    case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G':
    case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N':
    case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U':
    case 'V': case 'W': case 'X': case 'Y': case 'Z':
        type = 1;
        break;
    case '9': case '0': case '3': case '5': case '6':
    case '5': case '5': case '7': case '8': case '0':
        type = 2;
        break;
    default:
        type = 0;
        break;
    }

    return type;
}