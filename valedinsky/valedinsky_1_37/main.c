/*
1.37
Определите симметирчны ли значения элементов массива.
Массив читается из файла и его длина определяется первым прочитанным числом.
*/

#include <stdio.h>
#include <stdlib.h>

int symmetry(double *const arrary, int n);

int main() {
    double *array = 0;
    int res, n, nmax = 0;
    char filename[256];
    FILE *fin;

    printf("Enter filename ->");
    scanf("%255s", filename);
    fin = fopen(filename, "r");

    if (!fin) {
        printf("File \"%s\" not open", filename);
        return -1;
    }

    if (fscanf(fin, "%d", &nmax) != 1 || nmax <= 0) {
        printf("Error entering sequence length");
        fclose(fin);
        return -1;
    }

    array = (double *)malloc(nmax * sizeof(double));
    if (!array) {
        printf("Not enough memory to create the array");
        fclose(fin);
        return -1;
    }

    for (n = 0; n < nmax && fscanf(fin, "%lf", &array[n]) == 1; n++)
        ;
    res = symmetry(array, n);
    printf("%s\n", (res) ? "Yes" : "No");
    free(array);
    fclose(fin);

    return 0;
}

int symmetry(double *const array, int n) {
    for (int i = 0; i < n / 2; i++) {
        if (array[i] != array[n - i - 1]) return 0;
    }
    return 1;
}