#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i,n;
	printf("enter number of elements:\n");
	scanf("%d",&n);
	int arr[n];
	printf("enter element:\n");
	for (i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	
	printf("after sorting...\n");
	for (i = 0; i < n; ++i)
		printf("%d ",arr[i]);
}