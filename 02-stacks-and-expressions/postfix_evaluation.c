#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int evaluate(char []);
void push(int);
int pop();
int isoperator(char ch);

int s[10],top=-1;		//s is an integer stack

void main()
{
	int p;
	char postfix[10];					//use character array for strings
	printf("\nEnter a valid postfix expression .. ");
	scanf("%s",postfix);					//no need of & for strings
	p=evaluate(postfix);
	printf("\nThe result is .. %d\n",p);
}

int evaluate(char postfix[])
{
	int i=0;
	char ch;
	int x,y,z;
	while ((ch=postfix[i++])!='\0')
	{
		if (isalnum(ch))
		{
			push(ch - '0');
		}
		else if (isoperator(ch))
		{
			x = pop();
			y = pop();
			switch(ch)
			{
				case '+':
					{ z = x+y;		
					}break;
				case '-':
					{ z = y-x;		
					}break;
				case '*':
					{ z = x*y;		
					}break;
				case '/':
					{ z = y/x;		
					}break;	
				case '^':
					{ z = y^x;		
					}break;	
			}
			push(z);
		}
	}
	return pop();
}

void push(int ch)
{
	s[++top]=ch;			//increment top before use, as # is pushed in first
}

int pop()
{
	return s[top--];		//decrement top after use
}

int seek()
{
	return s[top];
}

int isoperator(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
		case '^':
		case '*':
		case '/':return 1;
	}
	return 0;
}