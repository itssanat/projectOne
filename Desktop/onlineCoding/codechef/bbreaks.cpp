#include<bits/stdc++.h>
#define ll long long int
#define v vector
using namespace std;
#define mod  1000000007

ll prod(ll n, ll k){
	ll sum = 1;
	for(ll i =0;i<=k;i++){
		sum = (sum*(n-i))%mod;
	}
	return sum;
}

int main()
{
	ll t,n,k,sum = 0;
	ll a,b,c;
	cin>>t;
	while(t--){
		cin>>n>>k;
		n++;
		for(ll i =0;i<=k;i++){
			a = prod(n-2*i+1,i-1)%mod;
			b = prod(n-2*k+i+1,k-i-1)%mod;
			c = (a*b)%mod;
			//cout<<a<<b<<endl;
			if(i == 0 || i == k)
				sum = (sum + (ll)ceil(c/k))%mod;
			else
				sum = (sum+c/(i*(k-i)))%mod;
			cout<<sum<<endl;
		}
		cout<<sum<<endl;
		sum = 0;	
	}
	cin>>t;
	return 0;
}