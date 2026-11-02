#include <stdio.h>
#include <stdlib.h>


typedef struct node 
{
    int info;
    struct node* next;
} NODE;

NODE* queue_head = NULL;

void enqueue();
void dequeue();
void display();


int main() 
{
    int choice;

    while (1) 
	{
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
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


void enqueue() 
{
    int x;
    NODE *newnode, *temp;

    printf("Enter the element to enqueue: ");
    scanf("%d", &x);

    newnode = (NODE *)(malloc(sizeof(NODE)));
    if (newnode == NULL) 
	{
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->info = x;
    newnode->next = NULL;


    if (queue_head == NULL) 
	{
        queue_head = newnode;
    }

    else 
	{
        temp = queue_head;
        while (temp->next != NULL) 
		{
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("%d enqueued to the queue.\n", x);
}


void dequeue() 
{
    NODE *temp;

    if (queue_head == NULL) 
	{
        printf("Empty Queue! Cannot dequeue.\n");
    }
    else 
	{
        temp = queue_head;
        printf("Element removed from queue is %d\n", temp->info);
        queue_head = queue_head->next;
        free(temp);
    }
}


void display() 
{
    NODE *temp = queue_head;

    if (temp == NULL) 
	{
        printf("Queue is empty.\n");
        return;
    }

    printf("Contents of queue are ...\n");
    while (temp != NULL) 
	{
        printf("\t%d", temp->info);
        temp = temp->next;
    }
    printf("\n");
}