// Exploration of pointers
// W11A

#include <stdio.h>

int *max(int *a, int *b);
void change_num(int *pointer);

int main(void) {

    // How do I declare a pointer?
    int *pointer;

    // How do I initialise a pointer?
    int a = 2;
    pointer = &a;
    printf("a = %d\n", a);
    printf("&a = %p\n", &a);
    printf("pointer = %p\n", pointer);
    char c;
    char *char_pointer = &c;
    
    change_num(pointer);
    printf("a = %d\n", a);

    return 0;
}

void change_num(int *pointer) {
    *pointer = 10;
}