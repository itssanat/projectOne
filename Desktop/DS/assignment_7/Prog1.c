#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
typedef struct node NODE;

NODE * insertFront(NODE *head, int x)
{
	NODE *p;
	p = (NODE *)malloc(sizeof(NODE));
	p->info = x;
	p->next = NULL;
	if(head == NULL)
	return p;
	
	p->next = head;
	return p;
}

void display(NODE * head)
{
	NODE * p = head;
	while(p != NULL){
		printf("%d\t",p->info);
		p = p->next;
	}
	printf("\n");
}

NODE * split(NODE * head)
{
	NODE *p=head,*q=head;
	if(head!=NULL)
	{
		while(q!=NULL && q->next!=NULL)
		{
			p=p->next;
			q=q->next->next;
		}
	}
	
	if(q == NULL)
	{
		q = head;
		while(q->next != p)
			q= q->next;
		q->next = NULL;
		q = p;
		while(q->next != NULL)
			q=q->next;
		q->next = head;
		return p;
	}
	else
	{
		q->next = head;
		q = p->next;
		p->next = NULL;
		return q;
	}
}

void main()
{
	int x,n,c = 1;
	NODE *head = NULL;
	printf("enter your choice\n");
	while(c){
		printf("1. insert node\n");
		printf("2. to finish\n");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("enter info: ");
				scanf("%d",&n);
				head = insertFront(head,n);
				break;
			case 2:
				c = 0;
				break;
			default: 
				printf("invalid input: ");
		}
	}
	
	printf("list before spliting\n");
	display(head);
	printf("list after spliting\n");
	head = split(head);
	display(head);
}























