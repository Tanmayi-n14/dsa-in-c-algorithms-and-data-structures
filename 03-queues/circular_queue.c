
#include <stdio.h>
#include <stdlib.h>
#define size 5

void enqueue(int [],int *,int *,int);
int dequeue(int [],int *);
int isqfull();
int isqempty();
void display(int [],int);
int count=0;

void main()
{
	int que[10],front,rear,choice,x;
	front=-1; rear=-1;	//queue empty
	
	while(1)
	{
		printf("\n-----MENU-----\n");
		printf("\n1 : ENQUEUE\n2 : DEQUEUE\n3 : DISPLAY\nEnter : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("Enter the element:");
				scanf("%d",&x);
				enqueue(que,&front,&rear,x);		
			}
			break;
			case 2:
			{
				if(isqempty())
				{
					printf("Empty Queue\n");
				}
				else
				{
					x=dequeue(que,&front);
					printf("Element popped is..%d",x);
				}
			}
			break;
			case 3:
			{
				printf("The contents in the queue are:\n");
				display(que,front);
			}
			break;
			default:
				exit(0);
		}
	}
}

void enqueue(int q[],int *f,int *r,int x)
{
	if(isqfull())		// count is a global variable
	{
		printf("Queue Full\n");
	}
	else
	{
		if((*f)==-1 && (*r)==-1)	//queue empty
		{
			(*f)++;
		}
		(*r)=((*r)+1)%size;	
		q[*r]=x;	
		count++;
	}
}

int dequeue(int q[],int *f)
{
	int x;
	x=q[*f];
	(*f)=((*f)+1)%size;
	count--;
	return x;			
}

int isqfull()
{
	if (count==size)
	{
		return 1;
	}
	return 0;
}

int isqempty()
{
	if (count==0)
	{
		return 1;
	}
	return 0;
}

void display(int q[],int f)	//f need not be updated, no need of pointer
{
	int i,j;
	if (isqempty())
	{
		printf("Empty Queue");
	}
	else
	{
		for(i=f,j=count;j>0;i=(i+1)%size,j--)
		{
			printf("%d\t",q[i]);
		}
	}
}