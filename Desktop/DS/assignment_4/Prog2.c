#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

struct stack{
	int arr[SIZE];
	int top;
};
typedef struct stack STACK;

void push(STACK *s, int num){
	if(s->top == SIZE-1){
		printf("queue is full");
	} else {
		s->arr[++s->top] = num;
	}
}

int pop(STACK *s){
	if(s->top == -1){
		printf("queue is empty");
		return -1;
	} 
	return s->arr[s->top--];
}

void dequeue(STACK *s,STACK * t){
	int num;
	if(s->top== -1){
		printf("queue is empty\n");
		return ;
	}
	t->top = -1;
	while(s->top != 0){
		push(t,pop(s));
	}
	num = s->arr[0];
	s->top = -1;
	
	while(t->top!= -1){
		push(s,pop(t));
	}
	printf("poped number is %d\n",num);
}

void display(STACK *s){
	int i;
	for(i = 0;i<=s->top;i++)
		printf("%d\t",s->arr[i]);
	printf("\n\n");
}
	

int main(){
	STACK stk,tmp;
	stk.top = -1;
	tmp.top = -1;
	int x,num;
	while(1){
		printf("enter 1 to enqueue\n");
		printf("enter 2 to dequeue\n");
		printf("enter 3 to disply:\n");
		printf("enter 4 to exit:\n");
		scanf("%d",&x);
		
		switch(x){
			case 1:
				printf("enter your number: ");
				scanf("%d",&num);
				push(&stk,num);
				break;
			case 2:
				dequeue(&stk,&tmp);
				break;
			case 3:
				display(&stk);
				break;
			case 4:
				exit(1);
			default:
				printf("invalid input...\n");
		}
	}
	return 0;
}