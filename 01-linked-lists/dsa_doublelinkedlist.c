#include <stdio.h>
#include <stdlib.h>

typedef struct dnode
{
	int info;
	struct dnode *left, *right;
}DNODE;


	
DNODE* frontins(DNODE *,int);

DNODE* endins(DNODE *,int );

void display(DNODE *);

DNODE* frontdel(DNODE *);

DNODE* enddel(DNODE *);

DNODE* succnodeins(DNODE *,int, int);

DNODE* succnodedel(DNODE *,int ); 

DNODE* posins(DNODE *, int, int);

DNODE* posdel(DNODE *, int);

DNODE* searchAndDelete(DNODE *, int);
	

	
void main()
{ 
	DNODE *dlist;
	int x,choice,pos,succ,key;
	
	dlist=NULL;
	

	while(1)
	{	
		printf("Enter 1-> Front insertion\n2->End insertion\n3->Display\n");
		printf("Enter 4-> Front deletion\n5->End deletion\n6-> Insertion when successor is given-works only when this method is used from start\n");
		printf("Enter 7-> Deletion when successor is given\n8->Position insertion\n9->Position deletion\n");
		printf("Enter 10-> Search and delete by value\n11->Exit\n");
		
		
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
			{
				printf("Enter the value to be inserted");
				scanf("%d",&x);
				dlist=frontins(dlist,x);
			}break;
		
			case 2: 
			{
				printf("Enter the value to be inserted");
				scanf("%d",&x);
				dlist=endins(dlist,x);
			}break;	
				
			case 3: 
			{
				printf("The list contains... \n");
				display(dlist);
			}break;
			
			case 4: 
			{
				dlist=frontdel(dlist);
			}break;
			
			case 5: 
			{
				dlist=enddel(dlist);
			}break;
			
			case 6: 
			{
				printf("Enter the value to be inserted & successor node information");
				scanf("%d %d",&x,&succ);
				dlist=succnodeins(dlist,x,succ);
			}break;
			
			case 7: 
			{
				printf("Enter the successor node information");
				scanf(" %d",&succ);
				dlist=succnodedel(dlist,succ);
			}break;
			
			case 8:
			{
				printf("Enter the value to be inserted & position\n");
				scanf("%d %d", &x, &pos);
				dlist = posins(dlist, x, pos);
			}break;

			case 9: 
			{
				printf("Enter the position of the value to be deleted\n");
				scanf("%d", &pos);
				dlist = posdel(dlist, pos);
			}break;
			
			
			 case 10:
            {
                printf("Enter the value to be deleted\n");
                scanf("%d", &key);
                dlist = searchAndDelete(dlist, key);
            }break;

            case 11:
            {
                exit(0);
            }break;
			
		
			default: exit(0);
		}	
	}	
}



DNODE* frontins(DNODE *dlist,int x)
{
	DNODE *newnode;
	
	newnode = (DNODE *)(malloc(sizeof(DNODE)));
	newnode->info=x;
	newnode->left=NULL;
	newnode->right=NULL;
	
	if (dlist==NULL) dlist=newnode;
	else 
	{
		newnode->right=dlist;
		dlist->left=newnode;
		dlist=newnode;
	}
	return dlist;	
}


void display(DNODE *dlist)
{
	DNODE *temp=dlist;
	while(temp!=NULL)
	{
		printf("\t %d", temp->info);
		temp=temp->right;
	}
}




DNODE* endins(DNODE *dlist,int x)
{
	DNODE *newnode, *temp;
	
	newnode = (DNODE *)(malloc(sizeof(DNODE)));
	newnode->info=x;
	newnode->left=NULL;
	newnode->right=NULL;
	
	if (dlist==NULL) dlist=newnode;
	else 
	{
		temp=dlist;
		while(temp->right!=NULL)
			temp=temp->right;
		temp->right=newnode;	
		newnode->left=temp;
	}
	return dlist;	
}




DNODE* frontdel(DNODE *dlist)
{
	DNODE *temp;
	temp=dlist;
	if (dlist==NULL) printf("Empty list");
	else if (dlist->right==NULL)
	{
		dlist=NULL;
	}
	else 
	{
		dlist=dlist->right;
		dlist->left=NULL;
	}
	free(temp);
	return dlist;	
}

DNODE* enddel(DNODE *dlist)
{
	DNODE *temp;
	temp=dlist;
	if (dlist==NULL)  printf("Empty list"); 
	else if(dlist->right==NULL) dlist=NULL;
	else 
	{
		while(temp->right!=NULL)
		{
			temp=temp->right;
		}
		(temp->left)->right=NULL;	
	}
	free(temp);	
	return dlist;	
}


