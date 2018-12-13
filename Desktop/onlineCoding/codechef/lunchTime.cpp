#include<bits/stdc++.h>
#define ll long long int
#define v vector
using namespace std;

int main()
{
	int t,n,m,k,l;
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>l;
		int arr[n];
		int min = INT_MAX,tmp;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		int i;
		for(i=0;i<n;i++){
			tmp = m*l-arr[i]+l*(i+1);
			if(tmp <min)
				min = tmp;
		}
		tmp = m*l-k+(n+1)*l;
		if(tmp<min)
			min = tmp;
		if(min <= 0)
			cout<<0<<endl;
		else
			cout<<min<<endl;
	}
	return 0;
}