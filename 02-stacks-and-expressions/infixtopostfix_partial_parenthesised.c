#include <stdio.h>
#include <stdlib.h>


void convert_infix_to_postfix(char[], char[]);

int input_prec(char);

int stack_prec(char);

void push(char);

char pop();

char seek();

char s[10];
int t=-1;

void main()
{
	char infix[10],postfix[10];
	printf("Enter infix expression");
	scanf("%s",&infix);
	convert_infix_to_postfix(infix,postfix);
	printf("Postfix expression is ... %s",postfix);
	
}

void convert_infix_to_postfix(char infix[], char postfix[])
{
	int i=0,j=0;
	push('#');
	while(infix[i]!='\0') //backslash 0 is null character
	{
		while(stack_prec(seek())>input_prec(infix[i]))	
		{	
			postfix[j++]=pop();
		}
		if(stack_prec(seek())!=input_prec(infix[i]))
		{	
			push(infix[i]);
		}
	else pop();	
	i++;	
	}
	while(seek()!='#')	
	{
		postfix[j++]=pop();
	}
	postfix[j]='\0';	
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


void push(char ch)
{
	s[++t]=ch;	
}	
	
	
char pop()
{
	return s[t--];
}	

char seek()
{
	return s[t];
}