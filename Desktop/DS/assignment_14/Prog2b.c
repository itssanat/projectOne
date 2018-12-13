#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
int v,e,w;

void prim(int mat[v][v],int mst[v][v],bool initial[v],bool final[v])
{
	int i,j;
	int min = INT_MAX,x,y;
	for(i =0;i<v;i++){
		if(final[i]){
			for(j = 0;j<v;j++){
				if(initial[j]&&(mat[i][j]!=0)&&(min>mat[i][j])){
					min = mat[i][j];
					x = i;
					y = j;
				}
			}
		}
	}
	if(min < INT_MAX){
		initial[y] = false;
		final[y] = true;
		mst[x][y] = mst[y][x] = min;
		prim(mat,mst,initial,final);
	}
}

int main(int argc, char const *argv[])
{
	printf("enter number of vertics and edges: ");
	scanf("%d%d",&v,&e);
	int mat[v][v];
	
	int i,j,x,y;
	for(i=0;i<v;i++){
		for(j =0;j<v;j++)
			mat[i][j] = 0;
	}
	printf("enter start and end of edge's and weight\n");
	for(i =0;i<e;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		mat[x][y] = w;
		mat[y][x] = w;
 	}

	int mst[v][v];
	for(i=0;i<v;i++){
		for(j =0;j<v;j++)
			mst[i][j] = 0;
	}

	bool initial[v] , final[v];
	for(i = 0;i<v;i++){
		initial[i] = true;
		final[i] = false;
	} 
	initial[0] = false;
	final[0] = true;
	prim(mat,mst,initial,final);

	printf("MST representation: vertics---(cost)---vertics\n");

	for(i =0;i<v;i++){
		for(j=i;j<v;j++){
			if(mst[i][j]!=0){
				printf("%d---(%d)---%d\n",i,mat[i][j],j);
			}
		}
	}

	return 0;
}