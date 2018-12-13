#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int h[n],c[n];
		for(int i=0;i<n;i++) cin>>h[i];
		for(int i=0;i<n;i++) cin>>c[i];

		int i =0;
		int arr[n],top = -1;
		while(i<n){
			if(top == -1){
				arr[++top] = i;
				i++;
				continue;
			}
			if(h[i]<h[arr[top]] && c[i]!=c[arr[top]]){
				arr[++top] = i;
				i++;
				continue;
			}
			if(h[i] == h[arr[top]]){
				arr[top] = i;
				i++;
				continue;
			}
			if(h[i]>h[arr[top]]){
				while(top>=0 && h[arr[top]] <=h[i])
					top--;
				if(top == -1 || c[i]!=c[arr[top]])
					arr[++top] = i;
			}
			i++;
		}
		int count  = 0;
		int co[m+1] = {0};
		for(i =0;i<=top;i++){
			if(co[c[arr[i]]] == 0){
				count++;
				co[c[arr[i]]] == 1;
			}
		}
		cout<<count<<endl;
 	}		
	return 0;
}