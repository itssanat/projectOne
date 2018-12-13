#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct stack
{
	int top[MAX];
	int *array;
}Stack;

void push(Stack *p,int item,int n)
{
	if(p->top[n]==5 && p->top[n+1]!=0)
	{
		printf("Global Stack Overflow\n");
		return;
	}
	p->top[n]++;
	p->array[5*n + p->top[n]]=item;
	
}

int pop(Stack *p,int n)
{
	int item=p->array[5*n+p->top[n]];
	p->top[n]--;
	return item;
}

void display(Stack *p,int n)
{
	int i;
	for(i=5*n;i<=5*n+p->top[n];i++)
		printf("%4d",p->array[i]);
	printf("\n");
}

int main(){
	int pos,choice,res,num;
	Stack *p;
	p=(Stack *)malloc(sizeof(Stack));
	p->array=(int *)malloc(sizeof(int) * 100);
	int i;
	for(i=0;i<MAX;i++){
		p->top[i]=-1;
	}
	while(1){
		printf("Enter the nth stack where operation to be implemented:- ");
		scanf("%d",&pos);
		printf("\n1.Push into the stack\n2.Pop the stack\n3.Display the stack\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			printf("Enter a number to push ");
			scanf("%d",&num);
			push(p,num,pos);
			break;
		case 2:
			
			res=pop(p,pos);
			printf("Element poped is %d\n",res);
			break;
		case 3:
			display(p,pos);
			break;
		case 4:
			exit(0);
		default:
			printf("Wrong choice\n");	
	}
}
return 0;
}
