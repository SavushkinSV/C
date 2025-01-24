/*
В консоль вводится имя файла. Открыть его и в нем необходимо посчитать количество предложений.
Конец предложения это любой из символов .!?
Вывести в консоль количество предложений. Предложением считать хотя бы один символ после знака конца. После
вывода переноса строки не должно быть. предложения. Если файла не существует вывести "n/a".

Пример:

What???
Вывод: 1

Test+class!? Hello, World.
Вывод: 2
*/

#include <stdio.h>

#define MAX_LENGTH_FILENAME 256

int is_symbol(char ch) { return ch == '.' || ch == '!' || ch == '?'; }

int main() {
    char file_name[MAX_LENGTH_FILENAME] = "";
    scanf("%255s", file_name);

    FILE *fin = fopen(file_name, "r");
    if (fin != NULL) {
        int c = 0;
        int sum = 0;
        int first_simbol = 0;
        while ((c = fgetc(fin)) != EOF) {
            if (is_symbol(c) && first_simbol) continue;
            if (is_symbol(c)) {
                sum++;
                first_simbol = 1;
            } else {
                first_simbol = 0;
            }
        }
        fclose(fin);
        printf("%d", sum);
    } else {
        printf("n/a");
        return -1;
    }

    return 0;
}
