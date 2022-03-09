// is_even.c
// W11A
// Check if a number given by the user is even or odd

#include <stdio.h>

// Check if the given number is even
int is_even(int num);

int main(void) {

    printf("Enter number: ");
    int num;
    scanf("%d", &num);

    if (is_even(num) == 1) {
        printf("Even number!\n");
    } else {
        printf("Odd number!\n");
    }

    return 0;
}


// is_even 
// takes in an integer
// returns 1 if it is an even number, and 0 if it is not.
int is_even(int num) {
    if (num % 2 == 0) {
        return 1;
    }

    return 0;
}

