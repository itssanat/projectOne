#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct List
{
	int desti;
	struct List * next;
};
typedef struct List list;

struct Vertics
{
	int info;
	struct Vertics * nextVer;
	struct List * next;
};
typedef struct Vertics vertics;

vertics * createVertics(vertics * root, int x){
	vertics * p = (vertics *)malloc(sizeof(vertics));
	p->info = x;
	p->nextVer = NULL;
	p->next = NULL;
	if(root == NULL)
		return p;
	vertics * q = root;
	while(q->nextVer != NULL)
		q = q->nextVer;
	q->nextVer = p;
	return root;
}

int degree(vertics * root,int x){
	vertics * p = root;
	list * q = NULL;
	int count = 0;
	while(p!=NULL){
		if(p->info == x){
			q= p->next;
			break;
		}
		p = p->nextVer;
	}
	if(q == NULL)
		return 0;
	while(q!=NULL){
		count++;
		q = q->next;
	}
	return count;
}

void addEdge(vertics * root, int s,int e){
	vertics * p = root;
	list * q = NULL;
	if(p == NULL)
		return ;
	while(p!=NULL){
		if(p->info == s){
			q = p->next;
			break;
		}
		p = p->nextVer;
	}
	list * r = (list * )malloc(sizeof(list));
	r->desti = e;
	r->next = NULL;
	if(q == NULL){
		p->next = r;
		return;
	}
	while(q->next != NULL)
		q = q->next;
	q->next = r;
}

void removeEdge(vertics * root,int s,int e){
	vertics * p = root;
	list * q = NULL;
	if(p == NULL)
		return ;
	while(p!=NULL){
		if(p->info == s){
			q = p->next;
			break;
		}
		p = p->nextVer;
	}
	if(q == NULL)
		return;
	list * r;
	if(q->desti == e){
		r = q;
		p->next = q->next;
		free(r);
		return ;
	}
	while(q->next != NULL){
		if(q->desti == e){
			break;
		}
		r = q;
		q = q->next;
	}
	if(q->desti == e){
		r->next = q->next;
		free(q);
	}
}

void freeNode(vertics * root){
	list * q = root->next ,* r;
	free(root);
	while(q != NULL){
		r = q;
		q = q->next;
		free(r);
	}
}

vertics * removeVertics(vertics * root,int x){
	vertics * p = root, * r= root;
	list * q = NULL;
	if(p == NULL)
		return p;
	if(p->info == x){
		r = p;
		p = p->nextVer;
		root = p;
		freeNode(r);
		while(p != NULL){
			removeEdge(root,p->info,x);
		}
		return root;
	}
	while(p!=NULL){
		if(p->info == x){
			break;
		}
		r = p;
		p= p->nextVer;
	}
	if(p == NULL)
		return root;
	r->nextVer = p->nextVer;
	freeNode(p);
	p = root;
	while(p!=NULL){
		removeEdge(root,p->info,x);
		p = p->nextVer;
	}
	return root;
}

void display(vertics * root){
	vertics * p =root;
	list * q;
	while(p!= NULL){
		printf("%d: ", p->info);
		q = p->next;
		while(q != NULL){
			printf("-->%d",q->desti);
			q = q->next;
		}
		printf("\n");
		p = p->nextVer;
	}
}

int main(int argc, char const *argv[])
{
	int x,info,y;
	vertics * root = NULL;
	printf("1. to create edge between two vertics\n");
	printf("2. to remove an edge\n");
	printf("3. degree of perticular vertics\n");
	printf("4. create a vertics\n");
	printf("5. remove an exiting vertics\n");
	printf("6. to display list\n");
	printf("7. to exit\n");
	while(true){
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("enter edge's start and end vertics\n");
				scanf("%d%d",&x,&y);
				addEdge(root,x,y);
				break;
			case 2:
				printf("enter edge's start and end vertics\n"); 
				scanf("%d%d",&x,&y);
				removeEdge(root,x,y);
				break;
			case 3:
				printf("enter vertics info\n");
				scanf("%d",&info);
				int d = degree(root,info);
				printf("degree of vertics = %d\n",d);
				break;
			case 4:
				printf("enter vertics info\n");
				scanf("%d",&info);
				root = createVertics(root,info);
				break;
			case 5:
				printf("enter vertics info\n");
				scanf("%d",&info);
				root = removeVertics(root,info);
				break;
			case 6:
				display(root);
				break;
			case 7:
				exit(0);
			default:
			printf("invalid input..\n");
		}
	}
	return 0;
}