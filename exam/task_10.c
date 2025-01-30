/*
Написать программу на Си.
Вводится последовательность целых чисел.
Гарантируется, что в последовательности только у одного числа нет пары.
Конец последовательности -1.
Вывести в консоль число, у которого нет пары.
Нельзя использовать массивы и динамическую память.

Пример:
Ввод:
2 3 2 -1
Выыод:
3

Ввод:
2 2 2 -1
Выыод:
2
*/

#include <stdio.h>

int main() {
    int num = 0;
    int prev_first = 0;
    int prev_second = 0;
    int not_pair = 0;
    scanf("%d", &num);

    while (num != -1) {
        if (not_pair) {
            if (prev_first == num) {
                prev_first = 0;
                if (prev_second) {
                    not_pair = prev_second;
                } else {
                    not_pair = 0;
                }
            } else if (prev_second == num) {
                prev_second = 0;
            } else {
                prev_second = num;
            }
        } else {
            prev_first = num;
            not_pair = num;
        }

        scanf("%d", &num);
    }
    printf("%d", not_pair);

    return 0;
}

// gcc -Wall -Wextra -Werror task_10.c
