#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include<stdbool.h>
#define MAX(X, Y) (((X) <= (Y)) ? (Y) : (X))

int pre[100],in[100];
int curr = 0;
struct btnode 
{
	int info;
	struct btnode * lchild,* rchild;
};
typedef struct btnode BTNODE;

void inorder(BTNODE * root)
{
	if(root != NULL){
		inorder(root->lchild);
		printf("%d ",root->info);
		inorder(root->rchild);
	}
}

BTNODE * makeTree(int l,int r){
	if(l>r )
		return NULL;
	BTNODE *p = (BTNODE *)malloc(sizeof(BTNODE));
	p->info = pre[curr];
	int i;
	for(i=l;i<=r;i++){
		if(in[i] == pre[curr])
			break;
	}
	curr++;
	p->lchild = makeTree(l,i-1);
	p->rchild = makeTree(i+1,r);
	return p;
}

int numberOfNode(BTNODE * root){
	if(root == NULL)
		return 0;
	return 1 + numberOfNode(root->lchild) + numberOfNode(root->rchild);
}

int numberOfLeaf(BTNODE * root){
	if(root == NULL)
		return 0;
	if(root->lchild == NULL && root->rchild == NULL)
		return 1;
	return numberOfLeaf(root->lchild)+numberOfLeaf(root->rchild);
}

int numberOfNonLeaf(BTNODE * root){
	if(root ==NULL || (root->lchild == NULL && root->rchild == NULL))
		return 0;
	return 1+numberOfNonLeaf(root->lchild) + numberOfNonLeaf(root->rchild);
}

int height(BTNODE * root){
	if(root  == NULL)
		return 0;
	return 1 + MAX(height(root->lchild),height(root->rchild));
}

bool strict(BTNODE * root){
	if(root == NULL)
		return true;
	if((root->lchild == NULL && root->rchild != NULL) || (root->lchild != NULL && root->rchild == NULL))
		return false;
	return (strict(root->lchild)&&strict(root->rchild));
}

bool checkEqualtiy(BTNODE * root,BTNODE *root1){
	if(root == NULL && root1 == NULL)
		return true;
	if((root1->info != root->info)||(root==NULL&&root1!=NULL)||(root!=NULL&&root1==NULL))
		return false;
	return checkEqualtiy(root->lchild,root1->lchild)&&checkEqualtiy(root1->rchild,root->rchild);
}

void equalTree(BTNODE * root){
	int n,i;
	printf("enter number of node in second tree\n");
	scanf("%d",&n);
	printf("enter preorder value:\n");
	for(i =0;i<n;i++)
		scanf("%d",&pre[i]);
	printf("enter inorder value\n");
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	curr = 0;
	BTNODE * root1 = makeTree(0,n-1);
	if(checkEqualtiy(root,root1))
		printf("trees are equal\n");
	else
		printf("trees are not equal\n");
}

int main(int argc, char const *argv[])
{
	int n,i,x;
	printf("first we creat a tree using preorder and inorder----\n");
	printf("enter number of node in tree\n");
	scanf("%d",&n);
	printf("enter preorder value:\n");
	for(i =0;i<n;i++)
		scanf("%d",&pre[i]);
	printf("enter inorder value\n");
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	BTNODE * root = makeTree(0,n-1);

	printf("1. to count number of node\n");
	printf("2. to count number of leaf node\n");
	printf("3. to count number of non leaf node\n");
	printf("4. to find height of binary tree\n");
	printf("5. to check whether it's a strict binary tree or not\n");
	printf("6. to check whether two tree are equal or not\n");
	printf("7. to exit\n");

	while(true){
		scanf("%d",&x);
		switch(x){
			case 1:
			printf("number of node = %d\n",numberOfNode(root));
			break;
			case 2:
			printf("number of leaf node = %d\n",numberOfLeaf(root));
			break;
			case 3:
			printf("number of non leaf node = %d\n",numberOfNonLeaf(root));
			break;
			case 4:
			printf("height of tree = %d\n",height(root));
			break;
			case 5:
			if(strict(root))
				printf("tree is strict binary tree\n");
			else
				printf("tree is not a strict binary tree\n");
			break;
			case 6:
			equalTree(root);
			break;
			case 7:
			exit(1);
			default:
				printf("invalid input\n");
		}
	}

	return 0;
}