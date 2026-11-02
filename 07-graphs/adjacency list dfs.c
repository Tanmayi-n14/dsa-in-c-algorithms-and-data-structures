#include <stdio.h>
#include <stdlib.h>

typedef struct gnode
{
	int info;
	struct gnode *next;
}GNODE;

void creategraph(int);
void display(int);
void dfs(int,int);

GNODE *adjlist[10];
int visit[10];

void main()
{
	int n,v;
	printf("Enter the no.of vertices : ");
	scanf("%d",&n);
	
	for (int i=1;i<=n;i++)
	{
		adjlist[i]=NULL;
	}
	
	creategraph(n);
	display(n);

	printf("Enter the start vertex : ");
	scanf("%d",&v);

	for (int i=1;i<=n;i++)
	{
		visit[i]=0;
	}

	dfs(v,n);
}

void creategraph(int n)
{
	GNODE *temp;
	int i,j;
	while(1)
	{
		printf("Enter the indices of source and destination vertices : ");
		scanf("%d %d",&i,&j);
		if (i==0 && j==0)
		{
			break;
		}
		else
		{
			temp=(GNODE*)(malloc(sizeof(GNODE)));
			temp->info=j;
			temp->next=adjlist[i];
			adjlist[i]=temp;
		}
	}
}

void display(int n)
{
	GNODE *temp;

	printf("Adjacent nodes for the vertices are : \n");	

	for (int p=1;p<=n;p++)
	{
		printf("Vertex %d : ", p);

		for (temp=adjlist[p];temp!=NULL;temp=temp->next)
		{
			printf("%d\t",temp->info);
		}
		printf("\n");
	}
}

void dfs(int v,int n)
{
	GNODE *temp;
	int w;
	printf("%d\t",v);
	visit[v]=1;
	temp=adjlist[v];
	for (w = temp->info; temp!=NULL; temp=temp->next)
	{
		if (visit[temp->info]==0)
		{
			dfs(temp->info,n);
		}
	}
}