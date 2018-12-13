#include<bits/stdc++.h>
#define ll long long int;
#define v vector
using namespace std;
int main()
{	
	int x,y,num;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>num;
			if(num == 1)
				x = i,y = j;
		}
	}	
	cout<<fabs(2-x)+fabs(2-y)<<endl;
	return 0;
}