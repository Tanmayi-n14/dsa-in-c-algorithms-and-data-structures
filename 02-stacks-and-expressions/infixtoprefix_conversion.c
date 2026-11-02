#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAX_SIZE 100


void convert_infix_to_postfix(char infix[], char postfix[]);
void reverse_and_swap_parentheses(char original[], char reversed[]);
void string_reverse(char original[], char reversed[]);
int input_prec(char);
int stack_prec(char);
void push(char);
char pop();
char seek();


char s[MAX_SIZE];
int t = -1;

int main() 
{
    char infix[MAX_SIZE], reversed_infix[MAX_SIZE];
    char temp_postfix[MAX_SIZE], final_prefix[MAX_SIZE];

    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = 0; 
	
    reverse_and_swap_parentheses(infix, reversed_infix);

    convert_infix_to_postfix(reversed_infix, temp_postfix);

    string_reverse(temp_postfix, final_prefix);

    printf("%s\n", final_prefix);

    return 0;
}


void reverse_and_swap_parentheses(char original[], char reversed[]) 
{
    int len = strlen(original);
    int j = 0;
    for (int i = len - 1; i >= 0; i--) 
	{
        if (original[i] == '(') 
		{
            reversed[j++] = ')';
        } 
		else if (original[i] == ')') 
		{
            reversed[j++] = '(';
        } 
		else 
		{
            reversed[j++] = original[i];
        }
    }
    reversed[j] = '\0';
}


void string_reverse(char original[], char reversed[]) 
{
    int len = strlen(original);
    int j = 0;
    for (int i = len - 1; i >= 0; i--) 
	{
        reversed[j++] = original[i];
    }
    reversed[j] = '\0';
}


void convert_infix_to_postfix(char infix[], char postfix[]) 
{
    int i = 0, j = 0;
    push('#');
    while (infix[i] != '\0') 
	{
        while (stack_prec(seek()) > input_prec(infix[i])) 
		{
            postfix[j++] = pop();
        }
        if (stack_prec(seek()) != input_prec(infix[i])) 
		{
            push(infix[i]);
        } 
		else 
		{
            pop();
        }
        i++;
    }
    while (seek() != '#') 
	{
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int input_prec(char ch) 
{
    switch (ch) 
	{
        case '+': case '-': return 1;
        case '*': case '/': return 3;
        case '^': return 6;
        case '(': return 9;
        case ')': return 0;
        default:  return 7;
    }
}

int stack_prec(char ch) 
{
    switch (ch) 
	{
        case '+': case '-': return 2;
        case '*': case '/': return 4;
        case '^': return 5;
        case '(': return 0;
        case '#': return -1;
        default:  return 8;
    }
}

void push(char ch) 
{
    if (t < MAX_SIZE - 1) 
	{
        s[++t] = ch;
    }
}

char pop() 
{
    if (t > -1) 
	{
        return s[t--];
    }
    return '#';
}

char seek() 
{
    if (t > -1) 
	{
        return s[t];
    }
    return '#';
}