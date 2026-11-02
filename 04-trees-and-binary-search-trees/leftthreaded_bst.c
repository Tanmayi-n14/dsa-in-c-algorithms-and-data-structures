#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct thtree 
{
	int info;
	struct thtree *left,*right;
	bool lthread;
} THTREE;

THTREE* insert(THTREE*,int);
void reverse_inorder(THTREE *); 
THTREE* inorderpredecessor(THTREE *); 

void main()
{
    THTREE *root;
	int x,choice;
	
	root=NULL;
	while(1)
	{
		printf("Enter 1->Insertion\n2->REVERSE INORDER TREE Traversal\n3->EXIT\n");
		scanf("%d",&choice);
	
		switch(choice)
		{
			case 1:	{
					printf("Enter the value: ");
					scanf("%d", &x);
					root=insert(root,x);
					}break;
			case 2:	{
					reverse_inorder(root); 
					}break;
			default:exit(0);
		}
	}
}

THTREE* insert(THTREE *curr,int x)
{
	THTREE *temp,*t;
	t=curr;  
    
	temp = (THTREE *)(malloc(sizeof(THTREE)));
	temp->info=x;
	temp->left=NULL;
    temp->right=NULL; 
	temp->lthread=true; 
		
	if(curr==NULL) return temp;
	
	while(curr!=NULL)
	{
		if(x < curr->info)
        {
			if(curr->lthread == false) 
                curr=curr->left;                     
		    else 
                break;
        }
		else 
        {
            if(curr->right != NULL) 
                curr=curr->right;                    
		    else 
                break;
        }
	}

	if(x < curr->info)
	{
		temp->left = curr->left; 
        temp->lthread = curr->lthread; 
		curr->left = temp;
		curr->lthread = false; 
	}  
    else 	  
    {
		temp->left = curr; 
		curr->right = temp;
	}
	return t;
}

void reverse_inorder(THTREE *t)
{ 
    THTREE *curr;
	printf("\nReverse Inorder Traversal: ");
	if(t == NULL) 
    {
        printf("Empty Tree..\n");
        return;
    }
	
    curr = t;
    
	while(curr->right != NULL)
	{
		curr=curr->right;
	}	
    
	while(curr != NULL)
	{
		printf("%d ",curr->info);
		curr = inorderpredecessor(curr);  
	}
    printf("\n");
}

THTREE* inorderpredecessor(THTREE *t)
{ 
	if(t->lthread == true)
	    return t->left;
	
	t = t->left;
	while(t->right != NULL)
		t=t->right;
	return t;
}