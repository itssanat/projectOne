#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int v,e,w,count = 0,top = -1;

bool cycle(int mst[v][v][2],bool visit[v],int x,int parent){  //dfs  // 
	if(visit[x]){
		return true;
	}
	visit[x] = true;
	int i;
	for(i = 0;i<v;i++){
		if(mst[x][i][0] == 1 && i != parent){
			if(cycle(mst,visit,i,x)){
				return true;
			}
		}
	}
	return false;
}

void kruskal(int mat[v][v][2], int mst[v][v][2],int arr[3][e]){
	top++;
	int x = arr[1][top],i;
	int y = arr[2][top];
	bool visit[v];
	for(i = 0;i<v;i++) 
		visit[i] = false;

	mst[x][y][0] = mst[y][x][0] = 1;
	mst[x][y][1] = mst[y][x][1] = arr[0][top];
	int count = 1;

	while(count < v-1 && top<e){
		top++;
		x = arr[1][top];
		y = arr[2][top];
		mst[x][y][0] = mst[y][x][0] = 1;
		mst[x][y][1] = mst[y][x][1] = arr[0][top];

		for(i = 0;i<v;i++) 
			visit[i] = false;
		if(cycle(mst,visit,x,x)){
			mst[x][y][0] = mst[y][x][0] = 0;
			mst[x][y][1] = mst[y][x][1] = 0;
			continue;
		}
		else{
			count++;
		}
	}
}

int main()
{
	printf("enter number of vertics and edges: ");
	scanf("%d%d",&v,&e);
	int mat[v][v][2];
	int arr[3][e];
	int i,j,x,y;
	for(i=0;i<v;i++){
		for(j =0;j<v;j++)
			mat[i][j][0] = mat[i][j][1] = 0;
	}
	printf("enter start and end of edge's and weight\n");
	for(i =0;i<e;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		mat[x][y][0] = 1;
		mat[x][y][1] = w;
		mat[y][x][0] = 1;
		mat[y][x][1] = w;
		arr[0][i] = w;
		arr[1][i] = x;
		arr[2][i] = y;
 	}

	int mst[v][v][2];
	for(i=0;i<v;i++){
		for(j =0;j<v;j++)
			mst[i][j][0] = mst[i][j][1] = 0;
	}

	
	for(i=0;i<e;i++){
		for(j=0;j<e-i-1;j++){
			if(arr[0][j]>arr[0][j+1]){
				int tmp = arr[0][j];
				arr[0][j] = arr[0][j+1];
				arr[0][j+1] = tmp;

				tmp = arr[1][j];
				arr[1][j] = arr[1][j+1];
				arr[1][j+1] = tmp;

				tmp = arr[2][j];
				arr[2][j] = arr[2][j+1];
				arr[2][j+1] = tmp;
			}
		}
	}

	kruskal(mat,mst,arr);

	printf("adjacency matrix of mst\n");

	for(i =0;i<v;i++){
		for(j=0;j<v;j++){
			printf("%d  ",mst[i][j][0]);
		}
		printf("\n");
	}

	return 0;
}