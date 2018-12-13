#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void selection(int arr[],int n){
	int min = INT_MAX,j,i,k;
	for(i = 0;i<n-1;i++){
		min = i;
		for(j = i+1;j<n;j++){
			if(arr[j]<arr[min])
				min = j;
		}
		int tmp = arr[min];
		arr[min]  = arr[i];
		arr[i] = tmp;
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
	selection(arr,n);
	printf("after sorting...\n");
	for (i = 0; i < n; ++i)
		printf("%d ",arr[i]);
}