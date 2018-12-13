/// to calculate large fibonacci number //
// complexity is logn // 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007

void multiply(ll F[2][2], ll M[2][2])  // multiplication of two matrix //
{ 
	ll x = ((F[0][0]*M[0][0]) + (F[0][1]*M[1][0]))%mod; /// taking mod /// 
	ll y = ((F[0][0]*M[0][1]) + (F[0][1]*M[1][1]))%mod; 
	ll z = ((F[1][0]*M[0][0]) + (F[1][1]*M[1][0]))%mod; 
	ll w = ((F[1][0]*M[0][1]) + (F[1][1]*M[1][1]))%mod; 
	F[0][0] = x;
	F[0][1] = y; 
	F[1][0] = z; 
	F[1][1] = w; 
}

void power(ll F[2][2], ll n)  // using binary exponentian method //
{
	if( n == 0 || n == 1) 
		return; 
	ll M[2][2] = {{1,1},{1,0}}; 

	power(F, n/2); 
	multiply(F,F);

	if (n%2!=0) 
		multiply(F,M);
}

ll fib(ll n) 
{
	ll F[2][2] = {{1,1},{1,0}}; 
	if (n == 0)
		return 0;
	power(F, n-1); 
	return F[0][0]; 
}

int main()
{ 
	int t;
	scanf("%d",&t);
	while(t--){
		ll n;
		scanf("%lld",&n);
		ll ans = fib(n);
		printf("%lld\n",ans);
	}
	return 0; 
} 