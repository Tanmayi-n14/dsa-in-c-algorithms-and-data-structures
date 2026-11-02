#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int info;
	struct tree *left,*right;
} TREE;

TREE* insert(TREE*, int);
void preorder(TREE*);
void inorder(TREE*);
void postorder(TREE*);

void main()
{
    TREE *root = NULL;
	int x, choice;
	
	while(1)
	{
		printf("Enter 1->Insertion\n2->PREORDER\n3->INORDER\n4->POSTORDER\n5->EXIT\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: 
            {
				printf("Enter the value to insert: ");
				scanf("%d", &x);
				root = insert(root, x);
			}
            break;

			case 2: 
            {
                if (root == NULL) printf("Tree is empty.\n");
                else {
				    printf("Preorder traversal:");
				    preorder(root);
                    printf("\n");
                }
			}
            break;

			case 3: 
            {
                if (root == NULL) printf("Tree is empty.\n");
                else {
				    printf("Inorder traversal:");
					inorder(root);
                    printf("\n");
                }
			}
            break;

			case 4: 
            {
                if (root == NULL) printf("Tree is empty.\n");
                else {
				    printf("Postorder traversal:");
				    postorder(root);
                    printf("\n");
                }
			}
            break;
            
			case 5:
				exit(0);

			default: 
                printf("Invalid choice. Please try again.\n");
		}
	}
}


TREE* insert(TREE *root, int x)
{
	if (root == NULL) 
	{
        TREE* newnode = (TREE*)malloc(sizeof(TREE));
        newnode->info = x;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }

    if (x < root->info) 
	{
        root->left = insert(root->left, x);
    } 
    else if (x > root->info) 
	{
        root->right = insert(root->right, x);
    }
    else 
	{
        printf("Error: Duplicate value %d already exists. Please enter a different number.\n", x);
    }
	return root;
}

void preorder(TREE *root)  
{
	if(root)
	{
		printf("\t%d", root->info);
		preorder(root->left);
		preorder(root->right);
    }
}

void inorder(TREE *root)  
{
	if(root)
	{
		inorder(root->left);
		printf("\t%d", root->info);
		inorder(root->right);
	}
}

void postorder(TREE *root)  
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("\t%d", root->info);
	}
}