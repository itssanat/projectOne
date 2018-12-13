#include <stdio.h>
#include <stdlib.h>

void display(int arr[][3] ){
	int c = arr[0][2];
	int i;
	for(i = 0;i<=c;i++){
		printf("%d  %d  %d\n",arr[i][0],arr[i][1],arr[i][2]);
	}
}

void swap(int *a,int *b){
	int i;
	i = *a;
	*a = *b;
	*b = i;
}

void sort(int arr[][3]){
	int i,j,k,n = arr[0][2];
	for(i=1;i<=n;i++){
		for(j = 1;j<n;j++ ){
			if(arr[j][0]>arr[j+1][0]){
				swap(&arr[j][0],&arr[j+1][0]);
				swap(&arr[j][1],&arr[j+1][1]);
				swap(&arr[j][2],&arr[j+1][2]);
			}
			if(arr[j][0] == arr[j+1][0] && arr[j][1] > arr[j+1][1]){
				swap(&arr[j][0],&arr[j+1][0]);
				swap(&arr[j][1],&arr[j+1][1]);
				swap(&arr[j][2],&arr[j+1][2]);
			}
		}
	}
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
	printf("matrix before swap...\n");
	display(arr);
	printf("enter the rows which you want to swap\n");
	int x,y;
	scanf("%d%d",&x,&y);
	for(i=1;i<=n;i++){
		if(arr[i][0] == x){
			arr[i][0] = y;
			continue;
		}
		if(arr[i][0] == y){
			arr[i][0] = x;
		}
	}
	sort(arr);
	display(arr);
	return 0;
}