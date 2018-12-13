#include<stdio.h>
#include <stdlib.h>

struct  Node  // using doubly linked list data structure  // 
{
	int info;
	struct Node *pre ,*next;
};
typedef struct Node node;

node * insert (node * root,int x){
	node *p = (node *)malloc(sizeof(node));
	p->info = x;
	p->pre = p->next = p;
	if(root == NULL)
		return p;
	if(p->info <= root->info){
		p->next = root;
		p->pre = root->pre;
		root->pre->next = p;
		root->pre = p;
		return p;
	}
	node * q = root;
	while(q->next != root){
		if(p->info <= q->next->info && p->info >q->info){
			break;
		}
		q = q->next;
	}
	p->pre = q;
	p->next = q->next;
	q->next->pre = p;
	q->next = p;
	return root;
}

node *deletemin(node * root){
	node * p = root;
	if(root->next == root){
		free(root);
		return NULL;
	}
	root = root->next;
	root->pre = p->pre;
	p->pre->next = root;
	free(p);
	return root;
}

node *deletemax(node * root){
	node * p = root->pre;
	if(root->next == root){
		free(root);
		return NULL;
	}
	root->pre = p->pre;
	p->pre->next = root;
	free(p);
	return root;
}

void display(node * root){
	if(root == NULL )
		return;
	node * p = root;
	printf("%d  ",p->info);
	p = p->next;
	while(p != root){
		printf("%d  ",p->info);
		p = p->next;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	node * root = NULL;
	printf("enter the number of node\n");
	scanf("%d",&n);
	printf("enter info of nodes\n");
	int i,info;
	for(i = 0;i<n;i++){
		scanf("%d",&info);
		root = insert(root,info);
	}
	printf("elements before deleting min and max\n");
	display(root);
	root = deletemin(root);
	root = deletemax(root);
	printf("\nelements after deleteing min and max\n");
	display(root);
	return 0;
}