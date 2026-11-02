#include <stdio.h>
#include <stdlib.h>
#define size 5

typedef struct pnode
{
	int info;
	int pty;   //pty is priority
}PNODE;

void enque(PNODE [],int,int);
PNODE deque(PNODE []);
void display(PNODE []);

int count=0;

void main()
{
	int choice,x,p;            //p is priority
	PNODE que[size],t;

	while(1)
	{
		printf("\n-----MENU-----\n");
		printf("\n1 : ENQUE\n2 : DEQUE\n3 : DISPLAY\n4 : Exit\nEnter : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("Enter the element and it's priority:");
				scanf("%d %d",&x,&p);
				enque(que,x,p);		
			}
			break;
			case 2:
			{
				if(count==0)
				{
					printf("Empty Queue\n");
				}
				else
				{
					t=deque(que);
					printf("The element popped from the queue is..%d",t);
				}
			}
			break;
			case 3:
			{
				printf("The contents in the queue are:\n");
				display(que);
			}
			break;
			default:
				exit(0);
		}
	}
}

void enque(PNODE q[],int x,int p)
{
	int j;
	PNODE t;
	t.info=x;
	t.pty=p;

	if (count==size)
	{
		printf("Queue full\n");
	}
	else
	{
		j=count-1;
		while (j>=0 && (q[j].pty)>p)
		{
			q[j+1]=q[j];
			j--;
		}
		q[j+1]=t;
		count++;
	}
}

PNODE deque(PNODE q[])
{
	PNODE t;
	t=q[0];
	int j=0;
	while (j<count-1)
	{
		q[j]=q[j+1];
		j++;
	}
	count--;
	return t;		
}

void display(PNODE q[])
{
	int i;
	if (count==0)
	{
		printf("Empty Queue");
	}
	else
	{
		for(i=0;i<count;i++)
		{
			printf("(%d,%d)\t",q[i].info,q[i].pty);
		}
	}
}