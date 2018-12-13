#include<stdio.h>
#include<stdlib.h>

void bubble(int arr[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j = 0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

void main()
{
	int i,n;
	printf("enter number of elements:\n");
	scanf("%d",&n);
	int arr[n];
	printf("enter element:\n");
	for (i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	bubble(arr,n);
	printf("after sorting...\n");
	for (i = 0; i < n; ++i)
		printf("%d ",arr[i]);
}