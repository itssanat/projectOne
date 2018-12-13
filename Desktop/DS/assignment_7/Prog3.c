#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node *next;
};
typedef struct node NODE;
int carry;
NODE * insertEnd(NODE *head, int i)
{
	NODE *p,*q = head;
	p = (NODE *)malloc(sizeof(NODE));
	p->num = i;
	p->next = NULL;
	if(head == NULL)
		return p;
	while(q->next != NULL)
		q= q->next;
	q->next = p;
	return head;
}

NODE * insertFront(NODE * head,int n)
{
	NODE * p = (NODE *)malloc(sizeof(NODE));
	p->num = n;
	p->next = head;
	return p;
}

void display(NODE * head)
{
	NODE * p = head;
	if(carry != 0)
	printf("%d",carry);
	while(p != NULL){
		if(p->num == 0)
		printf("00000");
		else
		printf("%d",p->num);
		p = p->next;
	}
	printf("\n");
}

NODE * addNum(NODE * n1 , NODE * n2)
{
	NODE * p =n1,*q = n2 ,*r = NULL;
	NODE * ap=NULL, *aq=NULL;
	int num;
	carry = 0;
	if(p == NULL)
		return q;
	if(q == NULL)
		return p;
	do{
		p = n1 , q = n2;
		while(p->next != ap)
			p=p->next;
		while(q->next != aq)
			q=q->next;
		num = p->num+q->num+carry;
		carry = num/100000;
		num = num%100000;
		r = insertFront(r , num);
		ap = p;
		aq = q;
	} while(ap!=n1 && aq!=n2);
	
	if(ap != n1)
	{
		p = n1;
		while(p->next != ap)
		p=p->next;
		p->next = r;
		return n1;
	}
	if(aq != n2)
	{
		q = n2;
		while(q->next != aq)
		q=q->next;
		q->next = r;
		return n2;
	}
	return r;
}

void main()
{
	int x,n,c = 1;
	NODE *n1 = NULL ,* n2= NULL, *n3 = NULL;
	printf("enter first number: \n");
	while(c){
		printf("1. insert number:\n");
		printf("2. to finish\n");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("enter number in group of 5 digit: ");
				scanf("%d",&n);
				n1 = insertEnd(n1,n);
				break;
			case 2:
				c = 0;
				break;
			default: 
				printf("invalid input: ");
		}
	}
	c= 1;
	printf("\n\nenter second number: \n");
	while(c){
		printf("1. insert number:\n");
		printf("2. to finish\n");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("enter number in group of 5 digit: ");
				scanf("%d",&n);
				n2 = insertEnd(n2,n);
				break;
			case 2:
				c = 0;
				break;
			default: 
				printf("invalid input: ");
		}
	}
	
	printf("number after adding: \n");
	n3 = addNum(n1 , n2);
	display(n3);
}























