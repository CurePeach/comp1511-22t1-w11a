// students.c
// By W11A 
// Exploration of struct pointers

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

struct student {
    int zID;
    double wam;
    char name[MAX_NAME_LENGTH];
};

int main(void) {

    struct student clarissa;
    clarissa.zID = 1234567;
    clarissa.wam = 65.96;
    // clarissa.name = "Clarissa";
    strcpy(clarissa.name, "Clarissa");
    
    // int nums[4];
    // nums = {1, 2, 3, 4};
    // nums[0] = 1;
    // nums[1] = 2;
    // ...
    
    // How do I create a pointer to this struct?
    struct student *angella = &clarissa; 
    
    // How could I change the values to:
    // - zID: 7654321
    // - wam: 100.0
    // - name: "Angella"
    // using only a pointer?
    (*angella).zID = 7654321;
    angella->zID = 7654321;
    angella->wam = 100.0;
    strcpy(angella->name, "Angella");

    return 0;
}
