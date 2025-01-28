/*
Вводится последовательность целых положительных чисел, заканчивающаяся -1 (не входит в последовательность).
Переставить максимальное число в последовательноси с минимальным местами.
Проверить на ввод и в случае ошибки вывести n/a.
Пример:
Ввод: 1 2 3 4 5 6 7 8 9 -1
Вывод: 9 2 3 4 5 6 7 8 1
*/

#include <stdio.h>

int main(void) {
    int vector[1000];
    int not_error = 1;

    int num = 0;
    int max = 0;
    int min = 0;
    int index_max = 0;
    int index_min = 0;
    int count = 0;

    not_error = scanf("%d", &num);

    if (not_error && num >= -1) {
        min = num;
        max = num;
    } else {
        printf("n/a");
        return 1;
    }

    while (num != -1) {
        vector[count] = num;
        if (num > max) {
            max = num;
            index_max = count;
        }
        if (num < min) {
            min = num;
            index_min = count;
        }
        if (scanf("%d", &num) != 1 || num < -1) {
            printf("n/a");
            return 1;
        }
        count++;
    }

    int tmp = 0;
    for (int i = 0; i < count; i++) {
        tmp = vector[i];
        if (i == index_max) tmp = vector[index_min];
        if (i == index_min) tmp = vector[index_max];
        if (i == count - 1) {
            printf("%d", tmp);
        } else {
            printf("%d ", tmp);
        }
    }

    return 0;
}

// gcc -Wall -Wextra -Werror task_1_04.c