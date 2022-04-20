
#include <stdio.h>

int fibonacci(int n);
int factorial(int n);

int main(void) {

    int num;
    scanf("%d", &num);
    printf("Fibonacci is %d\n", fibonacci(num));
    printf("Factorial is %d\n", factorial(num));

    return 0;
}

int fibonacci(int n) {
    // Base case(s)
    if (n == 1 || n == 2) {
        return 1;
    }
    
    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int factorial(int n) {
    // Base case
    if (n == 1) {
        return 1;
    }
    
    // Recursive case
    return n * factorial(n - 1);
}
