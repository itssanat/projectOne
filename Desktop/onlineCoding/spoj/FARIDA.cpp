#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int n;
ll dp[10005];

ll coins(ll arr[],int l){
	if(l>n-1) return 0;
	if(dp[l] != -1) return dp[l];
	/*if(isTaken){
		dp[l] = coins(arr,l+1,false);
	}
	else*/ 
		dp[l] = max((arr[l]+coins(arr,l+2)),coins(arr,l+1));
	return dp[l];
}

int main()
{
	int tc;
	cin>>tc;
	for(int t =1;t<=tc;t++){
		cin>>n;
		if(n == 0){
			cout<<"Case "<<t<<": "<<0<<endl;
			continue;
		}
		ll arr[n];
		memset(dp,-1,(n+2)*sizeof(dp[0]));
		for(int i=0;i<n;i++) 
			cin>>arr[i];
		ll res = coins(arr,0);
		cout<<"Case "<<t<<": "<<res<<endl;
	}
	return 0;
}