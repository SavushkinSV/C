/*
Прочитать из файла телефонную книгу. Конец файла -1. В одной строке файла присутствует один контакт.
Формат файла:
Smith:8-950-111-11-33
Формат вывода:
Smith +7(950)111-11-33
*/

#include <stdio.h>

#define buf 256

int main(void) {
    char filename[buf];
    scanf("%s", filename);
    FILE *fin = fopen(filename, "r");

    if (fin) {
        char name[256];
        int pref;
        char number[10];
        int scan = 0;

        while ((scan = fscanf(fin, "%99[^:]:8-%d-%s\n", name, &pref, number)) != EOF) {
            if (scan == 3) printf("%s +7(%03d)%s\n", name, pref, number);
        }

        fclose(fin);

    } else {
        printf("n/a");
    }

    return 0;
}

// gcc -Wall -Wextra -Werror task_09.c