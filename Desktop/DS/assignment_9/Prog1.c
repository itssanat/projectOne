#include<stdio.h>
#include <stdlib.h>
#include <math.h>

struct btnode 
{
	int info;
	struct btnode * lchild,* rchild;
};
typedef struct btnode BTNODE;

BTNODE * insert(BTNODE * root, int i)
{
	BTNODE * p = (BTNODE *)malloc(sizeof(BTNODE)) ;
	p->info = i;
	p->lchild = p->rchild = NULL;
	if(root == NULL)
		return p;
	if(i < root->info)
		root->lchild = insert(root->lchild,i);
	else
		root->rchild = insert(root->rchild,i);
	return root;
}

int findmin(BTNODE * root)
{
	if(root->lchild == NULL)
		return root->info;
	else 
		return findmin(root->lchild);
}

BTNODE * delete(BTNODE * root , int i)
{
	BTNODE * p;
	if(root == NULL)
		return NULL;
	if(root->info > i){
		root->lchild = delete(root->lchild, i);
	}
	else if(root->info < i){
		root->rchild = delete(root->rchild, i);
	}
	else
	{
		if(root->lchild == NULL){
			p = root->rchild;
			free(root);
			return p;
		}
		else if(root->rchild == NULL){
			p = root->lchild;
			free(root);
			return p;
		}
		else{
			int t = findmin(root->rchild);
			root->info = t;
			root->rchild = delete(root->rchild,t);
		}
	}
	return root;
}

void preorder(BTNODE * root)
{
	if(root != NULL){
		printf("%d ",root->info);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

void postorder(BTNODE * root)
{
	if(root != NULL){
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d ",root->info);
	}
}

void inorder(BTNODE * root)
{
	if(root != NULL){
		inorder(root->lchild);
		printf("%d ",root->info);
		inorder(root->rchild);
	}
}

int main()
{
	int x,n,info;
	BTNODE * root = NULL;
	while(1)
	{	
		printf("1. to insert node\n");
		printf("2. to delete\n");
		printf("3. to display preorder\n");
		printf("4. to display inorder\n");
		printf("5. to display postorder\n");
		printf("6. to exit\n");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("enter info\n");
				scanf("%d",&info);
				root = insert(root,info);
				break;
			case 2:
				printf("enter info\n");
				scanf("%d",&info);
				root = delete(root,info);
				break;
			case 3:
				preorder(root);
				break;
			case 4:
				inorder(root);
				break;
			case 5:
				postorder(root);
				break;
			case 6:
				exit(1);
				break;
			default: 
				printf("invalid input...");
		}
	}
	return 0;
}