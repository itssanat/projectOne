#include<bits/stdc++.h>
#define ll long long int
#define v vector
using namespace std;

ll dp[101][101];
ll arr[101][101];
ll n,m;

ll func(ll x,ll y){
	if(y<0 || y>=m)
		return INT_MIN;
	if(x == n-1)
		return arr[x][y];
	if(dp[x][y] != -1)
		return dp[x][y];
	dp[x][y] = max(arr[x][y]+func(x+1,y),max(arr[x][y]+func(x+1,y-1),arr[x][y]+func(x+1,y+1)));
	return dp[x][y];
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<=n;i++)
			for(int j= 0;j<=m;j++)
				dp[i][j] = -1;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>arr[i][j];
		if(n== 1){
			ll max = INT_MIN;
			for(int i=0;i<m;i++)
				if(arr[0][i]>max)
					max = arr[0][i];
			cout<<max<<endl;
			continue;
		}
		ll fare = INT_MIN;
		for(int i=0;i<m;i++){
			ll num = func(0,i);
			if(fare < num)
				fare = num;
		}
		cout<<fare<<endl;
	}
	return 0;
}