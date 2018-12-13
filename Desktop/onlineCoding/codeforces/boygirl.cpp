#include<bits/stdc++.h>
#define ll long long int;
#define v vector
using namespace std;
bool arr[26];
int main()
{
	for(int i=0;i<26;i++)
		arr[i] = false;
	string str;
	cin>>str;
	int l = str.size();
	int c = 0;
	for(int i=0;i<l;i++){
		if(!arr[str[i]-97]){
			c++;
			arr[str[i]-97] = true;
		}
	}
	if(c%2 == 0)
		cout<< "CHAT WITH HER!"<<endl;
	else 
	cout<<"IGNORE HIM!"<<endl;
	return 0;
}