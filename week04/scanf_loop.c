// scanf_loop.c
// W11A
// Scan in all numbers until a non-integer is typed in or CTRL D is pressed.

#include <stdio.h>

int main(void) {

    // What is the initialisation?
    int num;
    int result = scanf("%d", &num);
    // What is the condition?
    while (result == 1) {
        printf("%d entered!\n", num);

        // What is the increment?
        result = scanf("%d", &num);
    }

    return 0;
}