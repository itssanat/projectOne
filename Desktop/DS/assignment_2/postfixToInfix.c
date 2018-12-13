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

void  postfixToInfix(char *str,int n){
	int i,c=0,j1,j2;
	char opr,s1[50],s2[50];
	for(i=0;i<n;i++){
		if((*(str+i)>=65 && *(str+i)<=90) || (*(str+i)>=97&& *(str+i)<=122) )
			push(*(str+i));
		else{
			opr = *(str+i);
			j1=-1,j2=-1,c=0;
			s1[++j1] = pop();
			if(s1[j1] == ')')
				c=1;
			while(c!=0){
				s1[++j1]=pop();
				if(s1[j1]=='(')
					c--;
				if(s1[j1]==')')
					c++;
			}
			c=0;
			s2[++j2] = pop();
			if(s2[j2] == ')')
				c=1;
			while(c!=0){
				s2[++j2]=pop();
				if(s2[j2]=='(')
					c--;
				if(s2[j2]==')')
					c++;
			}
			push('(');
			for(c=j2;c>=0;c--)
				push(s2[c]);
			push(opr);
			for(c=j1;c>=0;c--)
				push(s1[c]);
			push(')');
		}
	}
}

void main(){
	char str[100];
	printf("enter your expression: ");
	scanf("%s",str);
	int c = strlen(str),i;
	printf("infix form of expression:  ");
	postfixToInfix(&str[0],c);
	for(i=0;i<=top;i++)
		printf("%c",stack[i]);
}