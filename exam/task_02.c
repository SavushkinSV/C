/*
В консоль вводится целое число, которое является количеством строк и столбцов.
Далее заполнить матрицу.
Вывести на экран результат перемножения матриц.
В случае ввода некорректных данных выводить "n/a".

Пример.
Ввод:
2
1 2 3 4
-1 2 3 -4

Вывод:
5 -6
9 -10
*/

#include <stdio.h>
#include <stdlib.h>

int **get_matrix(int n);
void free_mattix(int **matrix);
void print_matrix(int **matrix, int n);
int input_matrix(int **matrix, int n);
void mul_matrix(int **matrix_1, int **matrix_2, int **result, int n);

int main() {
    int n = 0;
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("n/a");
        return -1;
    }

    int **matrix_1 = get_matrix(n);
    int **matrix_2 = get_matrix(n);
    int **result = get_matrix(n);

    int not_error = input_matrix(matrix_1, n);
    if (not_error) {
        not_error = input_matrix(matrix_2, n);
    }

    if (not_error) {
        mul_matrix(matrix_1, matrix_2, result, n);
        print_matrix(result, n);
    } else {
        printf("n/a");
    }

    free_mattix(matrix_1);
    free_mattix(matrix_2);
    free_mattix(result);

    return !not_error;
}

int **get_matrix(int n) {
    int **array_pointer = (int **)malloc(n * sizeof(int *));
    int *value_pointer = (int *)malloc(n * n * sizeof(int));
    for (int i = 0; i < n; i++) {
        array_pointer[i] = value_pointer + n * i;
    }

    return array_pointer;
}

void print_matrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void free_mattix(int **matrix) {
    if (matrix != NULL) {
        if (matrix[0] != NULL) {
            free(matrix[0]);
        }
        free(matrix);
    }
}

int input_matrix(int **matrix, int n) {
    int not_error = 1;
    for (int i = 0; i < n && not_error; i++) {
        for (int j = 0; j < n && not_error; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                not_error = 0;
            }
        }
    }

    return not_error;
}

void mul_matrix(int **matrix_1, int **matrix_2, int **result, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }
}

// gcc -Wall -Wextra -Werror task_02.c
// valgrind --tool=memcheck --leak-check=yes ./a.out