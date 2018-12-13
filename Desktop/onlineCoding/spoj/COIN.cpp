#include<bits/stdc++.h>
#define ll long long int
#define v vector
using namespace std;
#define len 1000001
int dp[len];

ll dollor(ll n){
	if(n == 0) return 0;
	if(n<len){
		if(dp[n]!=0) return dp[n];
		dp[n] = max(n,(dollor(n/2)+dollor(n/3)+dollor(n/4)));
		return dp[n];
	}
	else{
		return max(n,(dollor(n/2)+dollor(n/3)+dollor(n/4)));
	}
}

int main()
{
	ll n;
	while(scanf("%lld",&n)!=EOF){
		ll res = dollor(n);
		cout<<res<<endl;
	}	
	return 0;
}