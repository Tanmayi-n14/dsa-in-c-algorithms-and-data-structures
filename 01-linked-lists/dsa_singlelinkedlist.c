#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}NODE;
	
NODE* frontins(NODE *,int);

NODE* endins(NODE *,int );

void display(NODE *);

NODE* frontdel(NODE *);

NODE* enddel(NODE *);

NODE* posins(NODE *,int, int);

NODE* posdel(NODE *, int);

NODE* orderedins(NODE *,int);

int sum_all(NODE *);

void sum_alternate(NODE *);

NODE* searchAndDelete(NODE *, int);


	
void main()
{ 
	NODE *list;
	int x,choice,pos,key;
	
	list=NULL;
	

	while(1)
	{	
		printf("Enter 1-> Front insertion\n2->End insertion\n3->Display\n");
		printf("4-> Front deletion\n5->End deletion\n6->Position insertion\n");
		printf("7-> Position deletion\n8->Ordered insertion\n9->Find sum of all numbers\n");
		printf("10-> Find sum of alternate numbers\n11-> Search and delete by value\n12->Exit\n");
		
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
			{
				printf("Enter the value to be inserted");
				scanf("%d",&x);
				list=frontins(list,x);
			}break;
		
		
			case 2: 
			{
				printf("Enter the value to be inserted");
				scanf("%d",&x);
				list=endins(list,x);
			}break;
				
				
			case 3: 
			{
				printf("The list contains... \n");
				display(list);
			}break;
			
			case 4: 
			{
				list=frontdel(list);
			}break;
			
			case 5: 
			{
				list=enddel(list);
			}break;
			
			case 6: 
			{
				printf("Enter the value to be inserted & position");
				scanf("%d %d",&x,&pos);
				list=posins(list,x,pos);
			}break;
			
			case 7: 
			{
				printf("Enter the position of the value to be deleted");
				scanf("%d",&pos);
				list=posdel(list,pos);
			}break;
			
			case 8: 
			{
				printf("Enter the value to be inserted");
				scanf("%d",&x);
				list=orderedins(list,x);
			}break;
			
			case 9:
			{
                printf("The sum of all numbers in the list is: %d\n", sum_all(list));
            }break;
            case 10:
			{
                sum_alternate(list);
            }break;
			
			 case 11:
            {
                printf("Enter the value to be deleted\n");
                scanf("%d", &key);
                list = searchAndDelete(list, key);
            }break;
			
			case 12:
            {
                exit(0);
            }break;
			
			default: exit(0);
		}
	}	
}

NODE* frontins(NODE *list,int x)
{
	NODE *newnode;
	
	newnode = (NODE *)(malloc(sizeof(NODE)));
	newnode->info=x;
	newnode->next=NULL;
	
	if (list==NULL) list=newnode;
	else 
	{
		newnode->next=list;
		list=newnode;
	}
	return list;	
}

void display(NODE *list)
{
	NODE *temp=list;
	while(temp!=NULL)
	{
		printf("\t %d", temp->info);
		temp=temp->next;
	}
}


NODE* endins(NODE *list,int x)
{
	NODE *newnode, *temp;
	
	newnode = (NODE *)(malloc(sizeof(NODE)));
	newnode->info=x;
	newnode->next=NULL;
	
	if (list==NULL) list=newnode;
	else 
	{
		temp=list;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;		
	}
	return list;	
}

NODE* frontdel(NODE *list)
{
	NODE *temp;
	temp=list;
	if (list==NULL) printf("Empty list");
	else 
	{
		list=list->next;
		free(temp);
	}
	return list;	
}



NODE* enddel(NODE *list)
{
	NODE *temp, *prev;
	
	if (list==NULL)  printf("Empty list"); 
	else if(list->next==NULL) list=NULL;
	else 
	{
		temp=list;
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=NULL;	
	}
	free(temp);	
	return list;	
}


NODE* posins(NODE *list,int x, int pos)
{
	NODE *newnode, *temp, *prev;
	int i=1;
	
	newnode = (NODE *)(malloc(sizeof(NODE)));
	newnode->info=x;
	newnode->next=NULL;
	
	if (list==NULL) list=newnode;
	else if(pos==1)
	{
		newnode->next=list;
		list=newnode;
	}
	else 
	{
		temp=list;
		while(temp->next!=NULL && i<pos)
		{
			prev=temp;
			temp=temp->next;
			i++;
		}
		if (i==pos)
		{
			newnode->next=prev->next;
			prev->next=newnode;
		}
		else if (i+1==pos)
		{
			temp->next=newnode;
		}
		else
		{		
			printf("Invalid position");
		}
	}
	return list;		
}



NODE* posdel(NODE *list, int pos)
{
	NODE *temp, *prev;
	int i=1;
	temp=list;	
	
	if (list==NULL)  printf("Empty list");
	else if(pos==1)
	{
		list=list->next;
	}
	else 
	{
		temp=list;
		while(temp->next!=NULL && i<pos)
		{
			prev=temp;
			temp=temp->next;
			i++;
		}
		if (i==pos)
		{
			prev->next=temp->next;
		}
		else
		{		
			printf("Invalid position");
		}
	}
	free(temp);	
	return list;		
}




NODE* orderedins(NODE *list,int x)    //doesnt work with other insertions only ordered ins 
{
	NODE *newnode, *temp, *prev;
	
	newnode = (NODE *)(malloc(sizeof(NODE)));
	newnode->info=x;
	newnode->next=NULL;
	
	if (list==NULL) list=newnode;
	else if(x<list->info)
	{
		newnode->next=list;
		list=newnode;
	}
	else 
	{
		temp=list;
		while(temp->next!=NULL && temp->info<=x)
		{
			prev=temp;
			temp=temp->next;
		}
		if (temp->info>x)
		{
			newnode->next=prev->next;
			prev->next=newnode;
		}
		else
		{		
			temp->next=newnode;
		}
	}
	return list;		
}




int sum_all(NODE *list) 
{
    int sum=0;
    NODE *temp=list;
    while (temp!=NULL) 
	{
        sum+=temp->info;
        temp=temp->next;
    }
    return sum;
}



void sum_alternate(NODE *list) 
{
    if (list==NULL) 
	{
        printf("List is empty.");
        return;
    }

    int odd_pos_sum=0;
    int even_pos_sum=0;
    int position=1;
    NODE *temp=list;

    while (temp!=NULL) 
	{
        if (position % 2 != 0) 
		{ 
            odd_pos_sum += temp->info;
        } 
		else 
		{ 
            even_pos_sum += temp->info;
        }
        temp = temp->next;
        position++;
    }
    printf("Sum of numbers at odd positions: %d\n", odd_pos_sum);
    printf("Sum of numbers at even positions: %d\n", even_pos_sum);
}




NODE* searchAndDelete(NODE *list, int key) 
{
    NODE *current = list;
    NODE *prev = NULL;

    if (current != NULL && current->info == key) 
	{
        list = current->next;
        free(current);
        printf("Node with value %d deleted.\n", key);
        return list;
    }

    while (current != NULL && current->info != key) 
	{
        prev = current;
        current = current->next;
    }

    if (current == NULL) 
	{
        printf("Node with value %d not found.\n", key);
        return list;
    }

    prev->next = current->next;
    free(current);

    return list;
}
