#include<bits/stdc++.h>
#define ll long long int;
#define v vector
int arr[5];
using namespace std;
int main()
{
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		arr[x]++;
	}
	int res = arr[4];
	res= res+arr[3];
	res = res+arr[2]/2;
	arr[1] -= arr[3];
	if(arr[2]%2 == 1){
		res++;
		arr[1]-=2;
	}
	if(arr[1]>0){
		if(arr[1]%4 == 0)
			res+=(arr[1]/4);
		else
			res = res+arr[1]/4 + 1;
	}
	cout<<res<<endl;
}