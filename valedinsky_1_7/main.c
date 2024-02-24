/*
1.7
Введите с клавиатуры число x и определите порядковый номер первого числа, равного x.
Скорее всего в задании имеется ввиду, что необходимо определить первое вхождение числа x из
последовательности, которая расположена в файле.
*/

#include <stdio.h>

int firstOccurrence(FILE *fin, double number);

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
        printf("File \"%s\" not open", filename);
        return -1;
    }

    printf("Serial number of the first number %g is %d", number, firstOccurrence(fin, number));

    return 0;
}

int firstOccurrence(FILE *fin, double number) {
    int index = 0;
    double currentNumber;
    while (fscanf(fin, "%lf", &currentNumber) == 1) {
        index++;
        if (number == currentNumber) {
            return index;
        }
    }
    return 0;
}
