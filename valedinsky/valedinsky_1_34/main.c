/*
1.34
Написать функцию, получающую в качестве параметра имя текстового файла и копирующая его содержимое в другой
файл с заменой всех маленьких букв на большие.
*/

#include <stdio.h>

int copy_file(char *input_filename, char *output_filename);

int main() {
    char input_filename[256];
    char output_filename[256];
    printf("Enter input filename ->");
    scanf("%255s", input_filename);
    printf("Enter output filename ->");
    scanf("%255s", output_filename);
    copy_file(input_filename, output_filename);

    return 0;
}

int copy_file(char *input_filename, char *output_filename) {
    FILE *fin = fopen(input_filename, "rt");
    if (!fin) {
        printf("File \"%s\" not open\n", input_filename);
        return -1;
    }
    
    FILE *fout = fopen(output_filename, "w+t");
    if (!fout) {
        printf("File \"%s\" not open\n", output_filename);
        fclose(fin);
        return -1;
    }

    char c;
    while ((c = fgetc(fin)) != EOF) {
        if (c >= 'a' && c <= 'z') {
            fprintf(fout, "%c", c - 32);
        } else {
            fprintf(fout, "%c", c);
        }
    }
    fclose(fin);
    fclose(fout);

    return 0;
}