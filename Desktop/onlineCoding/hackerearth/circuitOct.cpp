#include<bits/stdc++.h>
using namespace std;
int po[1000001],ni[1000001];

int func(int n,int a,int b,int sum){
	if(n == 0){
		if(sum<0 && ni[(-sum)]==0){
			ni[(-sum)] = 1;
			return 1;
		}
		else if(sum >=0&&po[sum]==0){
			po[sum] = 1;
			return 1;
		}
		else
			return 0;
	}
	return func(n-1,a,b,sum+0)+func(n-1,a,b,sum+a)+func(n-1,a,b,sum-b);
}

int main()
{
	int t,n,a,b;
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		memset(po,0,(n+1)*a*sizeof(po[0]));
		memset(ni,0,(n+1)*b*sizeof(ni[0]));
		int res = func(n,a,b,0);
		cout<<res<<endl;
	}
	return 0;
}