#include<stdio.h>
int arr[100];

int fab(int a){
	if(arr[a]!=-1)
		return arr[a];
	arr[a] = fab(a-1)+fab(a-2);
	return arr[a];
}

void main(){
	int a,i;
	for(i=0;i<100;i++)
		arr[i]=-1;
	arr[0]=0;
	arr[1]=1;
	printf("enter any number: \n");
	scanf("%d",&a);
	printf("fibonacci series:  ");
	int f = fab(a);
	for(i=0;i<a;i++)
		printf("%d  ",arr[i]);
}