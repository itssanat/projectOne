#include <iostream>
using namespace std;
#define ll long long int

int main(){
	ll t,n,num,day = 0;
	cin>>t;
	while(--t>=0){
		cin>>n;
		ll arr[n];
		cin>>arr[0];
		for(ll i=1;i<n;i++){
			cin>>num;
			arr[i] = num+arr[i-1];
		}
		for(ll i = 0;i<n&&(arr[i]+i+1)<n;){
			i = i+arr[i];
			day++;
		}
		cout<<day+1<<endl;
		day = 0;
	}
}