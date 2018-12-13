#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
typedef struct node NODE;

NODE * enqueue(NODE *head, int x)
{
	NODE *p ,*q = head;
	p = (NODE *)malloc(sizeof(NODE));
	p->info = x;
	p->next = NULL;
	if(head == NULL)
	return p;
	while(q->next != NULL)
		q =q->next;
	q->next = p;
	return head;
}

void display(NODE * head)
{
	NODE * p = head;
	while(p != NULL){
		printf("%d  ",p->info);
		p = p->next;
	}
	printf("\n");
}

NODE * dequeue(NODE * head)
{
	NODE *p = head;
	if(head == NULL){
		printf("queue is empty...\n");
		return NULL;
	}
	else if(head->next == NULL){
		int q = head->info;
		printf("%d is deleted\n",q);
		free(p);
		return NULL;
	}
	else{
		int q = p->info;
		printf("%d is deleted\n",q);
		head = p->next;
		free(p);
		return head;
	}
}

void main()
{
	int x,n,c = 1;
	NODE *head = NULL;
	printf("enter your choice\n");
	while(c){
		printf("1. enqueue element in stack\n");
		printf("2. to dequeue\n");
		printf("3. to display\n");
		printf("4. to break\n");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("enter info: ");
				scanf("%d",&n);
				head = enqueue(head,n);
				break;
			case 2:
				head = dequeue(head);
				break;
			case 3:
				display(head);
				break;
			case 4:
				c = 0;
				break;
			default: 
				printf("invalid input: ");
		}
	}
}