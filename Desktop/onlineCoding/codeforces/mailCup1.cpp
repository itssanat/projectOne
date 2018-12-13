#include<bits/stdc++.h>
#define ll long long int;
#define v vector
using namespace std;

int main()
{
	int n;
	cin>>n;
	int l[n],arr[n],r[n];
	for(int i = 0;i<n;i++) 
		cin>>l[i];
	for(int i =0;i<n;i++) 
		cin>>r[i];
	v< pair<int ,int > > vect;
	for(int i=0;i<n;i++){
		vect.push_back(make_pair(-(l[i]+r[i]),i));
	}
	sort(vect.begin(),vect.end());
	int pre = INT_MIN,curr = 0;
	for(int i=0;i<vect.size();i++){
		if(vect[i].first>pre){
			arr[vect[i].second] = ++curr;
			pre = vect[i].first;
		}
		else arr[vect[i].second] = curr;
	}
	int nl[n],nr[n];
	for(int i=0;i<n;i++){
		nl[i] = nr[i] = 0;
		for(int j =0;j<i;j++){
			if(arr[j]>arr[i])
				nl[i]++;
		}
		for(int j=i+1;j<n;j++){
			if(arr[j]>arr[i])
				nr[i]++;
		}
	}
	for(int i=0;i<n;i++){
		if(l[i]!=nl[i] || nr[i]!=r[i]){
			cout<<"NO"<<endl;
			exit(0);
		}
	}
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	return 0;
}