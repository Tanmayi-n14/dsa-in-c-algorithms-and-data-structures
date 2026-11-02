#include <stdio.h>
#include <stdlib.h>
#define size 5

void enqueue(int[], int*, int*, int);

int isqfull(int);

int dequeue(int[], int*, int*);

int isqempty(int, int);

void display(int[], int, int);


void main()
{
	int que[10],front,rear,choice,x;
	front=-1;
	rear=-1;
	

	while(1)
	{
		{	
			printf("Enter 1-> ENQUEUE \n2-> DEQUEUE \n3->Display\n4->Exit\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1: 
				{
					printf("Enter the element");
					scanf("%d",&x);
					enqueue(que,&front,&rear,x);
				}break;
			
				case 2: 
				{
					if (isqempty(front,rear)) printf ("Empty Queue");
					else 
					{
						x = dequeue(que,&front,&rear);
						printf("Element removed from queue is %d",x);
					}	
				}break;
			
				case 3: 
				{
					printf("Contents of queue are ...\n");
					display(que,front,rear);
				}break;
						
				case 4:
				{
					exit(0);
				}break;
			
				default: exit(0);
			}
		}
	}		
}

void enqueue(int q[], int *f, int *r, int x)   //f is front and r is rear
{
	if (isqfull(*r)) printf("Queuefull");
	else
	{
		if (*f==-1 && *r==-1) (*f)++;
		(*r)++;
		q[*r]=x;
	}
}

int isqfull(int r)
{
	if (r==size-1) return 1;
	return 0;
}


int dequeue(int q[], int *f, int *r)
{
	int x;
	x=q[*f];
	(*f)++;
	return x;
}


int isqempty(int f, int r)
{
	if ((f==-1 && r==-1) || (f>r)) return 1;
	return 0;
}



void display(int q[], int f, int r)
{
	int i;
	if (isqempty(f,r)) printf ("Empty Queue");
	else
	{
		for (i=f;i<=r;i++)
		printf("%d\t",q[i]);
	}
}


