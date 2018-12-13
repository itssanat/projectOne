#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define debug printf("yaha sab thik hai\n");
#define dekho display(head);

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

void swap(MLNODE *head,int r1,int r2){
	MLNODE *p,*q,*r,*s,*t;
	p = above(head,r1,-1);
	p = p->nextRow;
	q = above(head,r2,-1);
	q = q->nextRow;
	p = p->nextCol;
	q = q->nextCol;

	while(p->col != -1 && q->col != -1){
		if(p->col == q->col){
			int tmp = p->info;
			p->info = q->info;
			q->info = tmp;
			p=p->nextCol;
			q=q->nextCol;
			continue;
		}

		if(p->col < q->col){
			addNode(above(head,q->row,p->col),left(head,q->row,p->col),q->row,p->col,p->info);
			r = p;
			s = above(head,p->row,p->col);
			t = left(head,p->row,p->col);
			s->nextRow = p->nextRow;
			t->nextCol = p->nextCol;
			p=p->nextCol;
			free(r);
			continue;
		}
		if(p->col > q->col){
			addNode(above(head,p->row,q->col),left(head,p->row,q->col),p->row,q->col,q->info);
			printf("\n");
			printf("\n");
			r = q;
			s = above(head,q->row,q->col);
			t = left(head,q->row,q->col);
			s->nextRow = q->nextRow;
			t->nextCol = q->nextCol;
			q=q->nextCol;
			free(r);
			continue;
		}
	}
	while(q->col != -1){
		addNode(above(head,p->row,q->col),left(head,p->row,q->col),p->row,q->col,q->info);
		r = q;
		s = above(head,q->row,q->col);
		t = left(head,q->row,q->col);
		s->nextRow = q->nextRow;
		t->nextCol = q->nextCol;
		q=q->nextCol;
		free(r);
	}
	while(p->col != -1){
		addNode(above(head,q->row,p->col),left(head,q->row,p->col),q->row,p->col,p->info);
		r = p;
		s = above(head,p->row,p->col);
		t = left(head,p->row,p->col);
		s->nextRow = p->nextRow;
		t->nextCol = p->nextCol;
		p=p->nextCol;
		free(r);
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
	printf("enter rows to swap\n");
	int rw1,rw2;
	scanf("%d%d",&rw1,&rw2);
	printf("matrix before swap\n");
	display(head);
	printf("matrix after swap..\n\n");
	swap(head,rw1,rw2);
	display(head);
}