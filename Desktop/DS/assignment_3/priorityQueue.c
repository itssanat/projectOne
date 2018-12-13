#include<stdio.h>
#include<stdlib.h>
#define qSize 100

struct queue{
	int arr[qSize];
	int front,rear;
};
typedef struct queue QUEUE;

void enque(QUEUE * q,int n){
	if(q->rear == qSize -1)
		printf("queue is full\n");
	else 
		q->arr[++q->rear] = n;
}

void deque(QUEUE *q){
	int max=0,i,index;
	if(q->front == q->rear+1)
		printf("queue is empty...\n");
	else{
		for(i = q->front;i<=q->rear;i++)
			if(q->arr[i]>max){
				max = q->arr[i];
				index = i;
			}
		printf("deleted number is %d \n",max);
		for(i=index;i<q->rear;i++)
			q->arr[i] = q->arr[i+1];
		q->rear--;
	}
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
		printf("enter 1 to insert an element in queue:\n");
		printf("enter 2 to delete an element from queue:\n");
		printf("enter 3 to display the elements of queue:\n");
		printf("enter 4 to exit:\n");
		scanf("%d",&x);
		switch(x){
			case 1:
			printf("enter the number.");
			scanf("%d",&n);
			enque(&que,n);
			break;
			case 2:
			deque(&que);
			break;
			case 3:
			display(&que);
			break;
			case 4:
			exit(0);
			default :
			printf("invalid input, please enter again...\n");
		}
	}
}
