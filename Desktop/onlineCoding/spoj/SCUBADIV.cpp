#include<bits/stdc++.h>
using namespace std;
int dp[1024][22][80];
int O[1001],N[1001],wt[1001];

int func(int i,int o,int n){
	if(o == 0 && n == 0)
		return 0;
	if(i<0)
		return 100000;  /////
	if(dp[i][o][n] != -1)
			return dp[i][o][n];
	else{
		dp[i][o][n] = min(func(i-1,o,n),wt[i]+func(i-1,max(o-O[i],0),max(n-N[i],0)));
		return dp[i][o][n];
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,o,num;
		cin>>o>>n>>num;
		for(int i=0;i<num;i++){
			cin>>O[i]>>N[i]>>wt[i];
		}
		memset(dp,-1,sizeof(dp));
		int res = func(num-1,o,n);
		cout<<res<<endl;
	}
	return 0;
}