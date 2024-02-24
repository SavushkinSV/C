/*
1.13
Определите значение минимального (или максимального) элемента последовательности
*/

#include <stdio.h>

double findMax(FILE *fin);
double findMin(FILE *fin);

int main() {
    char filename[256];
    FILE *fin;

    printf("Enter filename ->");
    scanf("%s", filename);
    fin = fopen(filename, "r");

    if (!fin) {
        printf("File \"%s\" not open\n", filename);
        return -1;
    }

    printf("Max number: %g\n", findMax(fopen(filename, "r")));
    fclose(fin);
    printf("Min number: %g\n", findMin(fopen(filename, "r")));
    fclose(fin);    

    return 0;
}

double findMax(FILE *fin) {
    double max, currentNumber;
    fscanf(fin, "%lf", &max);
    while (fscanf(fin, "%lf", &currentNumber) == 1) {
        if (currentNumber > max) {
            max = currentNumber;
        }
    }

    return max;
}

double findMin(FILE *fin) {
    double min, currentNumber = 0;
    fscanf(fin, "%lf", &min);
    while (fscanf(fin, "%lf", &currentNumber) == 1) {
        if (currentNumber < min) {
            min = currentNumber;
        }
    }

    return min;
}