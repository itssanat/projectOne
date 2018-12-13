#include<bits/stdc++.h>
#define ll long long int;
#define v vector
using namespace std;

int main()
{
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		int arr[n],sum = 0;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		for(int i=0;i<n-2;i++){
			if(arr[i]>k){
				arr[i+1] = arr[i+1]+k-arr[i];
				arr[i] = k;
			}
			sum+=arr[i];
		}
		if(arr[n-2]>k){
			arr[n-1] = arr[n-2] +k - arr[n-1]
		}
		sum+=arr[n-1];
		cout<<sum<<endl;
	}
	return 0;
}