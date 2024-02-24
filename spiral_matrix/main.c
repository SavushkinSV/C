/*
Дана матрица, или, на нашем языке, двумерный массив N и M. Они задаются
пользователем и это может быть не только квадрат, но и прямоугольник.
N и M числа больше 0.
Необходимо заполнить эту матрицу по спирали числами от 1 и по возрастающей до M*N.

Примеры вовода
1 2 3
6 5 4

1 2 3 4 5
14 15 16 17 6
13 20 19 18 7
12 11 10 9 8

*/

#include <stdio.h>
#include <stdlib.h>

int **get_matrix(int row, int col);
void input_matrix(int **matrix, int row, int col);
void spiral_matrix(int **matrix, int row, int col);
void output_matrix(int **matrix, int row, int col);
void free_matrix(int **matrix);

int main() {
    int n = 0;
    int m = 0;
    int **matrix = NULL;

    printf("Enter matrix dimensions ->");
    if (scanf("%d %d", &n, &m) == 2 && n > 0 && m > 0) {
        matrix = get_matrix(n, m);
        input_matrix(matrix, n, m);
        spiral_matrix(matrix, n, m);
        output_matrix(matrix, n, m);
        free_matrix(matrix);
    } else {
        printf("n/a");
    }

    return 0;
}

int **get_matrix(int row, int col) {
    int **array_pointer = malloc(row * sizeof(int *));
    int *value_pointer = malloc(row * col * sizeof(int));
    for (int i = 0; i < row; i++) {
        array_pointer[i] = value_pointer + col * i;
    }

    return array_pointer;
}

void input_matrix(int **matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = 0;
        }
    }
}

void spiral_matrix(int **matrix, int row, int col) {
    int x = -1;
    int y = 0;
    int d_col = 1;
    int d_row = 0;
    int i = 1;

    while (i <= row * col) {
        if ((0 <= x + d_col && x + d_col < col) && (0 <= y + d_row && y + d_row < row) &&
            (matrix[y + d_row][x + d_col] == 0)) {
            x += d_col;
            y += d_row;
            matrix[y][x] = i;
            i++;
        } else {
            if (d_col == 1) {
                d_col = 0;
                d_row = 1;
            } else if (d_row == 1) {
                d_row = 0;
                d_col = -1;
            } else if (d_col == -1) {
                d_col = 0;
                d_row = -1;
            } else if (d_row == -1) {
                d_row = 0;
                d_col = 1;
            }
        }
    }
}

void output_matrix(int **matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j != col - 1)
                printf("%d ", matrix[i][j]);
            else
                printf("%d", matrix[i][j]);
        }
        if (i != row - 1) printf("\n");
    }
}

void free_matrix(int **matrix) {
    free(matrix[0]);
    free(matrix);
}
