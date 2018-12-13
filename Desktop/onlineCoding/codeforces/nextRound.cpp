#include<bits/stdc++.h>
#define ll long long int;
#define v vector
using namespace std;
int main()
{
	int k,n;
	cin>>n>>k;
	k--;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	if(arr[k]!=0){
		int i = k;
		while(arr[i]==arr[k] && i<n)
			i++;
		cout<<i<<endl;
		return 0;
	}	
	int i = k;
	while(arr[i] == arr[k] && i>=0)
		i--;
	cout<<i+1<<endl;
	return 0;
}