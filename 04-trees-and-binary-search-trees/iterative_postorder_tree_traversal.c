#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	int info;
	struct tree *left, *right;
} TREE;
	
TREE* insert(TREE*, int);
void iterative_postorder(TREE*);
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
		printf("\nMENU\n1.Insertion\n2.Postorder\n3.Exit");
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
                printf("The postorder tree traversal is...\n");
                iterative_postorder(root);
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
            else
			{
                printf("Duplicate value, not inserted.\n");
                free(newnode);
                flag = 0;
            }				
		}		
	}
	return root;	
}

void iterative_postorder(TREE *root)
{
	if (root == NULL) 
	{
		printf("Tree is empty.\n");
		return;
	}
	
	top = -1;
	TREE *current = root;
	TREE *last_visited = NULL;
	
	while (current != NULL || top != -1) 
	{
		if (current != NULL) 
		{
			push(current);
			current = current->left;
		}
		else
		{
			TREE *peek_node = stk[top];
			if (peek_node->right != NULL && peek_node->right != last_visited) 
			{
				current = peek_node->right;
			}

			else 
			{
				pop();
				printf("%d\t", peek_node->info);
				last_visited = peek_node;
			}
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
