#include<bits/stdc++.h>
#define ll long long int
#define v vector
using namespace std;
#define MAX 1000000
int mrp[105];
int dp[101][101];
int n,k;

int minPrice(int nop,int i,int sum){

	if(sum<0)
		return MAX;
	if(i<0 && sum != 0)
		return MAX;
	if(sum == 0)
		return 0;
	if(dp[sum][i] != -1)
		return dp[sum][i];
	if(mrp[i] == -1){
		dp[sum][i] = minPrice(nop,i-1,sum);
		return dp[sum][i];
	}
	else{
		int a = minPrice(nop,i-1,sum);
		int b = mrp[i] + minPrice(nop+1,i,sum-(i+1));
		dp[sum][i] = min(a,b);
		return dp[sum][i];
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<k;i++)
			cin>>mrp[i];
		memset(dp,-1,sizeof(dp));
		int price = minPrice(0,k-1,k);
		if(price >= MAX)
			cout<<-1<<endl;
		else
			cout<<price<<endl;
	}	
	return 0;
}