#include<bits/stdc++.h>
#define ll long long int
#define v vector
using namespace std;
string str;
ll dp[5005];

ll func(int i,int n){
	if(i > n-1)
		return 1;
	if(i == n-1 && str[i] != '0')
		return 1;
	if(dp[i]!= -1)
		return dp[i];
	if(str[i] == '0'){
		dp[i] = 0;
		return 0;
	}
	else{
		int a = str[i]-'0';
		int b = str[i+1]-'0';
		a = a*10+b;

		if(a > 26){
			dp[i] = func(i+1,n);
		}
		else if(a == 10 || a == 20){
			dp[i] = func(i+2,n);
		}
		else{
			dp[i] = func(i+1,n)+func(i+2,n);
		}
		return dp[i];
	}
}

int main()
{
	while(true){
		cin>>str;
		if(str == "0")
			break;
		int n = str.size();
		memset(dp,-1,sizeof(dp));
		ll res = func(0,n);
		cout<<res<<endl;
	}
	return 0;
}