#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME_LENGTH 50

// Definitions -----------------------------------------------------------------

struct student {
    int zID;
    double mark;
    char name[MAX_NAME_LENGTH];
    struct student *next;
};

// Function prototypes ---------------------------------------------------------

struct student *create_student(int zID, double mark, char *name);
void print_students_tail(struct student *head);

// Main function ---------------------------------------------------------------

int main(void) {
    // Q8. TODO: Create two struct student *'s using the create_student()
    // function from the malloc exercise.
    // Student 1: name: Harry, zID: 5000000, mark: 71.3
    // Student 2: name: Lucy, zID: 5111111, mark: 62.9
    struct student *harry = create_student(5000000, 71.3, "Harry");
    struct student *lucy = create_student(5111111, 62.9, "Lucy");
    
    // Q9. TODO: Link 'Harry struct' to 'Lucy struct'.
    // What value should the next pointer in the 'lucy struct' have?
    harry->next = lucy;
    
    // Q10. TODO: Print out the zID of `lucy` by only using the `harry` variable.
    // printf("%d\n", harry->next->zID);
    
    // Q11. TODO: Add three more students after Lucy (link them together).
    // Student 3: name: Fatima, zID: 5222222, mark: 85.3
    // Student 4: name: Carlos, zID: 5333333, mark: 51.6
    // Student 5: name: Feng, zID: 5444444, mark: 93.4
    struct student *fatima = create_student(5222222, 85.3, "Fatima");
    struct student *carlos = create_student(5333333, 51.6, "Carlos");
    struct student *feng = create_student(5444444, 93.4, "Feng");
    lucy->next = fatima;
    fatima->next = carlos;
    carlos->next = feng;
    
    // Q12. TODO: Print the names of all students through the `harry` variable.
    // Alternatively, how can we do this with a while loop?
    
    /*struct student *curr = harry;
    while (curr != NULL) {
        printf("%s\n", curr->name);
        curr = curr->next;
    }*/
    
    print_students_tail(harry);
    
    return 0;
}
// Helper functions ------------------------------------------------------------

// Function that returns a pointer to a new student struct with the given
// zId, mark and name.
struct student *create_student(int zID, double mark, char *name) {
    struct student *new_student = malloc(sizeof(struct student));
    new_student->zID = zID;
    new_student->mark = mark;
    strcpy(new_student->name, name);
    new_student->next = NULL;
    return new_student;
}
// Q13. TODO: write a function that always print the name stored in the tail
// node of the linked list.
void print_students_tail(struct student *head) {
    if (head == NULL) {
        return;
    }

    struct student *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    // after the while loop ends, if the list was not empty, curr should be on
    // the last node in the linked list.
    printf("last name: %s\n", curr->name);
}
