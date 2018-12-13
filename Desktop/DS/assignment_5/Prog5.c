#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next,*prev;
};
typedef struct node NODE;

NODE *createList(int num){ 
	NODE *p= (NODE *)malloc(sizeof(NODE));
	p->data = num;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

NODE *insertStart(NODE *head,int num){
	NODE *p= (NODE *)malloc(sizeof(NODE));
	p->data = num;
	p->next = head;
	p->prev = NULL;
	if(head != NULL)
		head->prev = p;
	return p;
}

NODE *insertEnd(NODE *head,int num){
	NODE *p= (NODE *)malloc(sizeof(NODE)),*q=head;
	p->data = num;
	p->next = NULL;
	p->prev = NULL;
	if(head == NULL)
		return p;
	
	while(q->next != NULL)
		q = q->next;
	q->next = p;
	p->prev = q;
	return head;
}

NODE *insertBeforeX(NODE *head,int num,int x){  //let assume that X is present in list //
	NODE *p= (NODE *)malloc(sizeof(NODE)),*q=head;
	p->data = num;
	if(head->data == x){
		p->next = head;
		head->prev = p;
		p->prev = NULL;
		return p;
	}
	while(q->next->data != x)
		q = q->next;
	p->next = q->next;
	p->prev = q;
	q->next->prev = p;
	q->next = p;
	return head;
}

NODE *insertAfterX(NODE *head,int num,int x){ //let assune that X is present in list //
	NODE *p= (NODE *)malloc(sizeof(NODE)),*q=head;
	p->data = num;
	while(q->data != x)
		q = q->next;
	
	p->next = q->next;
	p->prev = q;
	if(q->next != NULL)
		q->next->prev = p;
	q->next= p;
	return head;
}

NODE *deleteFirst(NODE *head){
	if(head == NULL){
		printf("no element found...\n");
	}
	else{
		NODE *p;
		p = head;
		head = head->next;
		if(head != NULL)
			head->prev = NULL;
		free(p);
	}
	return head;
}

NODE *deleteLast(NODE *head){
	NODE *p = head,*q=NULL;
	if(head == NULL){
		printf("empty list: ");
		return head;
	}
	if(head->next == NULL)
	{
		free(head);
		return q;
	}
	while(p->next != NULL){
		p=p->next;
	}
	q = p->prev;
	q->next = NULL;
	free(p);
	return head;
}

NODE *deleteX(NODE *head,int x) //it is assumed that X is present in list //
{
	NODE *p = head,*q;
	if(head->data == x)
	{
		head = head->next;
		head->prev = NULL;
		free(p);
		return head;
	}
	while(p->next->data != x )
		p=p->next;
	q = p->next;
	p->next = p->next->next;
	if(p->next != NULL)
		p->next->prev = p;
	free(q);
	return head;
}

void display(NODE *head){
	while(head != NULL){
		printf("%d\t",head->data);
		head = head->next;
	}
	printf("\n");
}

int main(){	
	int choice,num,x;
	NODE *head = NULL; 
	printf("select your choice...\n");
	while(1){	
		printf("1. To create list(initial step!)\n"); //first of all you have to creat list //
		printf("2. To insert element at start:\n");
		printf("3. To insert at end\n");
		printf("4. To insert before a given element X\n");
		printf("5. To insert after a given element X\n");
		printf("6. To delete first element\n");
		printf("7. To delete last element:\n");
		printf("8. To delete element of information X:\n");
		printf("9. To display the list:\n");
		printf("10. To exit:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter the data: ");
				scanf("%d",&num);
				head = createList(num);
				break;
			case 2:
				printf("enter the data:");
				scanf("%d",&num);
				head = insertStart(head,num);
				break;
			case 3:
				printf("enter the data:");
				scanf("%d",&num);
				head = insertEnd(head,num);
				break;
			case 4:
				printf("enter the data:");
				scanf("%d",&num);
				printf("enter the element X before which you have to insert new data:");
				scanf("%d",&x);
				head = insertBeforeX(head,num,x);
				break;
			case 5:
				printf("enter the data:");
				scanf("%d",&num);
				printf("enter the element X after which you have to insert new data:");
				scanf("%d",&x);
				head = insertAfterX(head,num,x);
				break;
			case 6:
				head = deleteFirst(head);
				break;
			case 7:
				head = deleteLast(head);
				break;
			case 8:
				printf("enter the data to which you want to delete:");
				scanf("%d",&x);
				head = deleteX(head,x);
				break;
			case 9:
				display(head);
				break;
			case 10:
				exit(0);
			default:
				printf("invalid input, enter again...\n");
		}
	}
	return 0;	
}