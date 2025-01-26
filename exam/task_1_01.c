/*
В консоль воодистся радиус платинового шара.
Найти массу платиного шара ее вывести в констоль окгугленную до ближайшего целого числа.
Плотность платины p = 21500.
Формулы:
    V = m / p
    V = (4 / 3) * pi * R^3
Для расчета использовать тип double.
*/

#include <math.h>
#include <stdio.h>

int main(void) {
    int p = 21500;
    double r = 0.0;

    scanf("%lf", &r);
    double V = (4.0 / 3.0) * M_PI * r * r * r;

    double m = round(V * p);
    printf("%d", (int)m);

    return 0;
}

// gcc -Wall -Wextra -Werror task_1_01.c -lm