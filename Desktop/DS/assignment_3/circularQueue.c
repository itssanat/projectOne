#include<stdio.h>
#include<stdlib.h>
#define qSize 5
int check=0;

struct queue{
	int arr[qSize];
	int front,rear;
};
typedef struct queue QUEUE;

void enque(QUEUE * q,int n){
	if(check == qSize)
		printf("queue is full\n");
	else{
		q->arr[(++q->rear)%qSize] = n;
		check++;
	}
}

void deque(QUEUE *q){
	if(check == 0)
		printf("queue is empty...\n");
	else{
		printf("deleted element is %d\n",q->arr[(q->front++)%qSize]);
		check--;
	}
}

void display(QUEUE *q){
	int i;
	if(q->front == q->rear+1 && check ==0)
		printf("queue is empty...\n");
	else{
		for(i =0;i<check;i++)
			printf("%d\t",q->arr[(q->front+i)%qSize]);
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
			//printf("deleted number is %d \n",n);
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
