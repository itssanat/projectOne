#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
typedef struct node NODE;

NODE * push(NODE *head, int x)
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

NODE * pop(NODE * head)
{
	NODE *p = head;
	if(head == NULL){
		printf("stack is empty...\n");
		return NULL;
	}
	else if(head->next == NULL){
		int q = head->info;
		printf("%d is poped\n",q);
		free(p);
		return NULL;
	}
	else{
		while(p->next->next != NULL)
			p=p->next;
		int q = p->next->info;
		printf("%d is poped\n",q);
		free(p->next);
		p->next = NULL;
		return head;
	}
}

void main()
{
	int x,n,c = 1;
	NODE *head = NULL;
	printf("enter your choice\n");
	while(c){
		printf("1. push element in stack\n");
		printf("2. to pop\n");
		printf("3. to display\n");
		printf("4. to break\n");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("enter info: ");
				scanf("%d",&n);
				head = push(head,n);
				break;
			case 2:
				head = pop(head);
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