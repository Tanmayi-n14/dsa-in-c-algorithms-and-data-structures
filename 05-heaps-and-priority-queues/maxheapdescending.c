//DESCENDING ORDER
#include <stdio.h>
#include <stdlib.h>

void heapify(int*);
void maxdel(int *);
void adjust(int );
int h[100];

void main()
{
	int n,p, q,r,count;

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

	maxdel(&count);
	
	printf("The heap is ...");
	for(r=0;r<count;r++)
	{
		printf("\t%d",h[r]);
	}
}

void heapify(int *count)
{
	int i,j,k,key;

	for (k=1;k<*count;k++)
	{
		i=k;
		key=h[i];
		j=(i-1)/2;
	
		while (i>0 && h[j]<key)
		{
			h[i]=h[j];
			i=j;
			j=(i-1)/2;
		}
		h[i]=key;
	}
}

void maxdel(int *count)
{
	int max;
	max=h[0];
	printf("The max element is %d .... ",max);
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
	
	while (i<count)		//as long as left child exists
	{
		if (i+1 < count)	//if right child exists
		{
			if (h[i+1] > h[i])
			{
				i++;
			}
		}
		if (key<h[i])
		{
			h[j] = h[i];
			j=i;
			i=2*j+1;
		}
		else break;
		h[j]=key;
	}
}	





  
 