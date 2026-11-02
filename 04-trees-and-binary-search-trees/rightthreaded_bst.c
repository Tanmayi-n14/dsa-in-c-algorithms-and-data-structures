#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct thtree 
{
	int info;
	struct thtree *left,*right;
	bool rthread;	
} THTREE;

THTREE* insert(THTREE*,int);
void inorder(THTREE *);
THTREE* inordersuccessor(THTREE *);

void main()
{
    THTREE *root;
	int x,choice;
	
	root=NULL;
	while(1)
	{
		printf("Enter 1->Insertion\n2->INORDER TREE Traversal\n3->EXIT\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:	{
					printf("Enter the value: ");
					scanf("%d", &x);
					root=insert(root,x);
					}break;
			case 2:	{
					inorder(root);
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
	temp->rthread=true; 
		
	if(curr==NULL) return temp;
	
	while(curr!=NULL)
	{
		if(x < curr->info)
        {
			if(curr->left != NULL) 
                curr=curr->left;                     
		    else 
                break;
        }
		else 
        {
            if(curr->rthread == false) 
                curr=curr->right;                    
		    else 
                break;
        }
	}

	if(x < curr->info)
	{
		temp->right = curr; 
		curr->left = temp;
	}  
    else 	  
    {
		temp->right = curr->right; 
        temp->rthread = curr->rthread;
		curr->right = temp;
		curr->rthread = false; 
	}
	return t;
 }

void inorder(THTREE *t)
{ 
    THTREE *curr;
	printf("\nInorder Traversal: ");
	if(t == NULL) 
    {
        printf("Empty Tree..\n");
        return;
    }
	
    curr = t;
    
	while(curr->left != NULL)
	{
		curr=curr->left;
	}	
    
	while(curr != NULL)
	{
		printf("%d ",curr->info);
		curr = inordersuccessor(curr);  
	}
    printf("\n");
}

THTREE* inordersuccessor(THTREE *t)
{ 
	if(t->rthread == true)
	    return t->right;
	
	t = t->right;
    
	while(t->left != NULL)
		t=t->left;
	return t;
}