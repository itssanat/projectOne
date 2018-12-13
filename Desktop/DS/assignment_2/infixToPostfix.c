#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define stkSize 100
char stack[stkSize];
int top = -1;

void push(char c){
	if(top == stkSize-1)
		printf("stack overflow:\n");
	else
		stack[++top]=c;
}

void pop(){
	if(top==-1)
		printf("stack underflow:\n");
	else
		printf("%c",stack[top--]);
}

int pref(char c){
	if(c=='+'||c=='-')
		return 1;
	if(c=='*'||c=='/')
		return 2;
	if(c=='^')
		return 3;
}

void infixToPostfix(char *str,int n){
	int i;
	for(i=0;i<n;i++){
		if((65<=*(str+i) && *(str+i)<=90 ) || (*(str+i)>=97 && *(str+i)<=122) )
			printf("%c",*(str+i));
		else {
			if(*(str+i)==')'){
				while(stack[top]!='(')
					pop();
				top--;
			} 
			else if(pref(*(str+i))>pref(stack[top])||*(str+i)=='('||top ==-1||stack[top]=='(')
				push(*(str+i));
			else if(pref(*(str+i))==pref(stack[top])){
				if(*(str+i)=='^')
					push(*(str+i));
				else{
					while(pref(stack[top])==pref(*(str+i)) && top!=-1)
						pop();
					push(*(str+i));
				}
			}
			else {
				while(pref(stack[top])>=pref(*(str+i)) && top!=-1 && stack[top]!='(')
					pop();
				push(*(str+i));
			}
		}
	}
	while(top!=-1)
		pop();
}

void main(){
	char str[100];
	printf("enter your expression: ");
	scanf("%s",str);
	int c = strlen(str);
	printf("postfix form of expression:  ");
	infixToPostfix(&str[0],c);
}