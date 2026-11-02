//DESCENDING ORDER
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heap[MAX];
int n = 0; 

int stack[MAX];
int top = -1;

void push(int val) 
{
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = val;
}

int pop() 
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

void insert(int val) 
{
    n++;
    int i = n;
    heap[i] = val;
    int parent = i / 2;

    while (i > 1 && heap[parent] > heap[i]) 
	{
        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;

        i = parent;
        parent = i / 2;
    }
}

void heapify_min(int i) 
{
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && heap[left] < heap[smallest])
        smallest = left;
    if (right <= n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) 
	{
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapify_min(smallest);
    }
}

void delete_min_and_adjust() 
{
    if (n == 0) 
	{
        printf("Heap is empty.\n");
        return;
    }

    printf("Deleted min element: %d\n", heap[1]);

    heap[1] = heap[n];
    n--;

    heapify_min(1);

    int temp[MAX];
    for (int i = 1; i <= n; i++)
        temp[i] = heap[i];

    for (int i = 1; i <= n - 1; i++) 
	{
        for (int j = i + 1; j <= n; j++) 
		{
            if (temp[i] < temp[j]) 
			{
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    printf("Heap adjusted to descending order:\n");
    for (int i = 1; i <= n; i++) 
	{
        printf("%d ", temp[i]);
        push(temp[i]); 
    }
    printf("\n");
}

void display_stack() 
{
    printf("\nStack contents (popping):\n");
    while (top != -1)
        printf("%d ", pop());
    printf("\n");
}

int main() 
{
    int i, val, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 1; i <= n; i++) 
	{
        scanf("%d", &val);
        heap[i] = val;
    }

    for (i = n / 2; i >= 1; i--)
        heapify_min(i);

    printf("Min Heap: ");
    for (i = 1; i <= n; i++)
        printf("%d ", heap[i]);
    printf("\n");

    delete_min_and_adjust();
    display_stack();

    return 0;
}