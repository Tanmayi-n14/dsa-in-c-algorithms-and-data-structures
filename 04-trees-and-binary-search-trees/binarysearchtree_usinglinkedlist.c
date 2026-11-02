#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int info;
	struct tree *left,*right;
}TREE;


TREE* insert(TREE*,int);
void preorder(TREE *);
void inorder(TREE *);
void postorder(TREE *);
int search(TREE*,int);
TREE* bst_delete(TREE *,int);

void main()
{
    TREE *root;
	int x,choice;
	
	root=NULL;
	while(1)
	{
		printf("Enter 1->Insertion\n2->PREORDER\n3->INORDER\n4->POSTORDER\n");
		printf("Enter 5->Search\n6->Delete\n7->EXIT\n");
		
		scanf("%d",&choice);
		 
		switch(choice)
		{
			case 1: {
					printf("Enter the value ");
					scanf("%d", &x);
					root=insert(root,x);
					}break;
			case 2: {
				    preorder(root);
			        }break;
			case 3: {
					inorder(root);
				    }break;
			case 4: {
				    postorder(root);
			        }break;
			case 5: {
					printf("Enter the key value to search");
					scanf("%d", &x);
					x=search(root,x);
					if(x==-1)printf("Element not found");
					else printf("Element %d found in the tree",x);
					}break;
			case 6:	{
					if (root == NULL) 
					{
						printf("Tree is empty. Nothing to delete.\n");
					} 
					else 
					{
						printf("Enter the value to delete: ");
						scanf("%d", &x);
						root = bst_delete(root, x);
					}
					}break;
			case 7:
					exit(0);
			default: exit(0);
		}
	}
}

TREE* insert(TREE *root,int x)
{
	TREE *newnode,*temp;
	int flag=1;
	  
    newnode = (TREE *)(malloc(sizeof(TREE)));
	newnode->info=x;
	newnode->left=NULL;
	newnode->right=NULL;
	
	if(root==NULL)root=newnode;
	else 
	{ 
		temp=root;
	    while(flag)
		{
			if(x<temp->info)
			{
				if(temp->left==NULL){temp->left=newnode; flag=0;}
				else temp=temp->left;
			}	
			else
			{
				if(temp->right==NULL){temp->right=newnode; flag=0;}
				else temp=temp->right;
			}
	    }
	}
	return root;
}
  
void preorder(TREE *root)  
{
	if(root)
	{
		printf("\t %d",root->info);
		preorder(root->left);
		preorder(root->right);
    }
	
}

void inorder(TREE *root)  
{
	if(root)
	{
		inorder(root->left);
		printf("\t %d",root->info);
		inorder(root->right);
	}
}

void postorder(TREE *root)  
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("\t %d",root->info);
	}
}

int search(TREE *root,int key)
{
	TREE *temp=root;
  
	while(temp!=NULL )
	{
		if(key==temp->info)return key;
		else if(key<temp->info)temp=temp->left;
		else temp=temp->right;
	}
	return -1;
}

TREE* bst_delete(TREE *root,int key)
{
	TREE *temp=root,*q=NULL,*parent=NULL,*insucc;
  
	while(temp!=NULL && key!=temp->info)
	{
		parent=temp;
		if(key<temp->info)temp=temp->left;
		else temp=temp->right;
	}
	if(temp==NULL)printf("Element Not Found");
	// single child node 
	else if(temp->left==NULL)q=temp->right;
	else if(temp->right==NULL)q=temp->left;
	else 
	{
		insucc=temp->right;
		while(insucc->left!=NULL)
			insucc=insucc->left;
			insucc->left=temp->left;
			q=temp->right;
    }
	if(parent==NULL)root=q;
	if(parent->left==temp)parent->left=q;
	else if(parent->right==temp)parent->right=q;
	free(temp);
	return root;
}