// echo_twice.c
// By W11A
// Reads lines from input and prints them out twice.
// Can only use fgets() and printf()

#include <stdio.h>

#define MAX_LEN 4096

int main(void) {

    char line[MAX_LEN];
    while (fgets(line, MAX_LEN, stdin) != NULL) {
        printf("%s", line);
        printf("%s", line);
    }

    return 0;
}
