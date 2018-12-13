#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int t,n,w;

        cin>>w>>n;
        int val[n+1],wt[n+1];
        for(int i=1;i<=n;i++){
            cin>>val[i]>>wt[i];
        }
        int arr[n+1][w+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=w;j++){
                if(j == 0 || i == 0)
                arr[i][j] = 0;
                else if(j<wt[i]){
                    arr[i][j] = arr[i-1][j];
                }
                else{
                    arr[i][j] = max(val[i]+arr[i-1][j-wt[i]],arr[i-1][j]);
                }
            }
        }
        cout<<arr[n][w]<<endl;
        
	return 0;
}