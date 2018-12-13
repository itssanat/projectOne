#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct  Node  
{
	char info;
	int freq;
	struct Node *next;
};
typedef struct Node node;


node * add(node * root,char c){
	node *p = (node *)malloc(sizeof(node)), *q = root;
	if(root == NULL){
		p->info = c;
		p->freq = 1;
		p->next = NULL;
		return p;
	}
	while(q->next != NULL){
		if(q->info == c){
			q->freq++;
			return root;
		}
		q = q->next;
	}
	if(q->info == c){
		q->freq++;
		return root;
	}
	p->info = c;
	p->freq = 1;
	p->next = NULL ;
	q->next = p;
	return root;
}

node * delete(node * root , char ch){
	if(root == NULL)
		return NULL;
	node * p = root;
	if(root->info == ch){
		if(root->freq == 1){
			root = root->next;
			free(p);
			return root;
		}
		p->freq--;
		return root;
	}
	while(p->next != NULL){
		if(p->next->info == ch){
			if(p->next->freq == 1){
				node * q = p->next;
				p->next = q->next;
				free(q);
				break;
			}
			p->next->freq--;
			break;
		}
		p = p->next ;
	}
	return root;
}

void display(node * root){
	node * p = root;
	while(p != NULL){
		int i = 0;
		for(i  = 0;i<p->freq;i++)
			printf("%c  ",p->info);
		p = p->next;
	}
}

int main()
{
	int x;
	node * root = NULL;
	char ch;
	printf("1. to add node\n");
	printf("2. to remove a node\n");
	printf("3. to display\n");
	printf("4. to exit\n");
	while(true){
		printf("enter choice: ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				printf("enter info: ");
				scanf(" %c",&ch); 
				root = add(root,ch);
				break;
			case 2:
				printf("enter info\n");
				scanf(" %c",&ch);
				root  = delete(root,ch);
				break;
			case 3:
				display(root);
				break;
			case 4:
				exit(0);
			default:
				printf("invalid input...\n");
		}
	}
	return 0;
}