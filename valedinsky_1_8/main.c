/*
1.8
Введите с клавиатуры число x и определите порядковый номер последнего числа x.
Скорее всего в задании имеется ввиду, что необходимо определить последнее вхождение числа x из
последовательности, которая расположена в файле.
*/

#include <stdio.h>

int lastOccurrence(FILE *fin, double number);

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

    printf("Serial number of the last number %g is %d", number, lastOccurrence(fin, number));

    return 0;
}

int lastOccurrence(FILE *fin, double number) {
    int index, count = 0;
    double currentNumber;
    while (fscanf(fin, "%lf", &currentNumber) == 1) {
        count++;
        if (number == currentNumber) {
            index = count;
        }
    }
    return index;
}
