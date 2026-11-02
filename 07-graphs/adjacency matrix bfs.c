#include <stdio.h>
#include <stdlib.h>

void creategraph();
void display();
void bfs(int);
void qinsert(int);
int qdelete();
int isqempty();

int adj[10][10];
int visit[10];
int q[25];
int f,r,n;

void main()
{
	int v;
	f=-1,r=-1;
	printf("Enter the no.of vertices : ");
	scanf("%d",&n);
	
	creategraph();
	display();

	printf("Enter the start vertex : ");
	scanf("%d",&v);

	for (int i=1;i<=n;i++)
	{
		visit[i]=0;
	}

	bfs(v);
}

void creategraph()
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

void display()
{
	for (int p=1;p<=n;p++)
	{
		for (int q=1;q<=n;q++)
		{
			printf("%d\t",adj[p][q]);
		}
		printf("\n");
	}
}

void bfs(int v)
{
	qinsert(v);
	visit[v]=1;
	printf("%d\t",v);

	while (!isqempty())
	{
		v=qdelete();
		
		for (int i=1;i<=n;i++)
		{
			if (adj[v][i]==1 && visit[i]==0)
			{
				qinsert(i);
				visit[i]=1;
				printf("%d\t",i);
			}
		}
	}
}

int isqempty()
{
	if ((f==-1 && r==-1) || (f>r))
	{
		return 1;
	}

	return 0;
}

void qinsert(int x)
{
	if (f==-1 && r==-1)
	{
		f++;	
	}
	r++;
	q[r]=x;
}

int qdelete()
{
	int x;
	x=q[f];
	f++;

	return x;
}