DNODE* succnodeins(DNODE *dlist,int x, int succ) //successor code only works when no other method is used
{
	DNODE *newnode, *temp;
	
	newnode = (DNODE *)(malloc(sizeof(DNODE)));
	newnode->info=x;
	newnode->left=NULL;
	newnode->right=NULL;
	
	if (dlist==NULL) dlist=newnode;
	else if(succ==dlist->info)
	{
		newnode->right=dlist;
		dlist->left=newnode;
		dlist=newnode;
	}
	
	else 
	{
		temp=dlist;
		while(temp->right!=NULL && succ!=temp->info)
		{
			temp=temp->right;
		}
		if (succ==temp->info)
		{
			newnode->left=temp->left;
			newnode->right=temp;
			temp->left=newnode;
			(newnode->left)->right=newnode;
		}
		else
		{		
			printf("Invalid successor node info");
		}
	}
	return dlist;		
}


DNODE* succnodedel(DNODE *dlist, int succ) 
{
	DNODE *temp;
	
	if (dlist==NULL)  printf("Empty list"); 
	
	else if((dlist->right)->info==succ)
	{
		(dlist->right)->left=NULL;
		dlist=dlist->right;
	}
	else 
	{
		temp=dlist;
		while(temp->right!=NULL && succ!=(temp->right)->info)
		{
			temp=temp->right;
		}
		if (succ==(temp->right)->info)
		{
			(temp->right)->left=temp->left;
			(temp->left)->right=temp->right;
			free(temp);
		}
		else
		{		
			printf("Invalid successor node info");
		}
	}
	return dlist;		
}


DNODE* posins(DNODE *dlist, int x, int pos)
{
	DNODE *newnode, *temp, *prev;
	int i=1;
	
	newnode = (DNODE *)(malloc(sizeof(DNODE)));
	newnode->info=x;
	newnode->left=NULL;  
	newnode->right=NULL; 
	
	if (dlist==NULL) 
	{
		dlist=newnode;
	}
	else if(pos==1)
	{
		newnode->right = dlist;
		dlist->left = newnode;
		dlist = newnode;
	}
	else
	{
		temp=dlist;
		while(temp->right!=NULL && i < pos)
		{
			prev=temp;
			temp=temp->right;
			i++;
		}
		
		if (i==pos)
		{
			newnode->right = prev->right;
			newnode->left = prev;
			
			if (prev->right != NULL) 
			{
				(prev->right)->left = newnode;
			}
			prev->right = newnode;
		}
		else if (i+1==pos)
		{
			temp->right=newnode;
			newnode->left = temp;
		}
		else
		{		
			printf("Invalid position\n"); 
		}
	}
	return dlist;		
}


DNODE* posdel(DNODE *dlist, int pos)
{
    DNODE *temp;
    int i=1;

    if (dlist==NULL) 
	{
        printf("Empty list\n");
        return NULL;
    }

    if(pos==1)
    {
        temp = dlist;
        dlist = dlist->right;
        if (dlist != NULL) 
		{
            dlist->left = NULL;
        }
    }
    else
    {
        temp=dlist;
        while(temp != NULL && i < pos)
        {
            temp=temp->right;
            i++;
        }

        if (temp == NULL)
        {
            printf("Invalid position\n");
            return dlist;
        }

        if (temp->left != NULL) 
		{
            temp->left->right = temp->right;
        }
        if (temp->right != NULL) 
		{
            temp->right->left = temp->left;
        }
    }
    
    free(temp);
    
    return dlist;
}



DNODE* searchAndDelete(DNODE *dlist, int key)
{
    DNODE *temp = dlist;

    if (dlist == NULL) 
	{
        printf("List is empty.\n");
        return NULL;
    }

    if (dlist->info == key) 
	{
        dlist = dlist->right;
        if (dlist != NULL) 
		{
            dlist->left = NULL;
        }
        free(temp);
        printf("Node with value %d deleted.\n", key);
        return dlist;
    }

    while (temp != NULL && temp->info != key) 
	{
        temp = temp->right;
    }

    if (temp == NULL) 
	{
        printf("Node with value %d not found.\n", key);
        return dlist;
    }

    if (temp->left != NULL) 
	{
        temp->left->right = temp->right;
    }
    if (temp->right != NULL) 
	{
        temp->right->left = temp->left;
    }

    free(temp);

    return dlist;
}
