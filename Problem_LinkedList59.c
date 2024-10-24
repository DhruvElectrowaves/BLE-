#include<stdio.h>
#include<stdlib.h>

// Structure for student node
struct student {
    int id;
    int Maths;
    int Science;
    struct student *next, *prev;
};

// Global variables for the list
struct student *head = NULL, *tail = NULL;
int count = 0;

// Function to create the initial linked list
void createLinkedList() {
    int choice = 1;
    while (choice == 1) {
        struct student *newnode = (struct student*)malloc(sizeof(struct student));
        
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        
        // Taking input for the new node
        printf("\nEnter the ID of Student (Enter -1 to exit): ");
        scanf("%d", &newnode->id);
        
        if (newnode->id == -1) {
            free(newnode);
            break;
        }
        
        printf("Enter the Maths marks: ");
        scanf("%d", &newnode->Maths);
        
        printf("Enter the Science marks: ");
        scanf("%d", &newnode->Science);
        
        newnode->next = NULL;
        newnode->prev = NULL;
        
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        count++;
    }
}

// Function to display the doubly linked list
void displayDLL() {
    struct student *temp = head;
    if (temp == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    printf("\nList of students:\n");
    while (temp != NULL) {
        printf("ID: %d, Maths: %d, Science: %d\n", temp->id, temp->Maths, temp->Science);
        temp = temp->next;
    }
    printf("Total number of students: %d\n", count);
}

// Function to insert an entry after a given ID
void insertAfter(int id) {
    struct student *newnode = (struct student*)malloc(sizeof(struct student));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter the new student's ID: ");
    scanf("%d", &newnode->id);
    printf("Enter the Maths marks: ");
    scanf("%d", &newnode->Maths);
    printf("Enter the Science marks: ");
    scanf("%d", &newnode->Science);

    struct student *temp = head;
    while (temp != NULL && temp->id != id) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with ID %d not found.\n", id);
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newnode;
    } else {
        tail = newnode;  // Update the tail if inserted at the end
    }
    temp->next = newnode;
    count++;
}

// Function to delete an entry by ID
void deleteByID(int id) {
    struct student *temp = head;
    while (temp != NULL && temp->id != id) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;  // Update head if deleting the first node
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev;  // Update tail if deleting the last node
    }

    free(temp);
    count--;
    printf("Student with ID %d deleted.\n", id);
}

// Main function with menu
int main() {
    int choice, id;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Entry\n");
        printf("2. Delete Entry\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the ID after which to insert: ");
                scanf("%d", &id);
                insertAfter(id);
                break;
            case 2:
                printf("Enter the ID to delete: ");
                scanf("%d", &id);
                deleteByID(id);
                break;
            case 3:
                displayDLL();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
