/* Write a program create a stack using linked list. Use push & Pop. Push
will insert the entry in top of the list. Pop will get top of the list and
display. Display will show from top to bottom.
Menu Items
1. Push
2. Pop
3. Display Stack
4. Exit
struct student {
int id;
int Maths;
int Science;
struct student *next; */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for the student
struct student {
    int id;
    int Maths;
    int Science;
    struct student *next;
};

// Function prototypes
void push();
void pop();
void display();
int menu();

// Global pointer to the top of the stack
struct student *top = NULL;

int main() {
    int choice;

    do {
        choice = menu();
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Menu to choose stack operations
int menu() {
    int choice;
    printf("\n----- Stack Menu -----\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display Stack\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Push function to add a new node (student) at the top of the stack
void push() {
    struct student *newnode = (struct student*)malloc(sizeof(struct student));

    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Input data for the new student
    printf("Enter the ID of the student: ");
    scanf("%d", &newnode->id);
    printf("Enter the Maths marks: ");
    scanf("%d", &newnode->Maths);
    printf("Enter the Science marks: ");
    scanf("%d", &newnode->Science);

    // Link the new node to the current top
    newnode->next = top;

    // Make the new node the new top of the stack
    top = newnode;

    printf("Student pushed onto the stack.\n");
}

// Pop function to remove and display the top node (student) from the stack
void pop() {
    if (top == NULL) {
        printf("Stack is empty! No student to pop.\n");
        return;
    }

    // Remove the top node
    struct student *temp = top;
    printf("Popping student with ID: %d\n", temp->id);
    printf("Maths marks: %d\n", temp->Maths);
    printf("Science marks: %d\n", temp->Science);

    top = top->next;
    free(temp);

    printf("Student popped from the stack.\n");
}

// Display function to show all students in the stack from top to bottom
void display() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Displaying stack (top to bottom):\n");
    struct student *temp = top;
    while (temp != NULL) {
        printf("\nID: %d\n", temp->id);
        printf("Maths marks: %d\n", temp->Maths);
        printf("Science marks: %d\n", temp->Science);
        temp = temp->next;
    }
}
