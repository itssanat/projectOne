#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct queue
{
	int front[MAX];
	int rear[MAX];
	int *array;
}Queue;

void enqueue(Queue *q,int item,int n)
{
	if(q->rear[n]==5 && q->rear[n+1]!=0)
	{
		printf("Queue Overflow\n");
		return;
	}
	q->rear[n]++;
	q->array[5*n + q->rear[n]]=item;
}

int dequeue(Queue *q,int n)
{
	int item=q->array[5*n+q->front[n]];
	q->front[n]++;
	return item;
}

void display(Queue *q,int n)
{
	int i;
	for(i=q->front[n];i<=q->rear[n];i++)
		printf("%d\t",q->array[5*n+i]);
	printf("\n");
}

int main(){
	int pos,choice,res,num,i;
	Queue *q;
	q=(Queue *)malloc(sizeof(Queue));
	q->array=(int *)malloc(sizeof(int) * 100);
	for(i=0;i<MAX;i++){
		q->front[i]=0;
		q->rear[i]=-1;
	}
	while(1){
		printf("Enter the nth queue where operation to be implemented:- ");
		scanf("%d",&pos);
		printf("\n1.Enqueue into the queue\n2.Dequeue the queue\n3.Display the queue\n4.Exit\n");
		printf("Enter your choice:- ");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			printf("Enter a number to enqueue ");
			scanf("%d",&num);
			enqueue(q,num,pos);
			break;
		case 2:
			
			res=dequeue(q,pos);
			printf("Element dequeued is %d\n",res);
			break;
		case 3:
			display(q,pos);
			break;
		case 4:
			exit(0);
		default:
			printf("Wrong choice\n");	
		}
	}
	return 0;
}