#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[100001];
int n;

ll maxToy(int arr[],int l){
	if(l>n) return 0;
	if(n == l) return arr[l];
	if(n == l+1) return (arr[l]+arr[l+1]);
	if(n == l+2) return (arr[l]+arr[l+1]+arr[l+2]);
	if(dp[l]!=-1) return dp[l];
	ll a = arr[l]+maxToy(arr,l+2);
	ll b = arr[l]+arr[l+1]+maxToy(arr,l+4);
	ll c = arr[l]+arr[l+1]+arr[l+2]+maxToy(arr,l+6);
	dp[l] = max(a,max(b,c));
	return dp[l];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(dp,-1,(n+2)*sizeof(dp[0]));
		int arr[n];
		for(int i=0;i<n;i++) 
			scanf("%d",&arr[i]);
		n--;
		ll res = maxToy(arr,0);
		printf("%lld\n", res);
	}	
	return 0;
}