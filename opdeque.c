#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

int size =0;

struct link
{
	char data[50];
	struct link *next;
};

typedef struct link *node;

typedef struct
{
	node front, rear;
}deque;

int isEmpty(deque *q)
{
	if(q->front ==NULL)
		return 1;
	else
		return 0;
}

int isFull()
{
	if(size == MAX )
		return 1;
	else
		return 0;
}

void enqueueF(deque *q, char *el)
{
	if(isFull())
	{
		printf("\nQueue is full!\n");
		return;
	}
	size++;
	node ptr = (node)malloc(sizeof(struct link));
	strcpy(ptr->data, el);
	if(q->rear == NULL && q->front == NULL)
	{
		q->front = ptr; q->rear = ptr;
	}
	else
	{
		ptr->next = q->front;
		q->front = ptr;
	}
}

void enqueueR(deque *q, char *el)
{
	if(isFull())
	{
		printf("\nQueue is full!\n");
		return;
	}
	size++;
	node ptr = (node)malloc(sizeof(struct link));
	strcpy(ptr->data, el);
	ptr->next = NULL;
	if(q->rear == NULL && q->front == NULL)
	{
		q->front = ptr; q->rear = ptr;
	}
	else
	{
		(q->rear)->next = ptr;
		q->rear = ptr;
	}
}



void dequeue(deque *q)
{
	if(isEmpty(q))
	{
		printf("\nQueue is empty!\n");
		return;
	}
	printf("\nElement dequeued -> %s\n", q->front->data);
	q->front = q->front->next;
}



void display(deque *q)
{
	if(isEmpty(q))
	{
		printf("\nQueue is empty!\n");
		return;
	}
	node ptr = (node)malloc(sizeof(struct link));
	ptr = q->front;
	while(ptr!=NULL)
	{
		printf("%s <- ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int main()
{
	deque *q;
	q = (deque*)malloc(sizeof(deque));
	q->front = NULL; q->rear = NULL;

	int op;
	do
	{
		printf("\nMenu \n1.Enqueue at front \n2.Enqueue at rear \n3.Dequeue \n4.Display \n5.Exit");
		printf("\nEnter option - ");
		scanf("%d", &op);

		switch(op)
		{
			case 1:
			{
				char ch = 'y'; char el[50];
				while(ch == 'y')
				{
					printf("\nEnter element - ");
					scanf("%s", el);
					enqueueF(q, el);
					printf("\nEnter again? ");
					scanf(" %c", &ch);
				}
			}break;

			case 2:
			{
				char ch = 'y'; char el[50];
				while(ch == 'y')
				{
					printf("\nEnter element - ");
					scanf("%s", el);
					enqueueR(q, el);
					printf("\nEnter again? ");
					scanf(" %c", &ch);
				}
			}break;

			case 3:
			{
				char ch = 'y';
				while(ch == 'y')
				{
					dequeue(q);
					printf("\nDelete again? ");
					scanf(" %c", &ch);
				}
			}break;

			case 4:
			{
				display(q);
			}break;

			case 5:
			{
				printf("\nAnusha Panchumarthi Reg no. 200905202\n\n");
				return 0;
			}break;

			default:
			{
				free(q);
				printf("\nInvalid input!\n");
			}
		}
	}while(op!=5);
	return 0;
}

