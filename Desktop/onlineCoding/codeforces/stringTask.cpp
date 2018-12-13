#include<bits/stdc++.h>
#define ll long long int;
#define v vector
using namespace std;
int main()
{
	string str,res;
	cin>>str;
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	int l = str.size();
	for(int i =0;i<l;i++){
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='y')
			continue;
		res = res+"."+str[i];
	}
	cout<<res<<endl;
	return 0;
}