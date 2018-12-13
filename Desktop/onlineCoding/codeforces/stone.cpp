#include<bits/stdc++.h>
#define ll long long int;
#define v vector
using namespace std;
int main()
{
	int n,count= 0;
	string str;
	cin>>n;
	cin>>str;
	for(int i =1;i<n;i++)
		if(str[i] == str[i-1])
			count++;
	cout<<count<<endl;
	return 0;
}