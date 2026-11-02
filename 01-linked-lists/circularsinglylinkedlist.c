#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} NODE;

NODE* frontins(NODE *, int);
NODE* endins(NODE *, int);
void display(NODE *);
NODE* frontdel(NODE *);
NODE* enddel(NODE *);
NODE* posins(NODE *, int, int);
NODE* posdel(NODE *, int);
NODE* orderedins(NODE *, int);

int main()
{
    NODE *list = NULL;
    int choice, x, pos;

    while(1)
    {
        printf("Enter 1-> Front insertion\n2->End insertion\n3->Display\n");
		printf("4-> Front deletion\n5->End deletion\n6->Position insertion\n");
		printf("7-> Position deletion\n8->Ordered insertion\n9->Exit\n");
		
		scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &x);
                list = frontins(list, x);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &x);
                list = endins(list, x);
                break;

            case 3:
                printf("List contents: ");
                display(list);
                break;

            case 4:
                list = frontdel(list);
                break;

            case 5:
                list = enddel(list);
                break;

            case 6:
                printf("Enter value and position: ");
                scanf("%d %d", &x, &pos);
                list = posins(list, x, pos);
                break;

            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                list = posdel(list, pos);
                break;

            case 8:
                printf("Enter value to insert in order: ");
                scanf("%d", &x);
                list = orderedins(list, x);
                break;

            case 9:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// Front insertion
NODE* frontins(NODE *list, int x)
{
    NODE *newnode, *temp;

    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = x;

    if (list == NULL)
    {
        newnode->next = newnode;  // Points to itself
        list = newnode;
    }
    else
    {
        temp = list;
        while (temp->next != list)
            temp = temp->next;

        newnode->next = list;
        temp->next = newnode;
        list = newnode;
    }
    return list;
}

// End insertion
NODE* endins(NODE *list, int x)
{
    NODE *newnode, *temp;

    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = x;

    if (list == NULL)
    {
        newnode->next = newnode;
        list = newnode;
    }
    else
    {
        temp = list;
        while (temp->next != list)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = list;
    }
    return list;
}

void display(NODE *list)
{
    if (list == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    NODE *temp = list;
    printf("%d ", temp->info);
    temp = temp->next;

    while (temp != list)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

// Front deletion
NODE* frontdel(NODE *list)
{
    if (list == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    if (list->next == list)
    {
         free(list);  // free the only node
        return NULL;
    }

    NODE *temp = list;
    NODE *last = list;

    while (last->next != list)
        last = last->next;

    last->next = list->next;
    list = list->next;
    free(temp);

    return list;
}

// End deletion
NODE* enddel(NODE *list)
{
    if (list == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    if (list->next == list)
    {
        free(list);  // free the only node
        return NULL;
    }

    NODE *temp = list;
    NODE *prev = NULL;

    while (temp->next != list)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = list;
    free(temp);

    return list;
}


// Position insertion (without calling frontins)
NODE* posins(NODE *list, int x, int pos)
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = x;

    // Insert at position 1 (front insertion)
    if (pos == 1)
    {
        if (list == NULL)
        {
            newnode->next = newnode;
            return newnode;
        }
        else
        {
            NODE *temp = list;
            // Find last node to fix circular link
            while (temp->next != list)
                temp = temp->next;

            temp->next = newnode;
            newnode->next = list;
            return newnode;  // New node is new head
        }
    }

    // Insert at position > 1
    if (list == NULL)
    {
        // Can't insert at pos > 1 in empty list
        printf("Invalid position\n");
        free(newnode);
        return NULL;
    }

    NODE *temp = list;
    int i = 1;

    // Move temp to node before position to insert
    while (i < pos - 1 && temp->next != list)
    {
        temp = temp->next;
        i++;
    }

    // Check if position is valid
    if (i + 1 == pos )
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else
    {
        printf("Invalid position\n");
        free(newnode);
    }

    return list;
}


// Position deletion (without calling frontdel)
NODE* posdel(NODE *list, int pos)
{
    if (list == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    // Delete at position 1 (front deletion)
    if (pos == 1)
    {
        // Only one node in list
        if (list->next == list)
        {
            free(list);
            return NULL;
        }
        else
        {
            NODE *last = list;
            // Find last node
            while (last->next != list)
                last = last->next;

            NODE *temp = list;
            last->next = list->next;
            list = list->next;
            free(temp);

            return list;
        }
    }

    // Delete at position > 1
    NODE *temp = list;
    NODE *prev = NULL;
    int i = 1;

    while (i < pos && temp->next != list)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }

    // If position is last node and i < pos (meaning pos out of bounds)
    if (i != pos)
    {
        printf("Invalid position\n");
        return list;
    }

    // Remove temp node
    prev->next = temp->next;
    free(temp);

    return list;
}


// Ordered insertion 
NODE* orderedins(NODE *list, int x)   //here it can be used using other ins also bcos its circular
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = x;

    // Empty list: create new node pointing to itself
    if (list == NULL)
    {
        newnode->next = newnode;
        return newnode;
    }

    NODE *current = list;

    // New node to be inserted before the head node (smallest)
    if (x < list->info)
    {
        // Find last node to fix circular link
        while (current->next != list)
            current = current->next;

        current->next = newnode;
        newnode->next = list;
        return newnode;  // New node is new head
    }

    // Otherwise, find correct position in list
    while (current->next != list && current->next->info < x)
    {
        current = current->next;
    }

    newnode->next = current->next;
    current->next = newnode;

    return list;
}
