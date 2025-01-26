/*
В консоль вводится трехзачное целое число.
Вывести в консоль перевернутое число.

Пример:
Ввод:
123
Вывод:
321

Ввод:
729
Вывод:
927
*/

#include <stdio.h>

int main(void) {
    int num = 0;
    int count = 0;
    scanf("%d", &num);

    while (count < 3) {
        int mod = num % 10;
        printf("%d", mod);
        num /= 10;
        count++;
    }
    return 0;
}

// gcc -Wall -Wextra -Werror task_1_03.c