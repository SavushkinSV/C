/*
1.2
Составьте программу для проверки является ли последовательность арифметической прогрессией.
*/

#include <stdio.h>

void progression(FILE *fin);

int main() {
    char filename[256];
    FILE *fin;
    printf("Enter filename ->");
    scanf("%s", filename);
    fin = fopen(filename, "r");
    if (!fin) {
        printf("File not open %s\n", filename);
        return -1;
    }

    progression(fin);
    fclose(fin);

    return 0;
}

void progression(FILE *fin) {
    double x, y, d;
    if (fscanf(fin, "%lf", &y) != 1) {
        printf("There is not enough data in the file\n");
        return;
    }

    if (fscanf(fin, "%lf", &x) != 1) {
        printf("There is not enough data in the file\n");
        return;
    }

    d = x - y;
    while (fscanf(fin, "%lf", &y) == 1) {
        if (y - x != d) {
            printf("The sequence is not an arithmetic progression");
            return;
        }
        x = y;
    }
    printf("The sequence is an arithmetic progression");
}