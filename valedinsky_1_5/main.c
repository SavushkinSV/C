/*
1.5
Определите количество чисел в последовательности, которые больше предшествующего числа.
*/

#include <stdio.h>
int numbersGreaterPrevious(FILE *fin);

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

    printf("Result: %d", numbersGreaterPrevious(fin));
    fclose(fin);

    return 0;
}

int numbersGreaterPrevious(FILE *fin) {
    int result = 0;
    double number, nextNumber;
    if (fscanf(fin, "%lf", &number) != 1) {
        printf("There is not enough data in the file\n");
        return -1;
    }
    printf("%g\n", number);

    if (fscanf(fin, "%lf", &nextNumber) != 1) {
        printf("There is not enough data in the file\n");
        return -1;
    }
    printf("%g\n", nextNumber);

    do {
        if (number < nextNumber) result++;
        number = nextNumber;
    } while (fscanf(fin, "%lf", &nextNumber) == 1);

    return result;
}