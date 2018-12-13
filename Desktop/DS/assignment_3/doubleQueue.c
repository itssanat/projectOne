#include<stdio.h>
#include<stdlib.h>
#define qSize 100

struct queue{
	int arr[qSize];
	int front,rear;
};
typedef struct queue QUEUE;

void insertFront(QUEUE * q,int n){
	if(q->front == 0)
		printf("local overflow\n");
	else 
		q->arr[--q->front] = n;
}

void insertLast(QUEUE * q,int n){
	if(q->rear == qSize -1)
		printf("local overflow\n");
	else 
		q->arr[++q->rear] = n;
}

void deleteFront(QUEUE *q){
	if(q->front == q->rear+1)
		printf("queue is empty...\n");
	else
		printf("deleted number is %d \n",q->arr[q->front++]);
}

void deleteLast(QUEUE *q){
	if(q->front == q->rear+1)
		printf("queue is empty...\n");
	else
		printf("deleted number is %d \n",q->arr[q->rear--]);
}

void display(QUEUE *q){
	int i;
	if(q->front == q->rear+1)
		printf("queue is empty...\n");
	else{
		for(i = q->front;i<=q->rear;i++)
			printf("%d\t",q->arr[i]);
		printf("\n");
	}
}

void main(){
	QUEUE que;
	que.front  = 0;
	que.rear = -1;
	int x,n;
	while(1){
		printf("enter 1 to insert an element in at front:\n");
		printf("enter 2 to insert an element in at last:\n");
		printf("enter 3 to delete an element from front:\n");
		printf("enter 4 to delete an element from last:\n");
		printf("enter 5 to display the elements of queue:\n");
		printf("enter 6 to exit:\n");
		scanf("%d",&x);
		switch(x){
			case 1:
			printf("enter the number.");
			scanf("%d",&n);
			insertFront(&que,n);
			break;
			case 2:
			printf("enter the number.");
			scanf("%d",&n);
			insertLast(&que,n);
			break;
			case 3:
			deleteFront(&que);
			break;
			case 4:
			deleteLast(&que);
			break;
			case 5:
			display(&que);
			break;
			case 6:
			exit(0);
			default :
			printf("invalid input, please enter again...\n");
		}
	}
}
