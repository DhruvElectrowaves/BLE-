/******************************************************   
Create a doubly linked list with about 5 entries using the following
structure. Insert a new entry before or after a given id. Delete an
entry of a given id.

    Menu Items
        1. Insert Entry
        2. Delete Entry
        3. Display List
        4. Exit
        
    struct student {
    struct student *prev;
    int id;
    int Maths;
    int Science;
    struct student *next;
    }
*********************************************************/
#include<stdio.h>
#include<stdint.h>

struct student 
{
int id;
int Maths;
int Science;
struct student *next, *prev;
}
struct student *newnode, *head, *tail, *temp;
int Position , i , choice=1 ;

void createLinkedList()
{
    while(choice==1)
  {
    newnode = (struct student*)malloc(sizeof(struct student));
   
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;  // Exit if memory allocation fails
    }
   
    // Taking the input for the node
    printf("\n Enter the id of Student (Except -1 to exit ) : ");
    scanf( "%d" , &newnode->id);
   
    if(newnode->id == -1)
     {
        free(newnode);  // This newnode is dynamically allocated
        choice =-1;
        break;
     }    
    printf("\n Marks of Maths : ");
    scanf( "%d" , &newnode->Maths);
   
    printf("\n Marks of Science : ");
    scanf("%d" , &newnode->Science);
   
    newnode->next = NULL;
    newnode->prev = NULL;
    count++;
    if(head==NULL)
    {
        head = newnode;
        tail = newnode;
        temp = newnode;
    }
    else
    {
        temp->next=newnode;
        newnode->prev = temp ;
        tail = newnode ;
        temp = newnode;
    }
  }
} // end of createLinkedList()

void displayDLL()
{
    temp = head;
while(temp!=0)
{
printf("\n The id of the Student :  %d" , temp->id);
printf("\n The Maths Marks of the Student :  %d" , temp->Maths);
printf("\n The Science Marks of the Student :  %d" , temp->Science);
temp=temp->next;
}
printf("\n The total number of Students :  %d" , count);
} // end of displayDLL()




























int main()
{
// ------------- Create A linked list --------
createDLL();  // This Function creates the Doubly Linked List     
printf("Welcome to the Problem Statement 59 \n ");
printf("Please Enter the Choice that you would like to make");
printf("\n 1. Insert Entry");
printf("\n 2. Delete Entry");
printf("\n 3. Display Entry");
printf("\n 4. Exit ");
scanf("%d", &choice);

    switch(choice) 
    {
        case 1 :
        printf("\n Choose Any Option : ");
        scanf("%d" , &i);
        if(i==1)
        insertAtBeginning();
        else if(i==2)
        insertAtEnd();
        else if(i==3)
        insertAtPos();
        else
        insertAtAnyPosition();
        displayDLL();
        break;
        
      case 2 :
          printf("Yet to be Written");
          break;

      case 3 :
         displayDLL();
         break;

      default :
        printf("\n Cant be Run");
        break;     
    }       
 
//createDLL();  // This Function creates the Doubly Linked List
//displayDLL(); // This is used to display the Linked List
//insertAtBeginning();  //This is used to insert at the Beginning 
//insertAtEnd(); // This is inserting at the end.
//insertAtPos(); //This is to insert at the specified position.
//insertAtAnyPosition(); //This is to insert after the specified position.   
}









