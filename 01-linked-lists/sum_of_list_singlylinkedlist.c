#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int info;
    struct node *next;
} NODE;


NODE* frontins(NODE*, int);
void display(NODE*);
int sum_all(NODE*);
void sum_alternate(NODE*);


int main() 
{
    NODE *list = NULL;
    int choice, value;

    while(1) 
	{ 
        printf("1. Insert at Front\n");
        printf("2. Display List\n");
        printf("3. Calculate Sum of All Elements\n");
        printf("4. Calculate Sum of Even/Odd Position Elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
		{
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                list = frontins(list, value);
                break;
            case 2:
                printf("Current List:");
                display(list);
                printf("\n"); 
                break;
            case 3:
                if (list == NULL) 
				{
                    printf("List is empty.\n");
                } 
				else 
				{
                    printf("The sum of all numbers is: %d\n", sum_all(list));
                }
                break;
            case 4:
                sum_alternate(list);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}


NODE* frontins(NODE *list, int x) 
{
    NODE *newnode;
    newnode = (NODE *)(malloc(sizeof(NODE)));
    if (newnode == NULL) 
	{
        printf("Memory allocation failed.\n");
        return list;
    }
    newnode->info = x;
    newnode->next = list;
    list = newnode;
    return list;
}


void display(NODE *list) 
{
    NODE *temp = list;
    if (temp == NULL) 
	{
        printf("\tList is empty.");
        return;
    }
    while (temp != NULL) 
	{
        printf("\t%d", temp->info);
        temp = temp->next;
    }
}


int sum_all(NODE *list) 
{
    int sum = 0;
    NODE *temp = list;
    while (temp != NULL) 
	{
        sum += temp->info;
        temp = temp->next;
    }
    return sum;
}


void sum_alternate(NODE *list) 
{
    if (list == NULL) 
	{
        printf("List is empty.\n");
        return;
    }
    int odd_pos_sum = 0;
    int even_pos_sum = 0;
    int position = 1;
    NODE *temp = list;

    while (temp != NULL) 
	{
        if (position % 2 != 0) 
		{ 
            odd_pos_sum += temp->info;
        } 
		else 
		{ 
            even_pos_sum += temp->info;
        }
        temp = temp->next;
        position++;
    }
    printf("Sum of numbers at odd positions: %d\n", odd_pos_sum);
    printf("Sum of numbers at even positions: %d\n", even_pos_sum);
}