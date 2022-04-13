// free.c
// Exploration of free

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *number = malloc(sizeof(int));
    *number = 10;

    // How do we free this memory?
    free(number);
    

    return 0;
}
