#include <stdio.h>
#include <stdlib.h>

typedef struct tree 
{
	int info;
	struct tree *left,*right;
}TREE;

TREE* create_exprtree(char[]);
void preorder(TREE *);
void inorder(TREE *);
void postorder(TREE *);
void push(TREE*);
TREE* pop();
int isoper(char);

TREE *stk[100];	
int top;

void main()
{
	char postfix[20];
	TREE *root=NULL;
	
	printf("Enter a valid postfix expression");
	scanf("%s",postfix);
	
	root=create_exprtree(postfix);
	
	printf("\nPreorder Traversal..");
	preorder(root);
	
	printf("\nInorder Traversal..");
	inorder(root);
	
	printf("\nPostorder Traversal..");
	postorder(root);
}

TREE* create_exprtree(char postfix[])
{
	char ch;
	int i = 0;
	top = -1;
	while (postfix[i] != '\0')
	{
        ch = postfix[i];
		TREE *temp = (TREE *)(malloc(sizeof(TREE)));
		temp->left = NULL;
		temp->right = NULL;
		temp->info = ch;
		
		if (isoper(ch))
		{
			temp->right = pop();
			temp->left = pop();
			push(temp); 
		}
		else 
        {
            push(temp);
        }
        i++; 
	}
	return pop();
}

  
void preorder(TREE *root)  
{
	if(root)
	{
		printf(" %c",root->info);
		preorder(root->left);
		preorder(root->right);
    }
	
}

void inorder(TREE *root)  
{
	if(root)
	{
		inorder(root->left);
		printf(" %c",root->info);
		inorder(root->right);
	}
}

void postorder(TREE *root)  
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf(" %c",root->info);
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

int isoper(char ch)
{
	switch(ch)
	{
		case'+':
		case'-':
		case'*':
		case'/':
		case'^': return 1;
		default: return 0;
		
	}
}