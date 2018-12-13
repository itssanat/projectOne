#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
	bool isOpr;
	char ch;
	struct node * left , * right ;
};
typedef struct node NODE;

bool isOperator(char ch){
	if(ch == '*'||ch == '+'||ch == '-'||ch == '/'||ch == '^') return true;
	return false;
}

NODE * createNode(char c){
	NODE * p = (NODE *)malloc(sizeof(NODE));
	p->ch = c;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void postorder(NODE * root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%c",root->ch);
	}
}

void preorder(NODE * root){
	if(root != NULL){
		printf("%c",root->ch);
		preorder(root->left);
		preorder(root->right);
		
	}
}

int main(int argc, char const *argv[])
{
	printf("enter postfix expression: ");
	char str[100];
	scanf("%s",str);
	NODE * root = NULL;
	NODE * stack[100];
	int top = -1,l,i;
	l = strlen(str);
	for(i=0;i<l;i++){
		if(isOperator(str[i])){
			NODE *p1,*p2,*p3;
			p2 = stack[top];
			top--;
			p1 = stack[top];
			top--;
			p3 = createNode(str[i]);
			p3->isOpr = true;
			p3->left = p1;
			p3->right = p2;
			stack[++top] = p3;
		}
		else{
			NODE * p = createNode(str[i]);
			p->isOpr = false;
			stack[++top] = p;
		}
	}
	root = stack[top];
	printf("postorder: ");
	postorder(root);
	printf("\npreorder: ");
	preorder(root);
	return 0;
}