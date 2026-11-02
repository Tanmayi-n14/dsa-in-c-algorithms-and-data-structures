#include <stdio.h>
#include <stdlib.h>

typedef struct dnode
{
	int info;
	struct dnode *left, *right;
}DNODE;


DNODE* frontins(DNODE *dlist,int x);
DNODE* posins(DNODE *dlist, int x, int pos);
DNODE* posdel(DNODE *dlist, int pos);
void display(DNODE *dlist);


int main()
{
    DNODE *dlist = NULL;
    int choice, x, pos;

    while(1) 
    {
        printf("1. Insert at Front\n");
        printf("2. Insert at a position\n");
        printf("3. Delete from a position\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
			case 1:
			{
				printf("Enter the value to be inserted");
				scanf("%d",&x);
				dlist=frontins(dlist,x);
			}break;

			case 2:
			{
				printf("Enter the value to be inserted & position\n");
				scanf("%d %d", &x, &pos);
				dlist = posins(dlist, x, pos);
			}break;

			case 3:
			{
				printf("Enter the position of the value to be deleted\n");
				scanf("%d", &pos);
				dlist = posdel(dlist, pos);
			}break;

            case 4:
                printf("Current List:");
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
		dlist->left = newnode;
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


DNODE* posins(DNODE *dlist, int x, int pos)
{
	DNODE *newnode, *temp, *prev;
	int i=1;

	newnode = (DNODE *)(malloc(sizeof(DNODE)));
	newnode->info=x;
	newnode->left=NULL;
	newnode->right=NULL;

	if (dlist==NULL) 
	{
		dlist=newnode;
	}
	else if(pos==1)
	{
		newnode->right = dlist;
		dlist->left = newnode;
		dlist = newnode;
	}
	else
	{
		temp=dlist;
        prev = dlist;
		while(temp->right!=NULL && i < pos)
		{
			prev=temp;
			temp=temp->right;
			i++;
		}

		if (i==pos)
		{
			newnode->right = prev->right;
			newnode->left = prev;

			if (prev->right != NULL) 
			{
				(prev->right)->left = newnode;
			}
			prev->right = newnode;
		}
		else if (i+1==pos)
		{
			temp->right=newnode;
			newnode->left = temp;
		}
		else
		{
			printf("Invalid position for insertion.\n");
		}
	}
	return dlist;
}

DNODE* posdel(DNODE *dlist, int pos)
{
    DNODE *temp;
    int i=1;

    if (dlist==NULL) 
	{
        printf("Empty list\n");
        return NULL;
    }

    if(pos==1)
    {
        temp = dlist;
        dlist = dlist->right;
        if (dlist != NULL) 
		{
            dlist->left = NULL;
        }
    }
    else
    {
        temp=dlist;
        while(temp != NULL && i < pos)
        {
            temp=temp->right;
            i++;
        }

        if (temp == NULL)
        {
            printf("Invalid position for deletion.\n");
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
    }

    printf("Deleted element: %d\n", temp->info);
    free(temp);

    return dlist;
}