#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next,*prev;
};
typedef struct node NODE;

NODE *createList(){ 
	NODE *p= (NODE *)malloc(sizeof(NODE));
	p->next = p;
	p->prev = p;
	return p;
}

NODE *insertStart(NODE *head,int num){
	NODE *p= (NODE *)malloc(sizeof(NODE)),*q;
	p->data = num;
	p->next = head->next;
	p->prev = head;
	head->next->prev = p;
	head->next = p;
	return head;
}

NODE *insertEnd(NODE *head,int num){
	NODE *p= (NODE *)malloc(sizeof(NODE)),*q=head;
	p->data = num;
	
	q = head->prev;
	q->next = p;
	p->prev = q;
	p->next = head;
	head->prev = p;
	return head;
}

NODE *insertBeforeX(NODE *head,int num,int x){  //let assume that X is present in list //
	NODE *p= (NODE *)malloc(sizeof(NODE)),*q = head->next;
	p->data = num;
	while(q->data != x)
		q = q->next;
	p->next = q;
	p->prev = q->prev;
	q->prev->next = p;
	q->prev = p;
	return head;
}

NODE *insertAfterX(NODE *head,int num,int x){ //let assune that X is present in list //
	NODE *p= (NODE *)malloc(sizeof(NODE)),*q=head->next;
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
	if(head == NULL || head->next == head){
		printf("no element found...\n");
		return head;
	}
	NODE *p;
	p = head->next;
	head->next = p->next;
	p->next->prev = head;
	free(p);
	return head;
}

NODE *deleteLast(NODE *head){
	NODE *p = head,*q=NULL;
	if(head == NULL || head->next == head){
		printf("empty list: ");
		return head;
	}
	p = head->prev;
	head->prev = p->prev;
	p->prev->next = head;
	free(p);
	return head;
}

NODE *deleteX(NODE *head,int x) //it is assumed that X is present in list //
{
	NODE *p = head->next,*q;
	while(p->data != x )
		p=p->next;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
	return head;
}

void display(NODE *head){
	NODE *p = head->next;
	while(p != head){
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("\n");
}

int main(){	
	int choice,num,x;
	NODE *head = NULL; 
	printf("select your choice...\n");
	while(1){	
		printf("1. To create header(initial step!)\n"); //first of all you have to creat list //
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
				head = createList();
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