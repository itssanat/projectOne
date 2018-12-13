#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define stkSize 100
char stack[stkSize];
int top = -1;

void push(char c){
	if(top == stkSize-1){
		printf("stack overflow:\n");
		exit(0);
	}
	else
		stack[++top]=c;
}

char pop(){
	if(top==-1){
		printf("stack underflow:\n");
		exit(0);
	}
	else
		return stack[top--];
}

int pref(char c){
	if(c=='+'||c=='-')
		return 1;
	if(c=='*'||c=='/')
		return 2;
	if(c=='^')
		return 3;
}

int  infixToPostfix(char *s,int n){
	int i,count = 0;
	char ch[100],c=0;
	char *str = &ch[0];
	for(i=0;i<n;i++){
		*(str+i) = *(s+i);
		if(*(s+i)==')' || *(s+i)=='(')
			count++;
	}
	for(i=0;i<n;i++){
		if((65<=*(str+i) && *(str+i)<=90 ) || (*(str+i)>=97 && *(str+i)<=122) )
			*(s+c++)=*(str+i);
		else {
			if(*(str+i)==')'){
				while(stack[top]!='(')
					*(s+c++) = pop();
				top--;
			} 
			else if(pref(*(str+i))>pref(stack[top]) || *(str+i)=='(' || top ==-1 ||stack[top]=='(' )
				push(*(str+i));
			else if(pref(*(str+i))==pref(stack[top])){
				if(*(str+i)=='^')
					push(*(str+i));
				else{
					while(pref(stack[top])==pref(*(str+i)) && top!=-1)
						*(s+c++) = pop();
					push(*(str+i));
				}
			}
			else {
				while(pref(stack[top])>=pref(*(str+i)) && top!=-1 && stack[top]!='(')
					*(s+c++) = pop();
				push(*(str+i));
			}
		}
	}
	while(top!=-1)
		*(s+c++) = pop();
	return count;
}

void reverse(char *str,int n){
	char c[100];
	int i;
	for(i=0;i<n;i++)
		c[i] = *(str+i);
	for(i =0;i<n;i++)
		if(c[n-1-i]=='(')
			*(str+i) = ')';
		else if(c[n-1-i]==')')
			*(str+i) = '(';
		else
			*(str+i) = c[n-1-i];
}

void main(){
	char str[100];
	printf("enter your expression: ");
	scanf("%s",str);
	int c = strlen(str),i;
	printf("prefix form of expression:  ");
	reverse(&str[0],c);
	c-=infixToPostfix(&str[0],c);
	reverse(&str[0],c);
	for(i=0;i<c;i++)
		printf("%c",str[i]);
}