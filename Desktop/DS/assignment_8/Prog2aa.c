#include <stdio.h>
#include <stdlib.h>

void display(int arr[][3] ){
	int c = arr[0][2];
	int i;
	for(i = 0;i<=c;i++){
		printf("%d  %d  %d\n",arr[i][0],arr[i][1],arr[i][2]);
	}
}

void delete(int arr[][3] ,int ind){
	int n = arr[0][2];
	int  i = ind;
	for(i = ind ;i<n;i++){
		arr[i][0] = arr[i+1][0];
		arr[i][1] = arr[i+1][1];
		arr[i][2] = arr[i+1][2];
	}
	arr[0][2]--;
}

int main()
{
	int r,c,n;
	printf("enter number of row, column and number of data\n");
	scanf("%d%d%d",&r,&c,&n);
	int arr[n+1][3];
	printf("please enter info. one by one\n");
	int i ;
	arr[0][0] = r,arr[0][1] = c ,arr[0][2] =  n;
	for(i = 1;i<=n;i++){
		printf("enter row, column and info\n");
		scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
	}
	printf("matrix before deletion row...\n");
	display(arr);
	printf("enter the row which you want to delete\n");
	int j;
	scanf("%d",&j);
	for(i=1;i<=n;i++){
		if(arr[i][0] == j){
			delete(arr,i);
			i--;
		}
	}
	display(arr);
	return 0;
}