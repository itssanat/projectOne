#include<stdio.h>
#include <stdlib.h>
#include <math.h>
int post[100],in[100];
int curr ;
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
	p->info = post[curr];
	int i;
	for(i=l;i<=r;i++){
		if(in[i] == post[curr])
			break;
	}
	curr--;
	//printf("%d %d %d %d\n",l,i,r,curr);
	p->rchild = makeTree(i+1,r);
	p->lchild = makeTree(l,i-1);
	return p;
}

int main(int argc, char const *argv[])
{
	int n,i;
	printf("enter number of node in tree\n");
	scanf("%d",&n);
	printf("enter postorder value:\n");
	for(i =0;i<n;i++)
		scanf("%d",&post[i]);
	printf("enter inorder value\n");
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	curr = n-1;
	BTNODE * root = makeTree(0,n-1);
	printf("inorder of created tree\n");
	inorder(root);

	return 0;
}