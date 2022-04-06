// malloc.c
// Exploration of malloc
// W11A

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50

struct student {
    int zID;
    double mark;
    char name[MAX_NAME_LENGTH];
};

struct student *create_student(int zID, double mark, char *name);

int main(void) {

    // Create a malloc'd int
    int *alloc_int = malloc(sizeof(int));

    // Create a malloc'd struct student
    // DO NOT DO THIS - WE WON'T HAVE ENOUGH MEMORY
    // struct student *alloc_student = malloc(sizeof(struct student *));
    struct student *alloc_student = malloc(sizeof(struct student));

    return 0;
}
