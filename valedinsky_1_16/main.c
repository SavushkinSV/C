/*
1.6
Пусть последовательность является неубывающей. Определите количество различных элементов этой
последовательности.
*/

#include <stdio.h>

int differentElements(FILE *fin);

int main() {
    char filename[256];
    FILE *fin;

    printf("Enter filename -> ");
    scanf("%s", filename);
    fin = fopen(filename, "r");

    if (!fin) {
        printf("File \"%s\" not open\n", filename);
        return -1;
    }
    printf("Different elements: %d", differentElements(fin));
    fclose(fin);
    
    return 0;
}

int differentElements(FILE *fin) {
    int count = 1;
    double currentValue, previousValue;
    fscanf(fin, "%lf", &previousValue);
    while (fscanf(fin, "%lf", &currentValue) == 1) {
        if (currentValue < previousValue) {
            printf("Incorrect sequence\n");
            return -1;
        }
        if (currentValue > previousValue) {
            count++;
        }
        previousValue = currentValue;
    }
    return count;
};