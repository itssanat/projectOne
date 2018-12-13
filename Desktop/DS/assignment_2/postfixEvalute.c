#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#define stkSize 100
int num[stkSize],top=-1;

void pushNum(int n){
	if(top==stkSize-1)
		printf("stack overflow\n");
	else
		num[++top] = n;
}

int popNum(){
	if(top == -1){
		printf("stack underflow...\n");
		exit(0);
	}
	else
		return num[top--];
}

void  postfixEvaluate(char *str,int n){
	int i,a,b;
	for(i=0;i<n;i++){
		if(*(str+i)>=48 && *(str+i)<=57)
			pushNum(*(str+i)-48);
		else{
			b = popNum();
			a = popNum();
			switch(*(str+i)){
				case '+':
				pushNum(a+b);
				break;
				case '*':
				pushNum(a*b);
				break;
				case '-':
				pushNum(a-b);
				break;
				case '/':
				pushNum(a/b);
				break;
				case '^':
				pushNum(pow(a,b));
				break;
				default :
				printf("operator is undefined...\n");
			}
		}
	}
}

void main(){
	char str[100];
	printf("enter your expression: ");
	scanf("%s",str);
	int c = strlen(str),i;
	postfixEvaluate(&str[0],c);
	printf("\nvalue of expression = %d\n",num[top] );

}