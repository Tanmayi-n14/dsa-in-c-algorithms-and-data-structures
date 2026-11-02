#include <stdio.h>
#include <stdlib.h>

typedef struct dnode
{
	int info;
	struct dnode *left, *right;
} DNODE;


DNODE* prednodeins(DNODE *dlist, int x, int pred_val);
DNODE* prednodedel(DNODE *dlist, int pred_val);
DNODE* frontins(DNODE *dlist,int x);
void display(DNODE *dlist);


int main()
{
    DNODE *dlist = NULL;
    int choice, value, pred_val;

    while(1)
    {
        printf("1. Insert at Front\n");
        printf("2. Insert after a Predecessor Node\n");
        printf("3. Delete after a Predecessor Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the value to insert at the front: ");
                scanf("%d", &value);
                dlist = frontins(dlist, value);
                break;
            case 2:
                printf("Enter the value of the predecessor node: ");
                scanf("%d", &pred_val);
                printf("Enter the new value to insert: ");
                scanf("%d", &value);
                dlist = prednodeins(dlist, value, pred_val);
                break;
            case 3:
                printf("Enter the value of the predecessor node: ");
                scanf("%d", &pred_val);
                dlist = prednodedel(dlist, pred_val);
                break;
            case 4:
                printf("Current List: ");
                display(dlist);
                printf("\n"); 
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


DNODE* frontins(DNODE *dlist,int x)
{
	DNODE *newnode;

	newnode = (DNODE *)(malloc(sizeof(DNODE)));
	newnode->info=x;
	newnode->left=NULL;
	newnode->right=NULL;

	if (dlist==NULL) 
	{
		dlist=newnode;
	}	
	else
	{
		newnode->right=dlist;
		dlist->left=newnode; 
		dlist=newnode;
	}
	return dlist;
}

void display(DNODE *dlist)
{
	DNODE *temp=dlist;
	while(temp!=NULL)
	{
		printf("\t %d", temp->info);
		temp=temp->right;
	}
}


DNODE* prednodeins(DNODE *dlist, int x, int pred_val)
{
    DNODE *newnode, *temp;

    newnode = (DNODE *)(malloc(sizeof(DNODE)));
    newnode->info = x;
    newnode->left = NULL;
    newnode->right = NULL;

    if (dlist == NULL) 
	{
        printf("List is empty, cannot find predecessor. Inserting as first node.\n");
        return newnode;
    }

    temp = dlist;
    while(temp != NULL && temp->info != pred_val) 
	{
        temp = temp->right;
    }

    if (temp != NULL) 
	{
        newnode->right = temp->right;
        newnode->left = temp;
        if (temp->right != NULL) 
		{
            (temp->right)->left = newnode;
        }
        temp->right = newnode;
    } 
	else 
	{
        printf("Predecessor node with value %d not found.\n", pred_val);
        free(newnode);
    }
    return dlist;
}

DNODE* prednodedel(DNODE *dlist, int pred_val)
{
    DNODE *pred_node, *target_node;

    if (dlist == NULL) 
	{
        printf("List is empty.\n");
        return NULL;
    }

    pred_node = dlist;
    while(pred_node != NULL && pred_node->info != pred_val) 
	{
        pred_node = pred_node->right;
    }

    if (pred_node != NULL && pred_node->right != NULL) 
	{
        target_node = pred_node->right;
        pred_node->right = target_node->right;
        if (target_node->right != NULL) 
		{
            (target_node->right)->left = pred_node;
        }
        printf("Deleted node with value: %d\n", target_node->info);
        free(target_node);
    } 
	else if (pred_node == NULL) 
	{
        printf("Predecessor node with value %d not found.\n", pred_val);
    } 
	else 
	{
        printf("Predecessor node is the last node, nothing to delete after it.\n");
    }
    return dlist;
}