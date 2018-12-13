#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX(X,Y) (((X) >= (Y)) ? (X) : (Y))

struct Node
{
	int info;
	struct Node *left ,* right;
	int height;
};
typedef struct Node node;

node * newNode(int x){
	node *p = (node *)malloc(sizeof(malloc));
	p->info = x;
	p->left = p->right = NULL;
	p->height = 1;
	return p;
}

int Height(node * root){
	if(root == NULL)
		return 0;
	return root->height;
}

int balanceFactor(node * root){
	if(root == NULL)
		return 0;
	return (Height(root->left) - Height(root->right));
}

node * rightRotate(node * root){
	node *p = root->left;
	node *q = p->right;
	p->right = root;
	root->left = q;

	root->height = MAX(Height(root->left),Height(root->right)) + 1;
	p->height = MAX(Height(p->left),Height(p->right))+1;

	return p;
}

node * leftRotate(node * root){
	node *p = root->right;
	node *q = p->left;
	p->left = root;
	root->right = q;

	root->height = MAX(Height(root->left),Height(root->right)) + 1;
	p->height = MAX(Height(p->left),Height(p->right))+1;

	return p;
}

node * insert(node * root,int num){
	if(root == NULL)
		return newNode(num);
	else if(num < root->info)
		root->left = insert(root->left,num);
	else if(num > root->info)
		root->right = insert(root->right , num);
	else
		return root;

	root->height = MAX(Height(root->left),Height(root->right)) +1 ;

	int b = balanceFactor(root);

	if(b>1 && num <root->left->info)
		return rightRotate(root);

	if(b<-1 && num > root->right->info)
		return leftRotate(root);

	if(b>1 && num > root->left->info){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if(b<-1 && num < root->right->info){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

int findmin(node * root)
{
	if(root->left == NULL)
		return root->info;
	else 
		return findmin(root->left);
}

node * delete(node *root, int num){
	node * p;
	if(root == NULL)
		return NULL;
	if(root->info > num){
		root->left = delete(root->left, num);
	}
	else if(root->info < num){
		root->right = delete(root->right, num);
	}
	else
	{
		if(root->left == NULL){
			p = root->right;
			free(root);
			return p;
		}
		else if(root->right == NULL){
			p = root->left;
			free(root);
			return p;
		}
		else{
			int t = findmin(root->right);
			root->info = t;
			root->right = delete(root->right,t);
		}
	}
	if(root == NULL)
		return root;

	root->height = MAX(Height(root->left),Height(root->right)) +1;

	int b = balanceFactor(root);

	if(b>1 && num <root->left->info)
		return rightRotate(root);

	if(b<-1 && num > root->right->info)
		return leftRotate(root);

	if(b>1 && num > root->left->info){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if(b<-1 && num < root->right->info){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void inOrder(node * root){
	if(root != NULL){
		inOrder(root->left);
		printf("%d ",root->info);
		inOrder(root->right);
	}
}

int main()
{
	int x,num;
	node * root = NULL;
	printf("1. to insert\n");
	printf("2. to delete\n");
	printf("3. to display inorder\n");
	printf("4. to exit\n");
	while(true){
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				printf("enter info: ");
				scanf("%d",&num); 
				root = insert(root,num);
				break;
			case 2:
				printf("enter info\n");
				scanf("%d",&num);
				root  = delete(root,num);
				break;
			case 3:
				inOrder(root);
				break;
			case 4:
				exit(0);
			default:
				printf("invalid input...\n");
		}
	}
	return 0;
}