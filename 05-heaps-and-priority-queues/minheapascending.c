//ASCENDING ORDER
#include <stdio.h>
#include <stdlib.h>

void heapify(int*);
void mindel(int *);
void adjust(int);

int h[100];

void main()
{
	int n,p,q,r,count;

	printf("Enter the no.of elements : ");
	scanf("%d",&n);
	
	count=n;

	printf("Enter the elements....\n");
	for (p=0;p<n;p++)
	{
		printf("Enter the element %d : ",p+1);
		scanf("%d",&h[p]);
	}

	heapify(&count);

	printf("The heap is ....\n");
	for (q=0;q<count;q++)
	{
		printf("%d\t",h[q]);
	}
	printf("\n");

	mindel(&count);

	printf("The heap is ....\n");
	for (r=0;r<count;r++)
	{
		printf("%d\t",h[r]);
	}
	printf("\n");
	
}

void heapify(int *count)
{
	int i,j,k,key;

	for (k=1;k<*count;k++)
	{
		i=k;
		key=h[i];
		j=(i-1)/2;
	
		while (i>0 && h[j]>key)   // correct for minheap
		{
			h[i]=h[j];
			i=j;
			j=(i-1)/2;
		}
		h[i]=key;
	}
}

void mindel(int *count)
{
	int min;
	min=h[0];
	printf("The min element is %d .... ",min);
	h[0]=h[*count-1];
	(*count)--;          
	adjust(*count);
}

void adjust(int count)
{
	int i,j,key;
	j=0;
	i=2*j+1;
	key=h[j];
	
	while (i<count)		// as long as left child exists
	{
		// choose the smaller child
		if (i+1 < count && h[i+1] < h[i])
		{
			i++;
		}

		// if parent > smaller child, swap
		if (key > h[i])
		{
			h[j] = h[i];
			j = i;
			i = 2*j + 1;
		}
		else
			break;
	}
	h[j] = key;
}