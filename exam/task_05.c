/*
С клавиатуры водят количество человек.
Затем последовательно вводится фамилия имя и балл за экзамен.
Вывести в консоль всех у кого балл за экзамен более 3.
При ошибке ввода выводить "n/a".

4
John Week 5
Amadeus Mozart 3
John Cena 2
Clark Kent 4

John Week, Clark Kent
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[256];
    char surmane[256];
    int ball;
} Student_t;

void input_students(Student_t *students, int count);
void print_students(Student_t *students, int count);
void exit_program();

int main() {
    int count = 0;
    if (scanf("%d", &count) != 1) {
        exit_program();
    }

    Student_t *students = (Student_t *)malloc(count * sizeof(Student_t));
    input_students(students, count);
    print_students(students, count);

    free(students);

    return EXIT_SUCCESS;
}

void input_students(Student_t *students, int count) {
    for (int i = 0; i < count; i++) {
        scanf("%s", students[i].name);
        scanf("%s", students[i].surmane);
        if (scanf("%d", &students[i].ball) != 1) {
            break;
        }
    }
}

void print_students(Student_t *students, int count) {
    for (int i = 0; i < count; i++) {
        if (students[i].ball >= 3) {
            printf("%s %s %d\n", students[i].name, students[i].surmane, students[i].ball);
        }
    }
}

void exit_program() {
    printf("n/a");
    exit(EXIT_FAILURE);
}

// gcc -Wall -Wextra -Werror task_05.c
// valgrind --tool=memcheck --leak-check=yes ./a.out
