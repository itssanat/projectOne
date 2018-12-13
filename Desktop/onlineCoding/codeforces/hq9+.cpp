#include<bits/stdc++.h>
#define ll long long int;
#define v vector
using namespace std;
int main()
{
	string str;
	cin>>str;
	int l = str.size();
	int i;
	for(i = 0;i<l;i++){
		if(str[i]=='H'||str[i]=='Q'||str[i]=='9')
			break;
	}
	if(i == l)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
	return 0;
}