//
// Author: W11A
// Date: Wednesday 16th March 2022
//
// Description:
// Attempt to implement each of the functions that may or may not be valid
// in the Week 5 tutorial.


#include <stdio.h>

int test_all_positive(int length, int nums[]);

int main(void) {

    int first_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int second_array[7] = {6, 8, 1, -4, 3, 0, -4};
    
    printf("First array: %d\n", test_all_positive(10, first_array));
    printf("Second array: %d\n", test_all_positive(7, second_array));

    return 0;
}

// Tests all values in the array are positive
// Takes in an array and its length
// Returns 1 if each value is positive and 0 if not
int test_all_positive(int length, int nums[]) {
    int i = 0;
    // int is_positive = 1;
    while (i < length) {
        if (nums[i] < 0) {
            // is_positive = 0;
            return 0;
        }
        i++;
    }
    // return is_positive;
    return 1;
}