#include<stdio.h>
#include<stdlib.h>
int p,q;

void partition(int arr[],int l,int r){
	p = q = l;
	int i ;
	for(i = l+1;i<=r;i++){
		if(arr[i] != arr[q]){
			break;
		}
		q = i;
	}
	int j;
	i = q;
	int x = arr[q];
	for( j = q+1;j<=r;j++){
		if(arr[j]<x){
			i = i+1;

			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	int k;
	int z = i;
	for(k = p;k<=q;k++){
		int tmp = arr[k];
		arr[k] = arr[i];
		arr[i] = tmp;
		i--;
	}
	q = z;
	p = i+1;

}

void quickSort(int arr[],int l,int r){
	if(l<r){
		partition(arr,l,r);
		quickSort(arr,l,p-1);
		quickSort(arr,q+1,r);
	}
}

int main()
{
	int n;
	printf("enter the number of elements in array\n");
	scanf("%d",&n);
	int arr[n];
	printf("enter elements\n");
	int i ;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("array before sorting\n");
	for(i=0;i<n;i++)
		printf("%d  ",arr[i]);
	printf("\n");
	quickSort(arr,0,n-1);
	printf("array after sorting...\n");
	for(i = 0;i<n;i++)
		printf("%d  ",arr[i]);
	return 0;
}