#include<bits/stdc++.h>
using namespace std;

int func(int arr[],int l,int r){
	if(l>r)
		return 0;
	int id;
	id = distance(arr, max_element(arr+l, arr + r+1));
	if(id == l || id == r)
		return 1;
	return 1+ min(func(arr,id+1,r),func(arr,l,id-1));
}

int main()
{
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int c = func(arr,0,n-1);
		cout<<c<<endl;
	}
	return 0;
}