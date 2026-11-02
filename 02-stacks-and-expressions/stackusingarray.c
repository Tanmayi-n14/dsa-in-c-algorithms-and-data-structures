#include <stdio.h>
#include <stdlib.h>
#define size 5

void push(int[], int*, int);

int pop(int[], int*);

void display(int[], int);

int seek(int[], int);


void main()
{
	int st[10],top,choice,x;
	top=-1;


	while(1)
	{
		{	
			printf("Enter 1-> PUSH \n2-> POP \n3->SEEK\n4->Display\n5->Exit\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1: 
				{
					printf("Enter the element");
					scanf("%d",&x);
					push(st,&top,x);
				}break;
			
				case 2: 
				{
					x = pop(st, &top);
					if (x==-1) printf ("Empty stack");
					else printf("Element deleted is %d",x);
				}break;
			
				case 3: 
				{
					x = seek(st, top);
					printf("Top of stack is %d",x);
				}break;
			
				case 4: 
				{
					printf("Contents of stack are ...\n");
					display(st,top);
				}break;
						
				case 5:
				{
					exit(0);
				}break;
			
				default: exit(0);
			}
		}
	}		
}

void push(int s[], int *t, int x)
{
	if (*t==size-1) printf("Stackfull");
	else
	{
		(*t)++;
		s[*t]=x;
	}
}

void display(int s[], int t)
{
	int i;
	if (t==-1) printf ("Empty stack");
	else
	{
		for (i=t;i>=0;i--)
		printf("%d\t",s[i]);
	}
}

int pop(int s[], int *t)
{
	int x=-1;
	if ((*t)==-1) return x;
	x=s[*t];
	(*t)--;
	return x;
}


int seek(int s[], int t)
{
	return s[t];
}