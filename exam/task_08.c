/*
Структука вектора x(целое), y(целое), z(целое).

В консоль вводится целое число N, которое обозначает количество векторов.
Затем заполняются координаты векторов.
Последним вводится число D.

Вывести в консоль округленную до целого числа сумму длин векторов, которые строго больше D.
Для точности при вычислениях лучше использовать тип double.

Проверить на корректность введенные данные. В случае ввода некорректных данных выводить n/a.
Перевода на новую строку не должно быть.

Пример:
Ввод:
2
0 0 0 5 5 5
2
Вывод:
9

Ввод:
3
1 1 1 2 2 2 3 3 3
4
Вывод:
5

Ввод:
2
1 1 1 2 2 2
0
Вывод:
5

*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int z;
} Vector_t;

int input_vector(Vector_t *vectors, int index) {
    int not_error = 1;
    not_error = scanf("%d", &vectors[index].x);
    if (not_error) not_error = scanf("%d", &vectors[index].y);
    if (not_error) not_error = scanf("%d", &vectors[index].z);

    return not_error;
}

int main(void) {
    int not_error = 1;
    int N = 0;
    int D = 0;

    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("n/a");
        return 1;
    }
    Vector_t *vectors = (Vector_t *)malloc(N * sizeof(Vector_t));

    for (int i = 0; i < N && not_error; i++) {
        not_error = input_vector(vectors, i);
    }

    if (not_error) not_error = scanf("%d", &D);
    if (not_error) {
        double sum = 0;
        double x = 0;
        double y = 0;
        double z = 0;
        for (int i = 0; i < N; i++) {
            x = vectors[i].x;
            y = vectors[i].y;
            z = vectors[i].z;
            double r = sqrt(x * x + y * y + z * z);
            if (r > D) {
                sum += r;
            }
        }
        sum = round(sum);
        printf("%d", (int)sum);
    }
    if (!not_error) {
        printf("n/a");
    }

    free(vectors);

    return 0;
}