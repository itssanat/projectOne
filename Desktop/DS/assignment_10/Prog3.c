#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
	int info;
	char symbol;
	struct node * left,*right;
};
typedef struct node NODE;
NODE *arr[100];
int top = -1;

void sort(NODE * arr[]){
	int n = top+1,i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(arr[j]->info < arr[j+1]->info){
				NODE * tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

NODE *createNode(int x,char ch){
	NODE * p = (NODE *)malloc(sizeof(NODE));
	p->info = x;
	p->symbol = ch;
	p->left = NULL;
	p->right = NULL;
	return p;
}

int path[100] ,t = -1;
void display(NODE *root){
	if(root==NULL){
		t--;
		return;
	}
	if(root->left == NULL && root->right == NULL){
		printf("%c: ",root->symbol);
		int i;
		for(i=0;i<=t;i++)
			printf("%d",path[i]);
		printf("\n");
		t--;
		return ;
	}
	path[++t] = 0;
	display(root->left);
	path[++t] = 1;
	display(root->right);
	t--;
}

int main(int argc, char const *argv[])
{
	int n;
	printf("number of element: ");
	scanf("%d",&n);
	int f[n],i;
	char s[n];
	printf("enter symbol\n");
	//for(i=0;i<1;i++) {
		scanf("%s",s);
	//}
	printf("enter frequency:\n");
	for(i=0;i<n;i++) {
		scanf("%d",&f[i]);
	}
	for(i=0;i<n;i++){
		arr[++top] = createNode(f[i],s[i]);
	}
	while(top != 0){
		sort(arr);
		NODE * p = createNode(arr[top]->info+arr[top-1]->info,'#');
		if(arr[top]->info != arr[top-1]->info){
			p->left = arr[top];
			top--;
			p->right = arr[top];
			arr[top] = p;
		}
		else{
			p->right = arr[top];
			top--;
			p->left = arr[top];
			arr[top] = p;
		}
	}
	display(arr[top]);
	return 0;
}