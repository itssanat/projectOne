#include<bits/stdc++.h>
#define ll long long int
#include <iterator>
using namespace std;

bool comp(const pair<int ,int > &a,const pair<int ,int > &b){
	if(a.first < b.first)
		return true;
	else if(a.first == b.first){
		if(a.second < b.second )
			return true;
		return false;
	}
	else
		return false;
}

int main()
{
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		vector< pair<int ,int> > v;
		int l,r;
		for(int i=0;i<n;i++){
			cin>>l>>r;
			v.push_back(make_pair(l,r));
		}
		sort(v.begin(),v.end(),comp);
		int mx = INT_MAX;
		vector< pair<int,int> >::iterator p;
		vector<pair<int ,int> >::iterator q;
		for(p = v.begin();p!=v.end();p++){
			q = next(p,k-1);
			if(q == v.end())
				break;
			if(((*p).second-(*q).first)>mx)
				mx= (*p) .second-(*q).first;
		}
		cout<<mx<<endl;
	}	
	return 0;
}