#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct link
{
	char data;
	struct link *next;
};

typedef struct link  *node;

typedef struct
{
	node rear, front;
}QUEUE;


int isEmpty(QUEUE *q)
{
	if(q->front == NULL && q->rear==NULL)
		return 1;
	else
		return 0;
}

void enqueueR(QUEUE *q, int el)
{
	node ptr= (node)malloc(sizeof(struct link));
	ptr->data = el;
	ptr->next = NULL;
	if(q->front == NULL && q->rear==NULL)
	{
		q->front = ptr; 
		q->rear = ptr;
	}
	else
	{
		(q->rear)->next = ptr;
		q->rear = ptr;
	}
}

char dequeueR(QUEUE *q)
{
	char val;
	if(isEmpty(q))
	{
		printf("\nQueue is empty!!\n");
		return 0;
	}
	node ptr = (node)malloc(sizeof(struct link));
	ptr = q->front;
	val = q->rear->data;//printf("\n val = %c", val);
	while(ptr->next!=q->rear)
	{
		ptr = ptr->next;
	}
	q->rear = ptr;
	q->rear->next = NULL;
	return val;
}

char dequeueF(QUEUE *q)
{
	char val;
	if(isEmpty(q))
	{
		printf("\nQueue is empty!!\n");
		return 0;
	}
	val=q->front->data;//printf("\n val = %c", val);
	q->front = q->front->next;
	return val;
}

void display(QUEUE *q)
{
	node temp;
	temp = q->front;
	if(isEmpty(q))
	{
		printf("\nQueue is empty!!\n");
		return;
	}
	printf("\nQueue - \n");
	while(temp!=NULL)
	{
		printf("%d <- ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	char str[50];
	QUEUE *q;
	q = (QUEUE*)malloc(sizeof(QUEUE));
	printf("\nEnter a string- ");
	scanf("%s", str);
	int i;
	for(i=0; str[i]!='\0'; i++)
	{
		enqueueR(q, str[i]);
	}

	int count, flag =0;
	if(strlen(str)%2==0) 
		count = strlen(str)/2 -1; 
	else 
		count = strlen(str)/2;

	while(count!=0)
	{
		if(dequeueF(q)!=dequeueR(q))
		{
			flag =1 ;
			break;
		}

		count--;
	}

	if(strlen(str)%2==0)
	{
		char ch = dequeueF(q);
		if(ch != q->rear->data)
			flag = 1;
	}
	
	if(flag==0)
		printf("\nPalindrome\n");
	else
		printf("\nNot a palindrome\n");

	printf("\nAnusha Panchumarthi Reg no. 200905202\n\n");
	return 0;
}