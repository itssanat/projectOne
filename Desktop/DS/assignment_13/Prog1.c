#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int v,e;

void DFS(bool mat[v][v],bool visit[], int x){
	visit[x] = true;
	printf("%d  ",x);
	int i;
	for( i  = 0;i<v;i++){
		if(mat[x][i] && !visit[i]){
			DFS(mat,visit,i);
		}
	}
}

void BFS(bool mat[v][v],bool visit[], int x){
	int i;
	int arr[v];
	int k =0;
	for(i=0;i<v;i++){
		if(mat[x][i] && !visit[i]){
			printf("%d  ",i);
			arr[k++] = i;
			visit[i] = true;
		}
	}
	for(i=0;i<k;i++){
		BFS(mat,visit,arr[i]);
	}
}

int main(int argc, char const *argv[])
{
	printf("enter number of vertics and edges\n");
	scanf("%d%d",&v,&e);
	bool mat[v][v];
	int x,y,i,j;

	for(i=0;i<v;i++)
		for(j =0;j<v;j++)
			mat[i][j] = false;

	printf("enter edge (starting vertics and destination vertics): \n");
	for(i =0;i<e;i++){
		scanf("%d%d",&x,&y);
		mat[x][y] = true;
	}
	bool visit[v];
	for(i=0;i<v;i++) visit[i] = false;

	printf("enter the starting vertics of DFS\n");
	scanf("%d",&x);
	DFS(mat,visit,x);
	printf("\n");
	for(i=0;i<v;i++) visit[i] = false;
	printf("enter the starting vertics of BFS\n");
	scanf("%d",&x);
	printf("%d  ",x);
	visit[x] = true;
	BFS(mat,visit, x);
	return 0;
}