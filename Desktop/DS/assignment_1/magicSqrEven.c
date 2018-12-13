// magic square of number divisible by 4 //
#include<stdio.h>

void doublyEven(int n){
	int arr[n][n],i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			arr[i][j]=n*i+j+1;
	}

	for(i=0;i<n/4;i++){
		for(j=0;j<n/4;j++)
			arr[i][j]= n*n+1-arr[i][j];
	}
	for(i=0;i<n/4;i++){
		for(j=3*(n/4);j<n;j++)
			arr[i][j]= n*n+1-arr[i][j];
	}
	for(i=3*(n/4);i<n;i++){
		for(j=0;j<n/4 ;j++)
			arr[i][j]= n*n+1-arr[i][j];
	}
	for(i=3*(n/4);i<n;i++){
		for(j=3*(n/4);j<n;j++)
			arr[i][j]= n*n+1-arr[i][j];
	}

	for(i=n/4;i<3*(n/4);i++){
		for(j=n/4;j<3*(n/4);j++)
			arr[i][j]=n*n+1-arr[i][j];
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d\t",arr[i][j]);
		printf("\n");
	}

}

void main(){
	int n;
	printf("enter any number divisible for 4: ");
	scanf("%d",&n);
	if(n%4==0)
		doublyEven(n);
	else 
		printf("sorry entered number is not valid\n");
}