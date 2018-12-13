#include<bits/stdc++.h>
#define ll long long int
#define v vector
using namespace std;

bool isPossible(int x,int n,int a,int b){
	int i;
	if(x<0)
		i = 0;
	else
		i = x/a;
	for(i;i<=n;i++){
		for(int j=0;(j+i)<=n;j++)
		{
			if(x == (i*a-j*b))
				return true;
			if(x > (i*a-j*b))
				break;
		}
	}
	return false;
}

int main()
{
	int t,n,a,b;
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		int c = 0;
		for(int i=-(n*b);i<=n*a;i++){
			if(isPossible(i,n,a,b))
				c++;
		}
		cout<<c<<endl;
	}
	return 0;
}