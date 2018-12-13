#include<bits/stdc++.h>
#define ll long long int
#define v vector
using namespace std;
int n,w;
ll dp[10005][505];
int val[501],wt[501];

ll func(int i,int sum){
	if((i <0 && sum != 0)||sum<0) 
		return INT_MAX;
	if(sum == 0) 
		return 0;
	if(dp[sum][i] != -1) 
		return dp[sum][i];
	ll a = func(i-1,sum);
	ll b = val[i]+func(i,sum-wt[i]);
	dp[sum][i] = min(a,b);
	return dp[sum][i];
}

int main()
{
	int t,wi,wf;
	cin>>t;
	while(t--){
		cin>>wi>>wf;
		w = wf-wi;
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>val[i]>>wt[i];
		}
		memset(dp,-1,sizeof(dp));
		ll res = func(n-1,w);
		if(res>=INT_MAX )
			cout<<"This is impossible."<<endl;
		else
			cout<<"The minimum amount of money in the piggy-bank is "<<res<<"."<<endl;
	}
	return 0;
}