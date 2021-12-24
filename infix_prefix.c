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
	}
}

void reverse(char *str)
{	
	char *temp;
	int i, k=0;
	for(i = strlen(str)-1; i>=0; i--)
	{
		temp[k++] = str[i];
	}
	temp[k] = '\0';

	strcpy(str, temp);
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
	char infix[50], prefix[50];
	printf("\nEnter infix expression - \n");
	scanf("%s", infix);
	int i=0, k=0;
	reverse(infix);
	while(i!=strlen(infix))
	{
		if(isalpha(infix[i]))
		{
			prefix[k++] = infix[i];
		}
		else if((prec(peek(ptr))<=prec(infix[i]))||isEmpty(ptr)||infix[i] == ')')
				push(ptr, infix[i]);
		else if(infix[i] == '(')
		{
				
				while(peek(ptr)!=')' && !isEmpty(ptr))
					prefix[k++] = pop(ptr);

				char junk = pop(ptr);
		}
		else if(prec(peek(ptr))>prec(infix[i]))
		{
			while(prec(peek(ptr))>prec(infix[i]))
			{
					prefix[k++] = pop(ptr);
			}
			push(ptr, infix[i]);
		}
		i++;
	}

	while(!isEmpty(ptr))
		prefix[k++] = pop(ptr);

	prefix[k] = '\0';
	reverse(prefix);

	printf("\nPrefix - %s\n", prefix);
		
}