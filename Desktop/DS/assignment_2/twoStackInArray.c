#include<stdio.h>
#include<stdlib.h>
#define stkSize 10
int stack[stkSize];
int top1=-1,top2= stkSize;

void pushStack1(int num){
	if(top2 == top1+1){
		printf("stack overflow\n");
		return;
	}
	stack[++top1] = num;
}

void pushStack2(int num){
	if(top2 == top1+1){
		printf("stack overflow\n");
		return;
	}
	stack[--top2] = num;
}

int popStack1(){
	if(top1 == -1){
		printf("stack 1 is in underflow.\n");
		return -1;
	} 
	return stack[top1--];
}

int popStack2(){
	if(top2 == stkSize){
		printf("stack 2 is in underflow.\n");
		return -1;
	} 
	return stack[top2++];
}

void displayStack1(){
	int i;
	if(top1 == -1){
		printf("no element in the stack 1.\n");
	} else {
		printf("element of stack 1: ");
		for(i=0;i<=top1;i++)
			printf("%d\t",stack[i] );
		printf("\n");
	}
}

void displayStack2(){
	int i;
	if(top2 == stkSize)
		printf("no element in stack 2.\n");
	else {
		printf("element of stack 2: ");
		for(i=stkSize-1;i>=top2;i--)
			printf("%d\t",stack[i] );
		printf("\n");
	}
}

void main(){
	int x,num,a;
	while(1){
		printf("1: to push in stack 1.\n");
		printf("2: to push in stack 2.\n");
		printf("3: to pop in stack 1.\n");
		printf("4: to pop in stack 2.\n");
		printf("5: to display stack 1.\n");
		printf("6: to display stack 2.\n");
		printf("7: to exit.\n");
		scanf("%d",&x);
		switch(x){
			case 1:
			printf("enter the element to push: ");
			scanf("%d",&num);
			pushStack1(num);
			break;
			case 2:
			printf("enter the element to push: ");
			scanf("%d",&num);
			pushStack2(num);
			break;
			case 3:
			a=popStack1();
			printf("deleted element is %d .\n",a );
			break;
			case 4:
			a =popStack2();
			printf("deleted element is %d.\n",a );
			break;
			case 5:
			displayStack1();
			break;
			case 6:
			displayStack2();
			break;
			case 7:
			exit(0);
			default :
			printf("input is not valid. enter again...\n\n");
		}
	}
}