/*
В структуре Person 3 поля: имя, фамилия и рост.
В начале вводится число n - количество объектов структуры.
Затем вводятся имена, фамилии и рост. Затем вводится имя.

Нужно вывести на экран фамилии всех людей с этим именем и их средний рост в виде числа округленного до
ближайшего целого числа.

Пример:
3
John Week 190
Amadeus Mozart 150
John Cena 180
John

Week, Cena, 185
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[256];
    char surname[256];
    int height;
} Person;

void input_person(Person *persons, int count);
void find_name(Person *persons, char *input_name, int count);

int main(void) {
    int count = 0;
    char input_name[256];
    scanf("%d", &count);
    Person *persons = (Person *)malloc(count * sizeof(Person));

    input_person(persons, count);
    scanf("%s", input_name);
    find_name(persons, input_name, count);
    free(persons);
}

void input_person(Person *persons, int count) {
    for (int i = 0; i < count; i++) {
        scanf("%s %s %d", persons[i].name, persons[i].surname, &persons[i].height);
    }
}

void find_name(Person *persons, char *input_name, int count) {
    int sum_height = 0;
    int find_person = 0;

    for (int i = 0; i < count; i++) {
        if (!strcmp(input_name, persons[i].name)) {
            if (find_person) {
                printf(", %s", persons[i].surname);
            } else {
                printf("%s", persons[i].surname);
            }

            sum_height += persons[i].height;
            find_person++;
        }
    }

    printf(", %d", (int)round(sum_height * 1.0 / find_person));
}

// gcc -Wall -Wextra -Werror task_06.c -lm