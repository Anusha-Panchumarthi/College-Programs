#include<stdio.h>
#include<stdlib.h>

struct link
{
	int data;
	struct link *next;
};

typedef struct link *node;
node head= NULL;

void insert(int el)
{
	//at head
	node ptr = (node)malloc(sizeof(struct link));
	ptr->data = el;
	if(head == NULL)
	{
		head = ptr;
		ptr ->next = NULL;
	}
	else
	{
		ptr->next = head;
		head = ptr;
	}
}

int isEmpty()
{
	if(head==NULL)
		return 1;
	else
		return 0;
}

void insertafter(int el, int key)
{
	int flag =0 ;
	node temp = (node)malloc(sizeof(struct link));
	node ptr = (node)malloc(sizeof(struct link));
	ptr->data = el;
	temp = head;

	do
	{
		if(temp->data == key)
		{
			flag =1;
			ptr->next = temp->next;
			temp->next = ptr;
		}
		temp = temp->next;
	}while(temp!=NULL);

	if(flag==0)
	{
		printf("\nKey not found!!\n");
		return;
	}
}

void delete()
{
	if(isEmpty())
	{
		printf("\nList is empty!\n");
		return;
	}
	node ptr = (node)malloc(sizeof(struct link));
	ptr = head;
	while((ptr->next)->next !=NULL){
		ptr = ptr->next;
	}

	ptr->next = NULL;
}

void deleteafter(int key)
{
	if(isEmpty())
	{
		printf("\nList is empty!\n");
		return;
	}
	int flag =0 ;
	node temp = (node)malloc(sizeof(struct link));
	temp = head;

	while(temp!=NULL)
	{
		if(temp->data == key)
		{
			flag =1;
			temp->next = (temp->next)->next;
		}
		temp = temp->next;
	}

	if(flag==0)
	{
		printf("\nKey not found!!\n");
		return;
	}
}

void disp()
{
	if(isEmpty())
	{
		printf("\nList is empty!\n");
		return;
	}
	node ptr = (node)malloc(sizeof(struct link));
	ptr = head;

	printf("\nLinked list - \n");
	while(ptr!=NULL)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}
	free(ptr);
	printf("\n");
}

int main()
{
	int op;
	do
	{
		printf("\nMenu \n1.Insert at head \n2.Insert after \n3.Delete after \n4.Display \n5.Exit");
		printf("\nEnter option - ");
		scanf("%d", &op);
		switch(op)
		{
			case 1:
			{
				char ch = 'y';
				int el;
				while(ch == 'y')
				{
					printf("\nEnter element - ");
					scanf("%d", &el);
					insert(el);
					printf("\nInsert more? ");
					scanf(" %c", &ch);
				}
			}break;

			case 2:
			{
				char ch = 'y';
				int el; int key;
				while(ch == 'y')
				{
					printf("\nEnter key - ");
					scanf("%d", &key);
					printf("\nEnter element - ");
					scanf("%d", &el);
					insertafter(el, key);
					printf("\nInsert more? ");
					scanf(" %c", &ch);
				}
			}break;

			case 3:
			{
				char ch = 'y';
				int key;
				while(ch=='y')
				{
					printf("\nEnter key - ");
					scanf("%d", &key);
					deleteafter(key);
					printf("\nDelete more? ");
					scanf(" %c", &ch);

				}
			}break;

			case 4:
			{
				disp();
			}break;

			case 5:
			{
				return 0;
			}
		}
	}while(op!=5);
	return 0;
}