#include <stdio.h>
#include <stdlib.h>
#define size 5


void push(int[], int*, int);
int pop(int[], int*);
void display(int[], int);
int seek(int[], int);
int is_stack_full(int);
int is_stack_empty(int);


void main()
{
	int st[10], top, choice, x;
	top = -1;

	while(1)
	{
		printf("\nEnter 1-> PUSH \n2-> POP \n3->SEEK\n4->Display\n5->Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
			{
				printf("Enter the element: ");
				scanf("%d", &x);
				push(st, &top, x);
			}break;
		
			case 2:
			{
				if (is_stack_empty(top)) 
				{
                    printf("Empty stack\n");
                }
				else 
				{
                    x = pop(st, &top);
				    printf("Element deleted is %d\n", x);
                }
			}break;
		
			case 3:
			{
                if (is_stack_empty(top)) 
				{
                    printf("Empty stack\n");
                } 
				else 
				{
				    x = seek(st, top);
				    printf("Top of stack is %d\n", x);
                }
			}break;
		
			case 4:
			{
				printf("Contents of stack are ...\n");
				display(st, top);
			}break;
					
			case 5:
			{
				exit(0);
			}break;
		
			default:
                printf("Invalid choice.\n");
		}
	}
}


void push(int s[], int *t, int x)
{
	if (is_stack_full(*t)) 
	{
        printf("Stack full\n");
    }
	else
	{
		(*t)++;
		s[*t] = x;
	}
}


void display(int s[], int t)
{
	int i;
	if (is_stack_empty(t)) 
	{
        printf("Empty stack\n");
    }
	else
	{
		for (i = t; i >= 0; i--) 
		{
		    printf("%d\t", s[i]);
        }
	}
}


int pop(int s[], int *t)
{
	int x;
	x = s[*t];
	(*t)--;
	return x;
}


int seek(int s[], int t)
{
	return s[t];
}


int is_stack_full(int t)
{
    if (t == size - 1) 
	{
        return 1;
    }
    return 0;
}


int is_stack_empty(int t)
{
    if (t == -1) 
	{
        return 1;
    }
    return 0;
}