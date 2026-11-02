#include <stdio.h>
#include <stdlib.h>

void insert(int);
void preorder(int);
void inorder(int);
void postorder(int);
int search(int);
void delete(int);

int t[100];
int i=0;
	
void main()
{
	int x,choice;

	while(1)
	{
		printf("Enter 1->Insertion\n2->PREORDER\n3->INORDER\n4->POSTORDER\n");
		printf("Enter 5->Search\n6->Delete\n7->EXIT\n");
		
		
		scanf("%d",&choice);
		 
		switch(choice)
		{
		    case 1: {
					printf("Enter the value to be inserted");
					scanf("%d", &x);
					insert(x);
					}break;
				
			case 2: {
				    preorder(i);
			        }break;
			case 3: {
					inorder(i);
				    }break;
			case 4: {
				    postorder(i);
			        }break;
					
			case 5: {
					printf("Enter the value to search: ");
					scanf("%d", &x);
					int res = search(x);
					if (res == -1)
						printf("Element not found.\n");
					else
						printf("Element %d found at index %d.\n", x, res);
					}break;
				
			case 6: {
					printf("Enter the value to delete: ");
					scanf("%d", &x);
					delete(x);
					}break;
	
			case 7:
					exit(0);		
			default: exit(0);	
		}
	}
}

void insert(int x)
{
	int i=0;
	while (t[i]!=0)
	{	
		if (x<t[i]) i=2*i+1;
		else if (x>t[i]) i=2*i+2;
	}
	t[i]=x;
}
  
void preorder(int i)
{
	if (t[i]!=0)
	{
		printf("\t%d",t[i]);
		preorder(2*i+1);
		preorder(2*i+2);
	}
}

void inorder(int i)
{
	if (t[i]!=0)
	{
		inorder(2*i+1);
		printf("\t%d",t[i]);
		inorder(2*i+2);
	}
}

void postorder(int i)
{
	if (t[i]!=0)
	{
		postorder(2*i+1);
		postorder(2*i+2);
		printf("\t%d",t[i]);
	}
}


int search(int key) 
{
    int i = 0;
    while (t[i] != 0) 
	{
        if (key == t[i]) 
		{
            return i; // Return index where element is found
        } 
		else if (key < t[i]) 
		{
            i = 2*i + 1;
        } 
		else 
		{
            i = 2*i + 2;
        }
    }
    return -1; // Not found
}



void delete(int key) 
{
    int i = 0, parent = -1;

    // Search for the node and keep track of parent
    while (t[i] != 0 && t[i] != key) 
	{
        parent = i;
        if (key < t[i])
            i = 2*i + 1;
        else
            i = 2*i + 2;
    }

    if (t[i] == 0) 
	{
        printf("Element not found.\n");
        return;
    }

    int left = 2*i + 1;
    int right = 2*i + 2;

    // Case 1: Node has no children (leaf)
    if (t[left] == 0 && t[right] == 0) 
	{
        t[i] = 0;
    }
    // Case 2: Node has only right child
    else if (t[left] == 0 && t[right] != 0) 
	{
        t[i] = t[right];
        t[right] = 0;
    }
    // Case 3: Node has only left child
    else if (t[left] != 0 && t[right] == 0) 
	{
        t[i] = t[left];
        t[left] = 0;
    }
    // Case 4: Node has two children (not implemented here)
    else 
	{
        printf("Delete of node with two children not supported in arrays.\n");
    }
}