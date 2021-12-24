#include <stdio.h>
#include <stdlib.h>

struct link
{
	int data;
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

void enqueueF(QUEUE *q, int el)
{
	node ptr= (node)malloc(sizeof(struct link));
	ptr->data = el;
	
	if(q->front == NULL && q->rear==NULL)
	{
		q->front = ptr; 
		q->rear = ptr;
		ptr->next = NULL;
	}
	else
	{
		ptr->next = q->front;
		q->front = ptr;
	}
}

void dequeueR(QUEUE *q)
{
	if(isEmpty(q))
	{
		printf("\nQueue is empty!!\n");
		return;
	}
	node ptr = (node)malloc(sizeof(struct link));
	ptr = q->front;
	printf("\nElement dequeued - %d\n", q->rear->data);
	while(ptr->next!=q->rear)
	{
		ptr = ptr->next;
	}
	q->rear = ptr;
	q->rear->next = NULL;

}

void dequeueF(QUEUE *q)
{
	if(isEmpty(q))
	{
		printf("\nQueue is empty!!\n");
		return;
	}
	printf("\nElement dequeued - %d\n", q->front->data);
	q->front = q->front->next;
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
	QUEUE *q;
	q = (QUEUE*)malloc(sizeof(QUEUE));
	enqueueR(q, 2);
	enqueueR(q, 3);
	enqueueF(q, 1);
	enqueueF(q, 0);
	enqueueR(q, 4);

	display(q);
	dequeueF(q);
	display(q);
	dequeueR(q);
	display(q);

}