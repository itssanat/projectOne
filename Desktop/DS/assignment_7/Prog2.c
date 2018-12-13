#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coeff,exp;
	struct node *next;
};
typedef struct node NODE;

NODE * insertEnd(NODE *head, int c , int e)
{
	NODE *p,*q = head;
	p = (NODE *)malloc(sizeof(NODE));
	p->coeff = c;
	p->exp = e;
	p->next = NULL;
	if(head == NULL)
		return p;
	while(q->next != NULL)
		q= q->next;
	q->next = p;
	return head;
}

void display(NODE * head)
{
	NODE * p = head;
	while(p != NULL){
		printf("%dX^%d + ",p->coeff,p->exp);
		p = p->next;
	}
	printf("\n");
}

NODE * addNode(c,e)
{
	NODE * p = (NODE *)malloc(sizeof(NODE));
	p->coeff = c;
	p->exp = e;
	p->next = NULL;
	return p;
}

NODE * addPoly(NODE * p1,NODE *p2)
{
	NODE *p=p1,*q=p2 , *r;
	NODE *header = (NODE *)malloc(sizeof(NODE));
	r = header;
	if(p1 == NULL)
		return p2;
	if(p2 == NULL)
		return p1;
	while(p!=NULL && q!=NULL)
	{
		if(p->exp > q->exp){
			r->next = addNode(p->coeff,p->exp);
			p=p->next;
		}
		else if(q->exp > p->exp){
			r->next = addNode(q->coeff,q->exp);
			q=q->next;
		}
		else 
		{
			if((p->coeff+q->coeff) != 0)
			{	
				r->next = addNode((p->coeff+q->coeff),p->exp);
			}
			p=p->next;
			q=q->next;
		
		}	
		r=r->next;
	}
	if(q != NULL)
	r->next = q;
	if(p != NULL)
	r->next = p;
	return header->next;
}

void main()
{
	int check = 1,c,e,x;
	NODE *p1 = NULL,*p2 = NULL,*p3 = NULL;
	printf("enter first polynomial: \n");
	while(check){
		printf("1. insert node\n");
		printf("2. to finish\n");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("enter coeff. and exponent: ");
				scanf("%d%d",&c,&e);
				p1 = insertEnd(p1,c,e);
				break;
			case 2:
				check = 0;
				break;
			default: 
				printf("invalid input: ");
		}
	}
	check= 1;
	printf("enter second polynomial: \n");
	while(check){
		printf("1. insert node\n");
		printf("2. to finish\n");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("enter coeff. and exponent: ");
				scanf("%d%d",&c,&e);
				p2 = insertEnd(p2,c,e);
				break;
			case 2:
				check = 0;
				break;
			default: 
				printf("invalid input: ");
		}
	}
	display(p1);
	display(p2);
	printf("polynomial after adding\n");
	p3 = addPoly(p1,p2);
	display(p3);
}























