#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

struct mlnode
{
	int row,col,info;
	struct mlnode * nextRow,*nextCol;
};
typedef struct mlnode MLNODE;

MLNODE * createHeader(int m,int n){
	MLNODE * p = (MLNODE *)malloc(sizeof(MLNODE));
	p->row = p->col = p->info = -1;
	p->nextCol = p->nextRow = NULL;
	MLNODE *q = p;
	int i;
	for(i=0;i<m;i++){
		q->nextRow = (MLNODE *)malloc(sizeof(MLNODE));
		q = q->nextRow;
		q->row = i+1;
		q->col = q->info = -1;
		q->nextCol = q;
	}
	q->nextRow = p;
	q = p;
	for(i=0;i<n;i++){
		q->nextCol = (MLNODE *)malloc(sizeof(MLNODE));
		q = q->nextCol;
		q->col = i+1;
		q->row = q->info = -1;
		q->nextRow = q;
	}
	q->nextCol = p;
	return p;
}

MLNODE * above(MLNODE * head,int r,int c){
	MLNODE * p = head,*q = head;
	while(p->col != c)
		p = p->nextCol;
	do
	{
		q = p;
		p = p->nextRow;
	} while (p->row < r && p->row != -1);
	return q;
}

MLNODE * left(MLNODE * head,int r,int c){
	MLNODE * p = head,*q = head;
	while(p->row != r)
		p = p->nextRow;
	do
	{
		q = p;
		p = p->nextCol;
	} while (p->col < c && p->col != -1);
	return q;
}

void addNode(MLNODE *a,MLNODE *l,int r,int c,int i){
	MLNODE * q = (MLNODE *)malloc(sizeof(MLNODE));
	q->row = r;
	q->col = c;
	q->info = i;
	q->nextRow = a->nextRow;
	q->nextCol = l->nextCol;
	a->nextRow = q;
	l->nextCol = q;
}

void display(MLNODE * head){
	MLNODE *p = head,*q;
	p = p->nextRow;
	while(p->row != -1){
		p=p->nextCol;
		while(p->col != -1){
			printf("%d,%d,%d\t",p->row,p->col,p->info);
			p=p->nextCol;
		}
		printf("\n");
		p = p->nextRow;
	}
}

void delete(MLNODE * head,int rw){
	MLNODE * p,*q,*r;
	p = above(head,rw,-1);
	q = p->nextRow;
	p->nextRow = q->nextRow;
	q=q->nextCol;
	while(q->col != -1){
		r = above(head,rw,q->col);
		r->nextRow = q->nextRow;
		q = q->nextCol;
	}
	q=q->nextCol;
	while(q->col != -1){
		r = q;
		q= q->nextCol;
		free(r);
	}
	free(q);

	p = above(head,rw+1,-1);
	p=p->nextRow;
	p->row--;
	q=p->nextCol;
	while(p->row != -1){
		while(q->col != -1){
			q->row--;
			q=q->nextCol;
		}
		p=p->nextRow;
		if(p->row == -1)
			break;
		p->row--;
		q = p->nextCol;
	}
}

int main()
{
	int r,c,i,check = 1,x;
	printf("enter number of row and col.\n");
	scanf("%d%d",&r,&c);
	MLNODE * head = createHeader(r,c);
	while(x){
		printf("1 add node\n");
		printf("2 to display\n");
		printf("3. to finish\n");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("enter row,col,and info\n");
				scanf("%d%d%d",&r,&c,&i);
				addNode(above(head,r,c),left(head,r,c),r,c,i);
				break;
			case 2 :
				display(head);
				break;
			case 3:
				x = 0;
				break;
			default:
				printf("invalid input\n");
		}
	}
	printf("enter row to delete\n");
	int rw;
	scanf("%d",&rw);
	printf("matrix before deletion\n");
	display(head);
	printf("matrix after deletion..\n\n");
	delete(head,rw);
	display(head);
}