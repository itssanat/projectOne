#include <iostream>
using namespace std;
#define mod 1000000007
#define ll long long int

ll func(ll n)
{
	ll res = n;
	for(int i=2;i*i<=n;i++)
		{
			if(n%i==0)
			res = res - res/i;
			while(n%i==0) 
				n=n/i;
		}
		if(n>1){
			res = res - res/n;
		}
	return res;
}
 
int main()
{
		ll n,res = 1;
		cin>>n;
		for(int i = 1;i<=n/2;i++){
			if(n%i == 0){
			res *= func(i);
			res = res%mod;
			}
		}
		res = res*func(n)%mod;
		
		cout<<res<<endl;
	return 0;
}