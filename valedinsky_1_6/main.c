/*
1.6
Введите с клавиатуры число x и определите, сколько раз оно встречается в последовательности.
*/

#include <stdio.h>

int repeatNumber(FILE *fin, double number);

int main() {
    char filename[256];
    FILE *fin;
    double number;

    printf("Enter double ->");
    scanf("%lf", &number);
    printf("Enter filename ->");
    scanf("%s", filename);
    fin = fopen(filename, "r");

    if (!fin) {
        printf("File \"%s\" not open\n", filename);
        return -1;
    }

    printf("Repeat number %g is %d", number, repeatNumber(fin, number));

    return 0;
}

int repeatNumber(FILE *fin, double number) {
    int result = 0;
    double currentNumber;
    while (fscanf(fin, "%lf", &currentNumber) == 1) {
        if (number == currentNumber) result++;
    }
    return result;
}