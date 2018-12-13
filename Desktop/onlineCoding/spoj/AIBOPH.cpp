#include<bits/stdc++.h>
#define ll long long int
#define v vector
using namespace std;
int dp[6101][6101];

int change(char str[],int l,int r){
	if(l>r) return 0;
	if(dp[l][r] != -1) return dp[l][r];
	if(str[l]==str[r]){
		dp[l][r] = change(str,l+1,r-1);
		return dp[l][r];
	}
	dp[l][r] = 1+min(change(str,l+1,r),change(str,l,r-1));
	return  dp[l][r];
}

int main()
{
	int t;
	cin>>t;
	while(--t>=0)
	{
		char str[6100];
		scanf("%s",str);
		int l = strlen(str);
		memset(dp,-1,sizeof(dp));
		int res = change(str,0,l-1);
		cout<<res<<endl;
	}
	return 0;
}