#include<bits/stdc++.h>
#define ll unsigned long long int
#define v vector
using namespace std;
int main()
{
	int n,l;
	cin>>n;
	string str,res;
	while(n--){
		cin>>str;
		l = str.size();
		if(l<=10){
			cout<<str<<endl;
			continue;
		}
		ostringstream str1;
		int s = l-2;
		str1<<s;
		res = str[0]+str1.str()+str[l-1];
		cout<<res<<endl;
	}
}