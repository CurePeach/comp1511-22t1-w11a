// arrays.c
// W11A
// Exploration of arrays

#include <stdio.h>

struct dog {
    int age;
    double weight;
    double height;
};

int main(void) {
    // Create an array called zeros of a size 7 and initialise all of the elements to 0.
    int zeroes[7] = {0}; 

    // How do we access elements of an array? Print the 3rd element.
    printf("The third element is %d\n", zeroes[2]);

    // How do we print out the elements of the zeros array above to ensure they are all 0?
    int counter = 0;
    while (counter < 7) {
        printf("The %dth element is %d\n", counter, zeroes[counter]);

        counter += 1;
    }

    // Create a struct array
    // struct dog clarissas_shibas[4];
    // clarissas_shibas[0].age = 1;
    // clarissas_shibas[0].weight = 10;
    // clarissas_shibas[0].height = 30;
    // printf("first shiba weighs %lf\n", clarissas_shibas[0].weight);

    // struct dog miku;
    // miku.age = 1;

    // int a = 1;
    // int b = 2;
    // b = a;
    // b = 3;

    // Create an array called ones of a size 7 and initialsie all of the elements to 1.
    int ones[7] = {1, 1, 1, 1, 1, 1, 1};
    // int ones[7] = {1}; doesn't work

    return 0;
}

// array_print prints all the contents in an array, separated by new lines
// takes in an array and its length
// returns ???
void array_print(int length, int arr[]);