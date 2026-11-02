#include <stdio.h>
#include <string.h>

void convert_infix_to_postfix(char infix[], char postfix[]) 
{
    int i = 0, j = 0;
    char stack[100];
    int top = -1;

    for (i = 0; infix[i] != '\0'; i++) 
	{
        char ch = infix[i];
        if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9') 
		{
            postfix[j++] = ch;
        } 
		else if (ch == '(') 
		{
            stack[++top] = ch;
        } 
		else if (ch == ')') 
		{

            while (top != -1 && stack[top] != '(') 
			{
                postfix[j++] = stack[top--];
            }
            if (top != -1 && stack[top] == '(') 
			{
                top--;
            }
        } 
		else 
		{
            while (top != -1 && stack[top] != '(') 
			{
                postfix[j++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while (top != -1) 
	{
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}

void main() 
{
    char infix[100], postfix[100];
    printf("Enter a fully parenthesized infix expression: ");
    scanf("%s", infix);
    convert_infix_to_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
}
