#include <stdio.h>
#include <stdlib.h>

typedef struct gnode
{
	int info;
	struct gnode *next;
} GNODE;

GNODE *adlist[10]; 
int visit[10];     
int q[25];         
int f, r, n;       

void creategraph(int);
void display(int);
void bfs(int);
void qinsert(int);
int qdelete();
int isqempty();

void main()
{
	int v;
	f = -1, r = -1; 
	printf("Enter the no.of vertices : ");
	scanf("%d", &n);

	creategraph(n); 
	display(n);     

	printf("Enter the start vertex : ");
	scanf("%d", &v);

	for (int i = 1; i <= n; i++)
	{
		visit[i] = 0;
	}

	printf("BFS Traversal: ");
	bfs(v); 
	printf("\n");
}

void creategraph(int n)
{
	GNODE *temp;
	int i, j;

	for (i = 1; i <= n; i++)
	{
		adlist[i] = NULL;
	}

	while (1)
	{
		printf("Enter the indices of source and destination vertices (0 0 to stop): ");
		scanf("%d %d", &i, &j);
		if (i == 0 && j == 0)
		{
			break;
		}
		else
		{
			temp = (GNODE *)malloc(sizeof(GNODE));
			temp->info = j;
			temp->next = adlist[i]; 
			adlist[i] = temp;
		}
	}
}

void display(int n)
{
	GNODE *temp;
	int p;
	printf("Adjacency List\n");
	for (p = 1; p <= n; p++)
	{
		printf("Vertex %d: ", p);
		for (temp = adlist[p]; temp != NULL; temp = temp->next)
		{
			printf("%d\t", temp->info);
		}
		printf("\n");
	}
	printf("\n");
}

void bfs(int v)
{
	GNODE *temp;
	int w;

	qinsert(v);   
	visit[v] = 1; 
	printf("%d\t", v);

	while (!isqempty())
	{
		v = qdelete(); 
		
		for (temp = adlist[v]; temp != NULL; temp = temp->next)
		{
			w = temp->info; 
			
			if (visit[w] == 0)
			{
				qinsert(w);  
				visit[w] = 1; 
				printf("%d\t", w);
			}
		}
	}
}

int isqempty()
{
	if ((f == -1 && r == -1) || (f > r))
	{
		return 1;
	}

	return 0;
}

void qinsert(int x)
{
	if (f == -1 && r == -1)
	{
		f++; 
	}
	r++;
	q[r] = x;
}

int qdelete()
{
	int x;
	x = q[f];
	f++;
	return x;
}