//GRAPH USING ADJACENCY MATRIX
//the vertices are represented using indices
//Indices start from 1
//for weighted, take that weight as input and make adj[i][j]=weight



#include <stdio.h>
#include <stdlib.h>

void creategraph(int);
void display(int);
void dfs(int,int);
int connected(int,int);

int adj[10][10];
int visit[10];

void main()
{
	int n,v,res;
	printf("Enter the no.of vertices : ");
	scanf("%d",&n);
	
	creategraph(n);
	display(n);

	printf("Enter the start vertex : ");
	scanf("%d",&v);

	res=connected(v,n);
	
	if (res==1)
	{
		printf("\nGraph is connected\n");
	}
	else
	{
		printf("\nGraph is not connected\n");
	}
}

void creategraph(int n)
{
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
			adj[i][j]=1;	//for directed graph
			//adj[j][i]=1;
			//adj[i][j]=1; adj[j][i]=1;  ---->for undirected graph
		}
	}
}

void display(int n)
{
	int p,q;
	for (p=1;p<=n;p++)
	{
		for (q=1;q<=n;q++)
		{
			printf("%d\t",adj[p][q]);
		}
		printf("\n");
	}
}

void dfs(int v,int n)
{
	printf("%d\t",v);
	visit[v]=1;
	for (int i=1;i<=n;i++)
	{
		if (adj[v][i]==1 && visit[i]==0)
		{
			dfs(i,n);
		}
	}
}

int connected(int v,int n)
{
	for (int i=1;i<=n;i++)
	{
		visit[i]=0;
	}
	
	dfs(v,n);

	for (int j=1;j<=n;j++)
	{
		if (visit[j]==0)
		{
			return 0;
		}
	}
	
	return 1;
}

