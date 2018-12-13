#include<stdio.h>
int arr[100],n;

int linS(int num,int i) // linear search using recursion
{
	if(i==n)
		return -1;
	if(arr[i]==num)
		return i;
	return linS(num,i+1);
}

void main(){
	printf("enter the number of element: \n");
	scanf("%d",&n);
	int i,num;
	printf("enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	printf("enter the number to search: ");
	scanf("%d",&num);
	i= linS(num,0);
	if(i == -1)
		printf("no such element is in the array\n");
	else
		printf("element is at index %d\n",i );
}