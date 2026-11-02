#include <stdio.h>
#include <stdlib.h>


typedef struct node 
{
    int info;
    struct node* next;
} NODE;


NODE* top = NULL;


void push();
void pop();
void display();


int main() 
{
    int choice;
    
    while (1) 
	{
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
		{
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
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}



void push() 
{
    int x;
    printf("Enter the element to push: ");
    scanf("%d", &x);

    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    if (newnode == NULL) 
	{
        printf("Memory allocation failed!\n");
        return;
    }
    
    newnode->info = x;
    newnode->next = top;
    top = newnode;
    printf("%d pushed to stack.\n", x);
}


void pop() 
{
    if (top == NULL) 
	{
        printf("Stack is empty!\n");
        return;
    }
    
    NODE* temp = top;
    printf("%d popped from stack.\n", temp->info);
    top = top->next;
    free(temp);
}


void display() 
{
    if (top == NULL) 
	{
        printf("Stack is empty.\n");
        return;
    }
    
    NODE* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) 
	{
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}
