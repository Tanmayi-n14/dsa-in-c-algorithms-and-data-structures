

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int info;
	int pty; // Priority
} NODE;


void pqinsert(int, int);
NODE pqdelete();
void display();
void adjust(int); 

NODE pq[25]; 
int count = 0; 

void main()
{
	int choice, x, p;
	NODE temp;
	while (1)
	{
		printf("\n-----MENU-----\n");
		printf("\n1 : PQINSERT\n2 : PQDELETE\n3 : PQDISPLAY\n4 : EXIT\n\nEnter : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			if (count >= 25)
			{
				printf("Error: Priority queue is full.\n");
			}
			else
			{
				printf("Enter the element and it's priority: ");
				scanf("%d %d", &x, &p);
				pqinsert(x, p);
			}
		}
		break;
		case 2:
		{

			if (count == 0)
			{
				printf("Error: Priority queue is empty.\n");
			}
			else
			{
				temp = pqdelete();
				printf("The element deleted is (%d, %d)\n", temp.info, temp.pty);
			}
		}
		break;
		case 3:
		{
			printf("The contents in the queue are:\n");
			display();
		}
		break;
		default:
			exit(0);
		}
	}
}

void pqinsert(int x, int p)
{
	int i, j;
	NODE temp;
	temp.info = x;
	temp.pty = p;

	i = count;	
	count++;	

	j = (i - 1) / 2; 
	
	while (i > 0 && temp.pty < pq[j].pty)
	{
		pq[i] = pq[j]; 
		i = j;		   
		j = (i - 1) / 2; 
	}
	pq[i] = temp;
}


NODE pqdelete()
{
	NODE min;

	min = pq[0]; 
	
	pq[0] = pq[count - 1];
	count--; 

	if (count > 0) 
	{
		adjust(count);
	}

	return min;
}


void display()
{
	int q;
	if (count == 0)
	{
		printf("The priority queue is empty.\n");
		return;
	}

	printf("The priority queue (heap array) is ....\n");
	for (q = 0; q < count; q++)
	{
		printf("(Info: %d, Priority: %d)\n", pq[q].info, pq[q].pty);
	}
	printf("\n");
}


void adjust(int n)
{
	int i, j;
	NODE key;

	j = 0;		
	key = pq[j]; 
	i = 2 * j + 1; 

	while (i < n) 
	{
		if (i + 1 < n && pq[i + 1].pty < pq[i].pty)
		{
			i++; 
		}

		if (key.pty > pq[i].pty)
		{
			pq[j] = pq[i]; 
			j = i;		  
			i = 2 * j + 1;   
		}
		else
		{
			break; 
		}
	}
	pq[j] = key; 
}
