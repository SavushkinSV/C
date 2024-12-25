/*
В консоль вводится строка.
Необходмо убрать пробелы в начале и конце строки. Также убрать повторяющиеся пробелы.
 */

#include <stdio.h>
#include <string.h>

void trim(char *str, char *result);

int main() {
    char str[1024] = "";
    char result[1024] = "";

    scanf("%1023[^\n\r]", str);
    trim(str, result);

    printf("%s", result);

    return 0;
}

void trim(char *str, char *result) {
    int ch = 1;
    int start_index = 0;

    int index_result = 0;
    int first_space = 0;
    while (str[start_index] == ' ') {
        start_index++;
    }

    int length = strlen(str);
    if (start_index == length) {
        result[0] = '\0';
    } else {
        int end_index = length - 1;
        while (str[end_index] == ' ') {
            if (end_index <= start_index) {
                break;
            }
            end_index--;
        }

        for (int i = start_index; i <= end_index; i++) {
            ch = str[i];
            if (ch == ' ' && first_space) {
                continue;
            }
            if (ch == ' ') {
                first_space = 1;
            } else {
                first_space = 0;
            }
            result[index_result] = str[i];
            index_result++;
        }
    }
}