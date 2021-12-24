#include <stdio.h>
#include <stdlib.h>

struct link
{
	int data;
	struct link *next;
};

typedef struct link *node;

typedef struct 
{
	node front, rear;
}QUEUE;

int isEmpty(QUEUE *q)
{
	if(q->rear == NULL)
		return 1;
	else
		return 0;
}
void enqueue(QUEUE *q, int el)
{
	node ptr= (node)malloc(sizeof(struct link));
	ptr->data = el;
	ptr->next = NULL;
	if(q->rear == NULL)
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

dequeue(QUEUE *q)
{
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
	q->front =NULL;
	q->rear = NULL;


	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);
	display(q);
	dequeue(q);
	dequeue(q);
	display(q);
	enqueue(q, 5);
	display(q);
}