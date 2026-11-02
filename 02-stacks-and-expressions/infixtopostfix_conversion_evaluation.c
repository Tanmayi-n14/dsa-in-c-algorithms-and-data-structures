#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char s_char[10];
int t_char = -1;

int s_int[10];
int t_int = -1;


void convert_infix_to_postfix(char[], char[]);
int input_prec(char);
int stack_prec(char);
void push_char(char);
char pop_char();
char seek_char();


int evaluate(char[]);
void push_int(int);
int pop_int();
int isoperator(char ch);


void main()
{
	char infix[10], postfix[10];
	int result;

	printf("Enter infix expression: ");
	scanf("%s", infix);

	convert_infix_to_postfix(infix, postfix);
	printf("Postfix expression is: %s\n", postfix);

	result = evaluate(postfix);
	printf("The result is: %d\n", result);
}


void convert_infix_to_postfix(char infix[], char postfix[])
{
	int i = 0, j = 0;
	push_char('#');
	while(infix[i] != '\0')
	{
		while(stack_prec(seek_char()) > input_prec(infix[i]))	
		{	
			postfix[j++] = pop_char();
		}
		if(stack_prec(seek_char()) != input_prec(infix[i]))
		{	
			push_char(infix[i]);
		}
		else pop_char();	
		i++;	
	}
	while(seek_char() != '#')	
	{
		postfix[j++] = pop_char();
	}
	postfix[j] = '\0';	
}

int input_prec(char ch)
{
	switch(ch)
	{
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 3;
		case '^': return 6;
		case '(': return 9;
		case ')': return 0;
		default : return 7;
	}	
}

int stack_prec(char ch)
{
	switch(ch)
	{
		case '+':
		case '-': return 2;
		case '*':
		case '/': return 4;
		case '^': return 5;
		case '(': return 0;
		case '#': return -1;
		default : return 8;
	}	
}

void push_char(char ch)
{
	s_char[++t_char] = ch;	
}

char pop_char()
{
	return s_char[t_char--];
}

char seek_char()
{
	return s_char[t_char];
}


int evaluate(char postfix[])
{
	int i = 0;
	char ch;
	int x, y, z;
	while ((ch = postfix[i++]) != '\0')
	{
		if (isalnum(ch))
		{
			push_int(ch - '0');
		}
		else if (isoperator(ch))
		{
			x = pop_int();
			y = pop_int();
			switch(ch)
			{
				case '+':
					z = x + y;		
					break;
				case '-':
					z = y - x;		
					break;
				case '*':
					z = x * y;		
					break;
				case '/':
					z = y / x;		
					break;	
				case '^':
					z = y ^ x;		
					break;	
			}
			push_int(z);
		}
	}
	return pop_int();
}

void push_int(int ch)
{
	s_int[++t_int] = ch;
}

int pop_int()
{
	return s_int[t_int--];
}

int isoperator(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
		case '^':
		case '*':
		case '/': return 1;
	}
	return 0;
}