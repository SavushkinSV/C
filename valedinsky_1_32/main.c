/*
1.32
Введите с клавиатуры строку символов и для каждого ее элемента определите сколько раз он встречается в файле.
*/

#include <stdio.h>

int count(char *name, char *a, int *nmb);

int main() {
    char a[256];  /* исходная строка */
    int nmb[256]; /* количество вхождений */
    char filename[256];

    int n;
    printf("Enter filename ->");
    scanf("%255s", filename);
    printf("Enter a character string ->");

    scanf("%255s", a);
    if ((n = count(filename, a, nmb)) == -1) {
        printf("File \"%s\" not open\n", filename);
        return -1;
    }

    printf("Symbol: Count\n");
    for (int i = 0; i < n; i++) {
        printf("%c: %d\n", a[i], nmb[i]);
    }

    return 0;
}

int count(char *name, char *a, int *nmb) {
    FILE *fin;
    int i, c, buf[256];
    fin = fopen(name, "r");
    if (!fin) return -1;
    for (i = 0; i < 256; i++) buf[i] = 0;
    while ((c = fgetc(fin)) != EOF) buf[c]++;
    for (i = 0; a[i]; i++) nmb[i] = buf[(int)a[i]];
    fclose(fin);

    return i;
}