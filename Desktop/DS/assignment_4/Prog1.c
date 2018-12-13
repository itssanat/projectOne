#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

struct queue{
	int arr[SIZE];
	int front,rear;
};
typedef struct queue QUEUE;

void enque(QUEUE *q, int num){
	if(q->rear == SIZE-1){
		printf("stack is full");
	} else {
		q->arr[++q->rear] = num;
	}

}

int dequeue(QUEUE *q){
	if(q->front == q->rear+1){
		printf("stack is empty");
		return -1;
	} 
	return q->arr[q->front++];
}

void pop(QUEUE *q,QUEUE * t){
	int num;
	if(q->front==q->rear+1){
		printf("stack is empty");
		return ;
	}
	t->front = 0, t->rear = -1;
	while(q->front!=q->rear){
		enque(t,dequeue(q));
	}
	num = q->arr[q->front];
	q->front = 0,q->rear = -1;
	
	while(t->front!=t->rear+1){
		enque(q,dequeue(t));
	}
	printf("poped number is %d\n",num);
}

void display(QUEUE *q){
	int i;
	for(i = q->front;i<=q->rear;i++)
		printf("%d\t",q->arr[i]);
	printf("\n\n");
}
	

int main(){
	QUEUE que,tmp;
	que.front = 0 , que.rear =-1;
	tmp.front = 0, tmp.rear = -1;
	int x,num;
	while(1){
		printf("enter 1 to push\n");
		printf("enter 2 to pop\n");
		printf("enter 3 to disply:\n");
		printf("enter 4 to exit:\n");
		scanf("%d",&x);
		
		switch(x){
			case 1:
				printf("enter your number: ");
				scanf("%d",&num);
				enque(&que,num);
				break;
			case 2:
				pop(&que,&tmp);
				break;
			case 3:
				display(&que);
				break;
			case 4:
				exit(1);
			default:
				printf("invalid input...\n");
		}
	}
	return 0;
}