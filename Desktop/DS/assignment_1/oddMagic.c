// /magic square for odd numbers //
#include<stdio.h>
void mgcSqrOdd(int n){ //magic square for odd
	int arr[n][n],i,j,x;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			arr[i][j]=0;
	}

	i = 0,j = n/2;
	for(x=1;x<=n*n;x++){
		if(i-n==-1&&j-n==-1){
			i=1,j=0;
			arr[i][j]=x;
		}
		else if(arr[i][j]==0){
			arr[i][j]= x;
		}
		else if(arr[i][j]!=0){
			i+=2;
			j++;
			arr[i][j]=x;
		}

		i--;
		j--;
		if(i<0)
			i+=n;
		if(j<0)
			j+=n;
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d\t",arr[i][j]);
		printf("\n");
	}
}

int main( )
{
	int n;
	while(1){
		printf("please enter any odd number:  ");
		scanf("%d",&n);
		if(n%2!=0)
			break;
	}
	mgcSqrOdd(n);
	return 0;
}