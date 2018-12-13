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
	p->next = p;
	p->prev = p;
	return p;
}

NODE *insertStart(NODE *head,int num){
	NODE *p= (NODE *)malloc(sizeof(NODE)),*q;
	p->data = num;
	p->next = head;
	if(head != NULL)
		head->prev = p;
	q = p;
	while(q->next!=NULL)
		q= q->next;
	p->prev = q;
	return p;
}

NODE *insertEnd(NODE *head,int num){
	NODE *p= (NODE *)malloc(sizeof(NODE)),*q=head;
	p->data = num;
	p->next = p;
	p->prev = p;
	if(head == NULL)
		return p;
	
	while(q->next != NULL)
		q = q->next;
	q->next = p;
	p->prev = q;
	p->next = head;
	head->prev = p;
	return head;
}

NODE *insertBeforeX(NODE *head,int num,int x){  //let assume that X is present in list //
	NODE *p= (NODE *)malloc(sizeof(NODE)),*q=head;
	p->data = num;
	while(q->data != x)
		q = q->next;
	p->next = q;
	p->prev = q->prev;
	q->prev->next = p;
	q->prev = p;
	if(head->data == x)
		return p;
	return head;
}

NODE *insertAfterX(NODE *head,int num,int x){ //let assune that X is present in list //
	NODE *p= (NODE *)malloc(sizeof(NODE)),*q=head;
	p->data = num;
	while(q->data != x)
		q = q->next;
	p->next = q->next;
	p->prev = q;
	q->next->prev = p;
	q->next= p;
	return head;
}

NODE *deleteFirst(NODE *head){
	if(head == NULL){
		printf("no element found...\n");
		return head;
	}
	if(head->next = head){
		free(head);
		return NULL;
	}
	NODE *p;
	p = head;
	head = head->next;
		
	head->prev = p->prev;
	p->prev->next = head;
	free(p);
	return head;
}

NODE *deleteLast(NODE *head){
	NODE *p = head,*q=NULL;
	if(head == NULL){
		printf("empty list: ");
		return head;
	}
	if(head->next == head)
	{
		free(head);
		return q;
	}
	p = head->prev;
	head->prev = p->prev;
	p->prev->next = head;
	free(p);
	return head;
}

NODE *deleteX(NODE *head,int x) //it is assumed that X is present in list //
{
	NODE *p = head,*q;
	if(head->data == x && head->next == head){
		free(head);
		return NULL;
	}
	while(p->data != x )
		p=p->next;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	if(p == head)
		head = p->next;
	free(q);
	return head;
}

void display(NODE *head){
	NODE *p = head,*q = NULL;
	while(head != q){
		printf("%d\t",head->data);
		head = head->next;
		q = p;
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