/*
2.13
Постройте функцию заполнения квадратной татрицы значениями aij= 1 / (1 + i + j), i,j=0,...,n-1 (это так
называемая матрица Гильберта).
*/

#include <stdio.h>
#include <stdlib.h>

double **get_matrix(int row, int col);
void hilbert(double **matrix, int row, int col);
void output_matrix(double **matrix, int row, int col);
void free_matrix(double **matrix);

int main() {
    int n = 0;
    double **matrix = NULL;

    printf("Enter matrix dimensions ->");
    if (scanf("%d", &n) == 1 && n > 0) {
        matrix = get_matrix(n, n);
        hilbert(matrix, n, n);
        output_matrix(matrix, n, n);
        free_matrix(matrix);
    } else {
        printf("n/a");
    }

    return 0;
}

double **get_matrix(int row, int col) {
    double **array_pointer = malloc(row * sizeof(double *));
    double *value_pointer = malloc(row * col * sizeof(double));
    for (int i = 0; i < row; i++) {
        array_pointer[i] = value_pointer + col * i;
    }

    return array_pointer;
}

void hilbert(double **matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = 1.0 / (double)(i + j + 1);
        }
    }
}

void output_matrix(double **matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j != col - 1)
                printf("%lf ", matrix[i][j]);
            else
                printf("%lf", matrix[i][j]);
        }
        if (i != row - 1) printf("\n");
    }
}

void free_matrix(double **matrix) {
    free(matrix[0]);
    free(matrix);
}
