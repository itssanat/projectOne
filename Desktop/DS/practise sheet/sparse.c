#include <stdio.h>
int row,col,tdata;

void print(int mat[][3]){
	int i;
	printf("\n");
	for(i=0;i<=tdata;i++)
		printf("%d\t%d\t%d\n",mat[i][0],mat[i][1],mat[i][2]);
}

void swap(int *p,int *q){
	int i = *p;
	*p = *q;
	*q = i;
}

void sort(int mat[][3]){
	int i,j,k;
	for(i=0;i<=tdata;i++){
		for(j=1;j<tdata;j++){
			if(mat[j][0]>mat[j+1][0]){
				swap(&mat[j][0],&mat[j+1][0]);
				swap(&mat[j][1],&mat[j+1][1]);
				swap(&mat[j][2],&mat[j+1][2]);
			}
			if(mat[j][0] == mat[j+1][0] && mat[j][1]>mat[j+1][1]){
				swap(&mat[j][0],&mat[j+1][0]);
				swap(&mat[j][1],&mat[j+1][1]);
				swap(&mat[j][2],&mat[j+1][2]);
			}
		} 
	}
}

void addition(int mat[][3]){
	int r,c,n,i,count=0;
	scanf("%d%d%d",&r,&c,&n);
	int mat1[tdata+1][3];
	mat1[0][0] = r;
	mat1[0][1] = c;
	mat1[0][2] = n;
	for(i=1;i<=n;i++){ /// taking input //
		scanf("%d%d%d",&mat1[i][0],&mat1[i][1],&mat1[i][2]);
	} 

	if(mat[0][0] == mat1[0][0] && mat[0][1] == mat1[0][1]){
		sort(mat);
		sort(mat1);
		
	}
}

void transpose(int mat[][3]){
	int t,i,j,k;
	for(i=0;i<=tdata;i++)
		swap(&mat[i][0],&mat[i][1]);
	sort(mat);
}

int main(int argc, char const *argv[])
{
	printf("enter total no. of rows, columns and entries:\n");
	scanf("%d%d%d",&row,&col,&tdata);
	int mat[tdata+1][3];
	mat[0][0] = row;
	mat[0][1] = col;
	mat[0][2] = tdata;
	int i;
	for(i=1;i<=tdata;i++){ /// taking input //
		scanf("%d%d%d",&mat[i][0],&mat[i][1],&mat[i][2]);
	}
	print(mat);
	transpose(mat);
	print(mat);
	addition(mat);
	return 0;
}