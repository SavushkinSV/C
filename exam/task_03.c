/*
В консоль вводится имя файла. Открыть его и в нем необходимо посчитать количество предложений.
Конец предложения это любой из символов .!?
Вывести в консоль количество предложений.
Если файла не существует вывести "n/a".
*/

#include <stdio.h>

#define MAX_LENGTH_FILENAME 256

int main() {
    char file_name[MAX_LENGTH_FILENAME] = "";
    scanf("%255s", file_name);

    FILE *fin = fopen(file_name, "r");
    if (fin != NULL) {
        int c = 0;
        int sum = 0;
        while ((c = fgetc(fin)) != EOF) {
            if (c == '.' || c == '!' || c == '?') {
                sum++;
            }
        }
        fclose(fin);
        printf("%s sum=%d", file_name, sum);
    } else {
        printf("n/a");
        return -1;
    }

    return 0;
}
