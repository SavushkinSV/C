/*
С клавиатуры в консоль вводятся целые числа.
Концом последовательности является число -1.
Необходимо вывести цифры последовательности в обратном порядке.

Пример:
0 -45 65 3 5 2 1 -1
0 -45 65 3 5 2 1
*/

#include <stdio.h>
#include <stdlib.h>

void print_vector(int *vector, int size);

int main(void) {
    int capasity = 10;
    int size = 0;
    int number = 0;
    int *vector = malloc(capasity * sizeof(int));

    while (number != -1) {
        scanf("%d", &number);
        if (size == capasity) {
            capasity *= 2;
            vector = (int *)realloc(vector, capasity * sizeof(int));
        }
        vector[size++] = number;
    }

    print_vector(vector, size);
    free(vector);

    return 0;
}

void print_vector(int *vector, int size) {
    for (int i = size - 2; i >= 0; i--) {
        if (i == 0) {
            printf("%d", vector[i]);
        } else {
            printf("%d ", vector[i]);
        }
    }
}

// gcc -Wall -Wextra -Werror task_01.c
// valgrind --tool=memcheck --leak-check=yes ./a.out