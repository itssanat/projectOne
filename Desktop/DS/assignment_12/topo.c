#include<stdio.h>
#include<stdlib.h>

struct  Node
{
	int info;
	struct Node * next;
};
typedef struct Node node;

struct Indegree
{
	int indeg;
	node * next;
};
typedef struct Indegree indegree;

void topological(indegree * arr[],int v){
	int i,j;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			if(arr[j]->indeg == 0){
				printf("%d  ",j);
				arr[j]->indeg--;
				node * p = arr[j]->next;
				while(p != NULL){
					arr[p->info]->indeg--;
					p = p->next;
				}
				break;
			}
		}
	}
}

void main()
{
	int v,e,i,j;
	printf("enter number of vertics and edges\n");
	scanf("%d%d",&v,&e);
	indegree * arr[v];
	for(i = 0;i<v;i++){
		indegree * p = (indegree * )malloc(sizeof(indegree));
		p->indeg = 0;
		p->next = NULL;
		arr[i] = p;
	}

	printf("enter edges\n");
	int x,y;
	for(i=0;i<e;i++){
		scanf("%d%d",&x,&y);
		node * q = (node *)malloc(sizeof(node));
		q->info = y;
		q->next = NULL;
		node * p = arr[x]->next;
		arr[y]->indeg++;
		if(p == NULL){
			arr[x]->next = q;
			continue;
		}
		while(p->next != NULL)
			p = p->next;
		p->next = q;
	}
	topological(arr,v);

	printf("\n");
}