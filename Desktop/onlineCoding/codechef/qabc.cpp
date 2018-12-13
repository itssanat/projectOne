#include<bits/stdc++.h>
#define ll long long int;
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int a[n],b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++){
			cin>>b[i];
			b[i]-=a[i];
		}
		int i;
		if(n==1){
			if(b[0] == 0){
				cout<<"TAK"<<endl;
				continue;
			}
			cout<<"NIE"<<endl;
			continue;
		}
		if(n == 2){
			if(b[0]==0 || b[1] == 0){
				cout<<"TAK"<<endl;
				continue;
			}
			cout<<"NIE"<<endl;
			continue;
		}
		for(i =0;i<n-2;i++){
			if(b[i]<0)
				break;
			if(b[i]>0){
				b[i+1] -=2*b[i];
				b[i+2]-=3*b[i];
			}
		}
		cout<<i<<endl;
		if(i == n-2 && b[n-2] == 0 && b[n-1] == 0) 
			cout<<"TAK"<<endl;
		else
			cout<<"NIE"<<endl;
	}
	return 0;
}