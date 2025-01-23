/*
В тектовом файле последовательность символов защифрованная шифром Цезаря. В алфавите шифра используется только
буквы английского алфавита a-z и A-Z.

В консоль вводится имя файла и ключ от шифра.
Открыть файл. Если встречается символ отличный от алфавита, то он выводится без изменений. Если встречается
символ из алфавита шифра, то он выводится с помощью шифра Цезаря.

Если файла не существует, то вывести "n/a". Перевода на новую строку не должно быть.

Пример:
Ввод:
7.txt
-8

Файл 1.txt:
bzctgitgi

Вывод:
TrUlYaYa


7.txt 1

*/

#include <stdio.h>
#include <string.h>

int is_alpha(char c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); }

int main() {
    char *dic = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int len_dic = strlen(dic);

    char filename[256];
    int key = 0;

    printf("Enter filename: ");
    scanf("%s", filename);
    printf("Enter key: ");
    scanf("%d", &key);
    key %= len_dic;

    FILE *fin = fopen(filename, "r");
    if (fin == NULL) {
        printf("n/a");
        return 1;
    }

    char ch = 0;
    while ((ch = fgetc(fin)) != EOF) {
        if (is_alpha(ch)) {
            char *p = strchr(dic, ch);
            int index = p - dic;
            index = index + key;
            if (index < 0) {
                index += len_dic;
            } else if (index >= len_dic) {
                index -= len_dic;
            }
            printf("%c", dic[index]);
        } else {
            printf("%c", ch);
        }
    }
}
