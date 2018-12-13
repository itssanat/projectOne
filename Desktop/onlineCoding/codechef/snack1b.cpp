#include<bits/stdc++.h>
#define ll long long int
#define v vector
using namespace std;
#define mod 1000000007

int main()
{
	ll t,n,k;
	cin>>t;
	while(t--){
		ll flag = 0;
		cin>>n>>k;
		ll arr[k];
		ll sum = 0;
		for(ll i=0;i<k;i++){
			arr[i]=i+1;
			sum+=arr[i];
			if(sum>n){
				flag = 1;
				break;
			}
		}
		if(flag == 1){
			cout<<-1<<endl;
			continue;
		}
		n-=sum;

		for(ll i=0;i<k;i++) 
			arr[i]+=(n/k);
		sum = n%k;
		if(sum != 0)
			arr[k-sum]+=sum;
		if(arr[0] == 1){
			cout<<0<<endl;
			continue;
		}
		sum = 1;
		ll tmp;

		for(ll i=0;i<k;i++){
			tmp = (arr[i]*(arr[i]-1))%mod;
			sum = (sum*tmp)%mod;
		}
		cout<<sum<<endl;
	}
	return 0;
}