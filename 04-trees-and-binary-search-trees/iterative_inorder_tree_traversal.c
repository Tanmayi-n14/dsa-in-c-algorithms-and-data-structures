#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	int info;
	struct tree *left, *right;
}TREE;
	
TREE* insert(TREE *,int);
void iterative_inorder(TREE *);
void push(TREE *);
TREE* pop();

//global variables
TREE *stk[100];	
int top;
	
void main()
{ 
	TREE *root;
	int x,choice;
	root=NULL;

	while(1)
	{	
		printf("\nMENU\n1.Insertion\n2.Inorder\n3.Exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
			{
				printf("Enter the value to be inserted : ");
				scanf("%d",&x);
				root=insert(root,x);
			}
			break;

			case 2: 
			{
				printf("The inorder tree traversal is... \n");
				iterative_inorder(root);
			}
			break;
			
			default: exit(0);
		}	
	}	
}

TREE* insert(TREE *root,int x)   //this insertion is aka lexical insertion
{
	TREE *newnode, *temp;
	int flag=1;
	
	newnode = (TREE *)(malloc(sizeof(TREE)));
	newnode->info=x;
	newnode->left=NULL;
	newnode->right=NULL;
	
	if (root==NULL) root=newnode;
	else 
	{
		temp=root;
		while(flag)
		{	
			if (x<temp->info)
				if(temp->left==NULL)
				{	
					temp->left=newnode;
					flag=0;
				}	
				else 
					temp=temp->left;
			else
			{
				if(temp->right==NULL)
				{	
					temp->right=newnode;
					flag=0;
				}	
				else 
					temp=temp->right;
			}				
		}		
	}
	return root;	
}

void iterative_inorder(TREE *root)
{
	TREE *temp=root;
	top=-1;
	
	while (temp!=NULL)
	{
		push(temp);
		temp=temp->left;
	}
	
	while (top!=-1)
	{
		temp=pop();
		printf("%d\t",temp->info);

		if (temp->right!=NULL)
		{
			temp=temp->right;
			
			while (temp!=NULL)
			{
				push(temp);
				temp=temp->left;
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