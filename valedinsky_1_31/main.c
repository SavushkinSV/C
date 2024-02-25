/*
1.31
Введите с клавиатуры символ и определите сколько раз он встречается в файле.
*/

#include <stdio.h>

int count(char *name, char a, int *nmb);
void free_bufer();

int main() {
    char a;      /* исходный символ */
    int nmb = 0; /* количество вхождений */
    char filename[256];

    printf("Enter filename ->");
    scanf("%255s", filename);
    printf("Enter symbol ->");

    free_bufer();
    a = fgetc(stdin);
    if (count(filename, a, &nmb) == -1) {
        printf("File \"%s\" not open\n", filename);
        return -1;
    }
    printf("Symbol: Count\n");
    printf("%c: %d\n", a, nmb);

    return 0;
}

int count(char *name, char a, int *nmb) {
    FILE *fin;
    int c;
    fin = fopen(name, "r");
    if (!fin) return -1;
    while ((c = fgetc(fin)) != EOF) {
        if (c == a) (*nmb)++;
    }
    fclose(fin);

    return *nmb;
}

void free_bufer() {
    char c = getc(stdin);
    while (c != '\n' && c != ' ') {
        c = getc(stdin);
    }
}