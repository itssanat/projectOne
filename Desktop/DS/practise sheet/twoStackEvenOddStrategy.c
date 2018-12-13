#include <stdio.h>
#include <stdlib.h>
#define EVEN 0
#define ODD 1
#define stkSize 100

struct stack
{
	int arr[stkSize];
	int top_even;
	int top_odd;
}  stk ;
typedef struct stack STACK;

void push(STACK *s,int num,int choice){
	if(choice == ODD){
		if(s->top_odd == 99)
			printf("overflow...\n");
		else{
			s->top_odd+=2;
			s->arr[s->top_odd]= num;
		}
	} else {
		if(s->top_even == 98)
			printf("overflow...\n");
		else{
			s->top_even+=2;
			s->arr[s->top_even]=num;
		}
	}
}

int pop(STACK *s,int choice)
{
	int num;
	if(choice == ODD){
		if(s->top_odd == -1)
			printf("underflow...\n");
		else
		{
			num = s->arr[s->top_odd];
			s->top_odd-=2;
			return num;
		}
	} else {
		if(s->top_even == -2)
			printf("underflow...\n");
		else
		{
			num = s->arr[s->top_even];
			s->top_even-=2;
			return num;
		}
	}
	return -1; // no element found ///
}

int main(int argc, char const *argv[])
{
	int x,num,choice;
	stk.top_odd = 1;
	stk.top_even = 0;
	while(1)
	{
		printf("1. to push:\n");
		printf("2. to pop:\n");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("enter information and stack no(0 for even, 1 for odd:)\n");
				scanf("%d%d",&num,&choice);
				push(&stk,num,choice);
				break;
			case 2:
				printf("enter stack no(0 for even, 1 for odd)\n");
				scanf("%d",&choice);
				num = pop(&stk,choice);
				printf("%d is poped..\n",num);
				break;
			default: 
				printf("invalid input...\n");
		}
	}
	return 0;
}