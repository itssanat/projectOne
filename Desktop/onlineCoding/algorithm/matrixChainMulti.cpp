#include<bits/stdc++.h> // matrix chain multiplication using dp //
#define ll long long int  // complexity is n*n*n;
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int d[n];
        for(int i=0;i<n;i++) cin>>d[i];
        int arr[n][n] = {0};
        for(int i=0;i<n;i++) arr[i][i] = 0;
        
        for(int l = 2;l<n;l++){
            for(int i = 1;i<=n-l;i++){
                int j = i+l-1;
                int min = INT_MAX;
                for(int k = i;k<j;k++){
                    int tmp = arr[i][k]+arr[k+1][j]+d[i-1]*d[k]*d[j];
                    if(tmp<min)
                        min = tmp;
                }
                arr[i][j] = min;
            }
        }
        cout<<arr[1][n-1]<<endl;
        
    }
	return 0;
}