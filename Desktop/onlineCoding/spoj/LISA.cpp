#include<bits/stdc++.h>
#define ll unsigned long long int
#define v vector
using namespace std;

ll cal(ll n1,char c,ll n2){
	if(c == '+')
		return n1+n2;
	return n1*n2;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		int n = str.size();
		ll arr[n][n];
		for(int i=0;i<n;i = i+2) 
			arr[i][i] = str[i]-48;

		// for maximum value //
		for(int l=2;l<=n;l=l+2){
			for(int i = 0;i<n-l;i=i+2){
				int j = i+l;
				int max = INT_MIN;
				for(int k = i;k<j;k=k+2){
					int tmp = cal(arr[i][k],str[k+1],arr[k+2][j]);
					if(tmp>max)
						max = tmp;
				}
				arr[i][j] = max;
			}
		}
		cout<<arr[0][n-1]<<" ";

		// for minimum value //
		for(int l=2;l<=n;l=l+2){
			for(int i = 0;i<n-l;i=i+2){
				int j = i+l;
				int max = INT_MAX;
				for(int k = i;k<j;k=k+2){
					int tmp = cal(arr[i][k],str[k+1],arr[k+2][j]);
					if(tmp<max)
						max = tmp;
				}
				arr[i][j] = max;
			}
		}
		cout<<arr[0][n-1]<<endl;

		/*for(int i=0;i<n;i = i+2){
				cout<<arr[i][i]<<" ";
			cout<<endl;
		}*/
	}
	return 0;
}