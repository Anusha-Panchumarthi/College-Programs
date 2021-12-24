#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int size =0;
struct link
{
	int data;
	struct link *next;
};


typedef struct link* node;

typedef struct
{
	node front, rear;
}queue;



int isEmpty(queue *q)
{
	if(q->rear == NULL)
		return 1;
	else
		return 0;
}



int isFull()
{
	if(size==MAX)
		return 1;
	else
		return 0;
}



void apqinsert(queue *q, int el)
{
	if(isFull())
	{
		printf("\nQueue is full!\n");
		return;
	}

	size++;
	node ptr = (node)malloc(sizeof(struct link));
	ptr->data = el;
	ptr->next = NULL;
	if(q->rear == NULL)
	{
		q->front = ptr; q->rear = ptr;
	}
	else
	{
		(q->rear)->next = ptr;
		q->rear = ptr;
	}
}



void display(queue *q)
{
	if(isEmpty(q))
	{
		printf("\nQueue is empty!\n");
		return;
	}
	printf("\n");
	node ptr = (node)malloc(sizeof(struct link));
	ptr = q->front;
	while(ptr!=NULL)
	{
		printf("%d <- ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}



void apqdelete(queue *q)
{
	if(isEmpty(q))
	{
		printf("\nQueue is empty!\n");
		return;
	}

	if(q->rear == q->front)
	{
		printf("\nElement dequeued --> %d", q->rear->data);
		q->rear = NULL;
		q->front = NULL;
		return;
	}
	node ptr = (node)malloc(sizeof(struct link));
	ptr = q->front;
	int small = ptr->data;

	while(ptr!=NULL)
	{
		if(ptr->data<small)
			small = ptr->data;

		ptr = ptr->next;
	}

	ptr = q->front;
	printf("\nElement dequeued --> %d", small);

	if(q->front->data == small)
	{
		q->front = q->front->next;
		return;
	}

	while(ptr!=NULL){
		if(ptr->next->data == small)
		{
			if(ptr->next == q->rear)
			{
				q->rear = ptr;
				return;
			}
			ptr->next = ptr->next->next;
			return;
		}
		ptr = ptr->next;
	}
}


int main()
{
	queue *q;
	q = (queue*)malloc(sizeof(queue));
	q->front = NULL; q->rear = NULL;

	int op;
	do
	{
		printf("\nMenu \n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit");
		printf("\nEnter option - ");
		scanf("%d", &op);

		switch(op)
		{
			case 1:
			{
				char ch = 'y'; int el;
				while(ch == 'y')
				{
					printf("\nEnter element - ");
					scanf("%d",&el);
					apqinsert(q, el);
					printf("\nEnter again? ");
					scanf(" %c", &ch);
				}
			}break;

			case 2:
			{
				char ch = 'y';
				while(ch == 'y')
				{
					apqdelete(q);
					printf("\nDelete again? ");
					scanf(" %c", &ch);
				}
			}break;

			case 3:
			{
				display(q);
			}break;

			case 4:
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
	}while(op!=4);
	return 0;
}