// magic square of number divisible by 2 //
#include<stdio.h>
void mgcSqrOdd(int *arr,int n,int l,int h){ 
	int i,j,x;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			*(arr+n*i+j)=0;
	}

	i = 0,j = n/2;
	for(x=l;x<=h;x++){
		if(i-n==-1&&j-n==-1){
			i=1,j=0;
			*(arr+i*n+j)=x;
		}
		else if(*(arr+i*n+j)==0){
			*(arr+i*n+j)= x;
		}
		else if(*(arr+i*n+j)!=0){
			i+=2;
			j++;
			*(arr+i*n+j)=x;
		}

		i--;
		j--;
		if(i<0)
			i+=n;
		if(j<0)
			j+=n;
	}
}
void swap(int *a,int *b){
	int t = *a;
	*a = *b;
	*b = t;
}
int main( )
{
	int n;
	printf("enter any number divisible by 2 except 2:  ");
	scanf("%d",&n);
	if(n%2!=0 || n==2||n%4==0){
		printf("enter number is not valid: \n");
		return 0;
	}
	int ar[n/2][n/2],arr[n][n],i,j,t;
	mgcSqrOdd(&ar[0][0],n/2,1,1*n*n/4);
	for(i=0;i<n/2;i++){
		for(j=0;j<n/2;j++)
			arr[i][j]=ar[i][j];
	}
	mgcSqrOdd(&ar[0][0],n/2,1*(n*n)/4+1,2*n*n/4);
	for(i=n/2;i<n;i++){
		for(j=n/2;j<n;j++)
			arr[i][j]=ar[i-n/2][j-n/2];
	}
	mgcSqrOdd(&ar[0][0],n/2,2*(n*n)/4+1,3*n*n/4);
	for(i=0;i<n/2;i++){
		for(j=n/2;j<n;j++)
			arr[i][j]=ar[i][j-n/2];
	}
	mgcSqrOdd(&ar[0][0],n/2,3*n*n/4+1,n*n);
	for(i=n/2;i<n;i++){
		for(j=0;j<n/2;j++)
			arr[i][j]=ar[i-n/2][j];
	}

	for(i=0;i<n/2;i++){
		for(j=n/2+n/4-2;j>=n/2;j--)
			swap(&arr[i][j],&arr[n/2+i][j]);
	} 
	for(i=0;i<n/2;i++){
		for(j=n/2-1;j>=n/2-n/4;j--)
			swap(&arr[i][j],&arr[i+n/2][j]);
	}
	swap(&arr[n/4][n/2-1],&arr[n/2+n/4][n/2-1]);
	swap(&arr[n/4][n/4],&arr[n/2+n/4][n/4]);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d\t",arr[i][j]);
		printf("\n");
	}
	return 0;
}