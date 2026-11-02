#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int info;
	struct node *next;
} NODE;
	

NODE* frontins(NODE*, int);
void display(NODE*);
NODE* searchAndDelete(NODE*, int);


int main()
{
    NODE *list = NULL;
    int choice, value, key;

    while(1)
    {
        printf("1. Insert at Front\n");
        printf("2. Search and Delete a Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
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
                if (list == NULL) 
				{
                    printf("List is empty. Nothing to delete.\n");
                }
				else 
				{
                    printf("Enter the value of the node to delete: ");
                    scanf("%d", &key);
                    list = searchAndDelete(list, key);
                }
                break;
            case 3:
                printf("Current List:");
                display(list);
                printf("\n"); 
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


NODE* frontins(NODE *list, int x)
{
	NODE *newnode;
	
	newnode = (NODE *)(malloc(sizeof(NODE)));
	newnode->info=x;
	newnode->next=NULL;
	
	if (list==NULL) 
	{
        list=newnode;
    }
	else 
	{
		newnode->next=list;
		list=newnode;
	}
	return list;	
}

void display(NODE *list)
{
	NODE *temp=list;
	while(temp!=NULL)
	{
		printf("\t %d", temp->info);
		temp=temp->next;
	}
}

NODE* searchAndDelete(NODE *list, int key) 
{
    NODE *current = list;
    NODE *prev = NULL;

    if (current != NULL && current->info == key) 
    {
        list = current->next; 
        printf("Node with value %d deleted.\n", key);
        free(current); 
        return list;
    }

    while (current != NULL && current->info != key) 
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL) 
	{
        printf("Node with value %d not found.\n", key);
        return list;
    }

    prev->next = current->next;
    printf("Node with value %d deleted.\n", key);
    free(current); 

    return list;
}