#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
	int top;
	char stk[50];
}STACK;

void push(STACK *ptr, char el)
{
	ptr->stk[++ptr->top] = el;
}

char pop(STACK *ptr)
{
	return ptr->stk[ptr->top --];
}

char peek(STACK *ptr)
{
	return ptr->stk[ptr->top];
}

int prec(char x)
{
	switch(x)
	{
		case '+':
		case '-':
			return 0;
		case '*':
		case '/':
		case '%':
			return 1;
		case '^':
			return 2;
	}
}

int isEmpty(STACK *ptr)
{
	if(ptr->top == -1)
		return 1;
	else
		return 0;
}

int main()
{
	STACK *ptr;
	ptr = (STACK*)malloc(sizeof(STACK));

	ptr->top = -1;
	char infix[50], postfix[50];
	printf("\nEnter infix expression - \n");
	scanf("%s", infix);
	int i=0, k=0;
	while(i!=strlen(infix))
	{
		if(isalpha(infix[i]))
		{
			postfix[k++] = infix[i];
		}
		else if((prec(peek(ptr))<prec(infix[i]))||isEmpty(ptr)||infix[i] == '(')
				push(ptr, infix[i]);
		else if(infix[i] == ')')
		{
				
				while(peek(ptr)!='(' && !isEmpty(ptr))
					postfix[k++] = pop(ptr);

				
				char junk = pop(ptr);
		}
		else if(prec(peek(ptr))>=prec(infix[i]))
		{
			while(prec(peek(ptr))>=prec(infix[i]))
			{
					postfix[k++] = pop(ptr);
			}
			push(ptr, infix[i]);
		}
		i++;
	}

	while(!isEmpty(ptr))
		postfix[k++] = pop(ptr);

	postfix[k] = '\0';

	printf("\nPostfix - %s\n", postfix);
		
}