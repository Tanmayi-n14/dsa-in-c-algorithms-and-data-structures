#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	int info;
	struct tree *left, *right;
} TREE;
	
TREE* insert(TREE*, int);
void iterative_preorder(TREE*);
void push(TREE*);
TREE* pop();

TREE *stk[100];	
int top;
	
void main()
{
	TREE *root;
	int x, choice;
	root = NULL;

	while(1)
	{	
		printf("\nMENU\n1.Insertion\n2.Preorder\n3.Exit");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
			{
				printf("Enter the value to be inserted: ");
				scanf("%d", &x);
				root = insert(root, x);
			}
			break;

			case 2:
			{
                printf("The preorder tree traversal is...\n");
                iterative_preorder(root);
			}
			break;
			
			case 3:
                exit(0);

			default: 
                printf("Invalid choice.\n");
		}	
	}	
}

TREE* insert(TREE *root, int x)
{
	TREE *newnode, *temp;
	int flag=1;
	
	newnode = (TREE *)(malloc(sizeof(TREE)));
	newnode->info = x;
	newnode->left = NULL;
	newnode->right = NULL;
	
	if (root == NULL) 
	{
        root = newnode;
    }
	else
	{
		temp = root;
		while(flag)
		{	
			if (x < temp->info) 
			{
				if(temp->left == NULL) 
				{	
					temp->left = newnode;
					flag = 0;
				}	
				else
				{
					temp = temp->left;
                }
            }
			else if (x > temp->info) 
			{
				if(temp->right == NULL) 
				{	
					temp->right = newnode;
					flag = 0;
				}	
				else 
				{
					temp = temp->right;
                }
			}
            else {
                printf("Duplicate value, not inserted.\n");
                free(newnode);
                flag = 0;
            }				
		}		
	}
	return root;	
}

void iterative_preorder(TREE *root)
{
	TREE *temp;
	top = -1; 
	if (root == NULL)
	{
		printf("Tree is empty.\n");
		return;
	}
	
	push(root);
	
	while (top != -1)
	{
		temp = pop();
		printf("%d\t", temp->info);
		if (temp->right != NULL)
		{
			push(temp->right);
		}
		if (temp->left != NULL)
		{
			push(temp->left);
		}
	}	
}

void push(TREE *temp)
{
	top++;
	stk[top]=temp;
}

TREE* pop()
{
	TREE *temp;
	temp=stk[top];
	top--;
	return temp;	
}
