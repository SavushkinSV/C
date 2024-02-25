/*
1.33
Написать функцию, получающую в качестве параметра имя текстового файла и подсчитывающую количество латинских
букв в файле.
*/

#include <stdio.h>

int count_alphabet(char *name);
void free_bufer();

int main() {
    char filename[256];
    printf("Enter filename ->");
    scanf("%255s", filename);

    int n = 0;
    if ((n = count_alphabet(filename)) == -1) {
        printf("File \"%s\" not open\n", filename);
        return -1;
    } else {
        printf("Latin latters in the file: %d", n);
    }

    return 0;
}

int count_alphabet(char *name) {
    FILE *fin;
    int count = 0;
    int c;
    fin = fopen(name, "r");
    if (!fin) return -1;
    while ((c = fgetc(fin)) != EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) count++;
    }
    fclose(fin);

    return count;
}