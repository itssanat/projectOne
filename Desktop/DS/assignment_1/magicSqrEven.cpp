// /magic square for odd numbers //
#include<iostream>
using namespace std;

void mgcSqr(int n){
	int arr[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			arr[i][j]=0;
	}

	int i = 0,j = n/2;
	for(int x=1;x<=n*n;x++){
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

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<arr[i][j]<<"\t";
		cout<<endl;
	}
}

int main( )
{
	int n;
	while(true){
		cout<<"please enter any odd number:"<<endl;
		cin>>n;
		if(n%2!=0)
			break;
	}
	mgcSqr(n);
	return 0;
}