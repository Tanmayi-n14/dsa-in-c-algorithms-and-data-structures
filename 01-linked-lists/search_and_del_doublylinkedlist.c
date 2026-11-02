#include <stdio.h>
#include <stdlib.h>


typedef struct dnode
{
	int info;
	struct dnode *left, *right;
} DNODE;


DNODE* frontins(DNODE*, int);
void display(DNODE*);
DNODE* searchAndDelete(DNODE*, int);


int main()
{
    DNODE *dlist = NULL;
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
                dlist = frontins(dlist, value);
                break;
            case 2:
                if (dlist == NULL) 
				{
                    printf("List is empty. Nothing to delete.\n");
                } 
				else 
				{
                    printf("Enter the value of the node to delete: ");
                    scanf("%d", &key);
                    dlist = searchAndDelete(dlist, key);
                }
                break;
            case 3:
                printf("Current List:");
                display(dlist);
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


DNODE* frontins(DNODE *dlist, int x)
{
	DNODE *newnode;

	newnode = (DNODE *)(malloc(sizeof(DNODE)));
	newnode->info = x;
	newnode->left = NULL;
	newnode->right = NULL;

	if (dlist == NULL) 
	{
        dlist = newnode;
    }
	else
	{
		newnode->right = dlist;
		dlist->left = newnode; 
		dlist = newnode;
	}
	return dlist;
}

void display(DNODE *dlist)
{
	DNODE *temp = dlist;
	while(temp != NULL)
	{
		printf("\t %d", temp->info);
		temp = temp->right;
	}
}

DNODE* searchAndDelete(DNODE *dlist, int key)
{
    DNODE *temp = dlist;

    if (dlist == NULL) 
	{
        printf("List is empty.\n");
        return NULL;
    }

    if (dlist->info == key) 
	{
        dlist = dlist->right; 
        if (dlist != NULL) 
		{
            dlist->left = NULL; 
        }
        free(temp);
        printf("Node with value %d deleted.\n", key);
        return dlist;
    }

    while (temp != NULL && temp->info != key) 
	{
        temp = temp->right;
    }

    if (temp == NULL) 
	{
        printf("Node with value %d not found.\n", key);
        return dlist;
    }

    if (temp->left != NULL) 
	{
        temp->left->right = temp->right;
    }

    if (temp->right != NULL) 
	{
        temp->right->left = temp->left;
    }

    printf("Node with value %d deleted.\n", key);
    free(temp);

    return dlist;
}