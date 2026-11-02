#include <stdio.h>
#include <stdlib.h>

typedef struct dnode 
{
    int info;
    struct dnode *left, *right;
} DNODE;

DNODE* frontins(DNODE *, int);
DNODE* endins(DNODE *, int);
void display(DNODE *);
DNODE* frontdel(DNODE *);
DNODE* enddel(DNODE *);
DNODE* posins(DNODE *, int, int);
DNODE* posdel(DNODE *, int);

int main() if w =  then |w| = ?
{
    DNODE *dlist = NULL;
    int x, choice, pos;

    while (1) 
	{
        printf("\nMenu:\n");
        printf("1 -> Front insertion\n2 -> End insertion\n3 -> Display\n");
        printf("4 -> Front deletion\n5 -> End deletion\n");
        printf("6 -> Position insertion\n7 -> Position deletion\n");
        printf("8 -> Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
		{
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &x);
                dlist = frontins(dlist, x);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &x);
                dlist = endins(dlist, x);
                break;
            case 3:
                printf("List contents: ");
                display(dlist);
                break;
            case 4:
                dlist = frontdel(dlist);
                break;
            case 5:
                dlist = enddel(dlist);
                break;
            case 6:
                printf("Enter value to insert & position: ");
                scanf("%d %d", &x, &pos);
                dlist = posins(dlist, x, pos);
                break;
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                dlist = posdel(dlist, pos);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

// Front insertion
DNODE* frontins(DNODE *dlist, int x) 
{
    DNODE *newnode = (DNODE *)malloc(sizeof(DNODE));
    newnode->info = x;
    if (dlist == NULL) 
	{
        newnode->left = newnode->right = newnode;
        dlist = newnode;
    } 
	else 
	{
        DNODE *last = dlist->left;
        newnode->right = dlist;
        newnode->left = last;
        last->right = newnode;
        dlist->left = newnode;
        dlist = newnode;  // newnode becomes new head
    }
    return dlist;
}

// End insertion
DNODE* endins(DNODE *dlist, int x) 
{
    DNODE *newnode = (DNODE *)malloc(sizeof(DNODE));
    newnode->info = x;
    if (dlist == NULL) 
	{
        newnode->left = newnode->right = newnode;
        dlist = newnode;
    } 
	else 
	{
        DNODE *last = dlist->left;
        newnode->right = dlist;
        newnode->left = last;
        last->right = newnode;
        dlist->left = newnode;
        // head remains same
    }
    return dlist;
}

void display(DNODE *dlist) 
{
    if (dlist == NULL) 
    {
        printf("List is empty\n");
        return;
    }

    DNODE *temp = dlist;
    
    while (temp != NULL) 
    {
        printf("%d ", temp->info);
        temp = temp->right;

        if (temp == dlist)  // Came full circle
            break;
    }

    printf("\n");
}


// Front deletion
DNODE* frontdel(DNODE *dlist) 
{
    if (dlist == NULL) 
	{
        printf("Empty list\n");
        return NULL;
    }
    if (dlist->right == dlist) 
	{  // Only one node
        free(dlist);
        return NULL;
    }
    DNODE *last = dlist->left;
    DNODE *temp = dlist;
    dlist = dlist->right;
    last->right = dlist;
    dlist->left = last;
    free(temp);
    return dlist;
}

// End deletion
DNODE* enddel(DNODE *dlist) 
{
    if (dlist == NULL) 
	{
        printf("Empty list\n");
        return NULL;
    }
    if (dlist->right == dlist) 
	{  // Only one node
        free(dlist);
        return NULL;
    }
    DNODE *last = dlist->left;
    DNODE *secondLast = last->left;
    secondLast->right = dlist;
    dlist->left = secondLast;
    free(last);
    return dlist;
}

// Position insertion

// Position Insertion
DNODE* posins(DNODE *dlist, int x, int pos) 
{
    if (pos < 1) 
    {
        printf("Invalid position\n");
        return dlist;
    }

    // Create new node
    DNODE *newnode = (DNODE *)malloc(sizeof(DNODE));
    newnode->info = x;

    // Case 1: Empty list and inserting at position 1
    if (dlist == NULL) 
    {
        if (pos == 1) 
        {
            newnode->left = newnode;
            newnode->right = newnode;
            return newnode;
        } 
        else 
        {
            printf("Invalid position: list is empty\n");
            free(newnode);
            return dlist;
        }
    }

    // Case 2: Insert at front (position 1)
    if (pos == 1) 
    {
        DNODE *last = dlist->left;

        newnode->right = dlist;
        newnode->left = last;

        last->right = newnode;
        dlist->left = newnode;

        dlist = newnode;  // Update head
        return dlist;
    }

    // Case 3: Insert at position > 1
    DNODE *temp = dlist;
    int i = 1;

    while (i < pos - 1 && temp->right != dlist) 
    {
        temp = temp->right;
        i++;
    }

    if (i == pos - 1) 
    {
        DNODE *next = temp->right;

        newnode->right = next;
        newnode->left = temp;

        temp->right = newnode;
        next->left = newnode;

        return dlist;
    }
    else 
    {
        printf("Invalid position\n");
        free(newnode);
        return dlist;
    }
}





// Position deletion
DNODE* posdel(DNODE *dlist, int pos) 
{
    if (dlist == NULL) 
    {
        printf("Empty list\n");
        return NULL;
    }

    if (pos < 1) 
    {
        printf("Invalid position\n");
        return dlist;
    }

    DNODE *temp = dlist;
    int i = 1;

    // Traverse to the node at position
    while (i < pos && temp->right != dlist) 
    {
        temp = temp->right;
        i++;
    }

    if (i < pos) 
    {
        printf("Invalid position\n");
        return dlist;
    }

    // Only one node in the list
    if (temp->left == temp && temp->right == temp) 
    {
        free(temp);
        return NULL;
    }

    // If deleting head node
    if (temp == dlist) 
    {
        DNODE *last = dlist->left;
        dlist = dlist->right;

        last->right = dlist;
        dlist->left = last;
    } 
    else 
    {
        temp->left->right = temp->right;
        temp->right->left = temp->left;
    }

    free(temp);
    return dlist;
}
