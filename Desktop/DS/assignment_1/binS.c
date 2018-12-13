#include<stdio.h>
int arr[100],n;

int binS(int l,int h,int num) // binary search using recursion
{
	if(h<l)
		return -1;
	int m = (l+h)/2;
	if(arr[m]>num)
		return binS(l,m-1,num);
	if(arr[m]<num)
		return binS(m+1,h,num);
	return m;
}

// sorting using insertion sort//
void Isort(){
	int j,i,key;
	for(j=1;j<n;j++){
		key = arr[j];
		i = j-1;
		while(i>=0&& arr[i]>key){
			arr[i+1]=arr[i];
			i--;
		}
		arr[i+1]=key;
	}
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
	Isort();
	i= binS(0,n-1,num);
	if(i == -1)
		printf("no such element is in the array\n");
	else
		printf("element is at index %d in sorted array.\n",i );
}