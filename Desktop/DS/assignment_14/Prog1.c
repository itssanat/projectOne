#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct  Vertics
{
	int info;   // can contain info of node or weight of edge ///
	bool isVertics;
	struct Vertics * point,* next;
};
typedef struct Vertics vertics;

vertics * createVertics(vertics * root,int x){
	vertics * p = (vertics *)malloc(sizeof(vertics)),*q = root;
	p->info = x;
	p->isVertics = true;
	p->point = p->next = NULL;
	if(root == NULL)
		return p;
	while(q->next != NULL)
		q = q->next;
	q->next = p;
	return root;
}

void addEdge(vertics * root, int s,int e,int w){
	vertics * p = root,*q,*t = root;;
	while(p != NULL){
		if(p->info == s){
			q = p->point;
			break;
		}
		p = p->next;
	}
	vertics * r = (vertics *)malloc(sizeof(vertics));
	r->info = w;
	r->isVertics = false;
	r->point = NULL;
	while(t->info != e)
		t = t->next;
	r->next = t;
	if(q == NULL){
		p->point = r;
		return ;
	}
	while(q->point != NULL)
		q = q->point ;
	q->point = r;
}

void removeEdge(vertics * root,int s,int e){
	vertics * p = root,*q,*r;
	if(p == NULL)
		return;
	while(p!= NULL){
		if(p->info == s){
			q = p->point;
			break;
		}
		p = p->next;
	}
	if(q == NULL)
		return ;
	if(q->next->info == e){
		p->point = q->point;
		free(q);
		return ;
	}
	while(q->point!=NULL){
		if(q->next->info == e){
			break;
		}
		r = q;
		q= q->point;
	}
	if(q->next->info == e){
		r->point = q->point;
		free(q);
	}
}

int degree(vertics * root,int x){
	vertics * p = root,*q = root;
	while(p!=NULL){
		if(p->info == x){
			q = p->point;
			break;
		}
		p = p->next;
	}
	int count = 0;
	while(q != NULL){
		count++;
		q = q->point;
	}
	return count;
}

void display(vertics * root){
	vertics * p = root ,* q;
	while(p!= NULL){
		printf("%d: ",p->info );
		q = p->point;
		while(q != NULL){
			printf("--%d-->%d",q->info,q->next->info);
			q = q->point;
		}
		printf("\n");
		p = p->next;
	}
}

vertics * removeVertics(vertics * root,int x){
	vertics * p = root, * r= root,*s,*t;
	if(root == NULL)
		return NULL;
	while(p != NULL){
		if(p->info == x){
			t = p;
			break;
		}
		p = p->next;
	}
	p = root;
	while(p != NULL){
		r = p->point;
		if(r == NULL){
			p = p->next;
			continue;
		}
		if(r->next->info == t->info){
			p->point = r->point;
			free(r);
			p = p->next;
			continue;
		}
		while(r != NULL){
			if(r->next->info == t->info){
				s->point = r->point;
				free(r);
				break;
			}
			s = r;
			r = r->point;
		}
		p = p->next;
	}
	p = root;
	if(p->info == x){
		root = root->next;
		r = p->point;
		free(p);
		while(r != NULL){
			s = r;
			r  = r->point;
			free(s);
		}
		return(root);
	}
	while(p!=NULL){
		if(p->info == x){
			r->next = p->next;
			s = p->point;
			free(p);
			while(s != NULL){
				t = s;
				s = s->point;
				free(t);
			}
			break;
		}
		r = p;
		p = p->next;
	}
	return root;
}

int main(int argc, char const *argv[])
{
	int x,info,y,w;
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
				printf("enter edge's start and end vertics and weight\n");
				scanf("%d%d%d",&x,&y,&w);
				addEdge(root,x,y,w);
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