#include<bits/stdc++.h> 
#define ll long long int  
using namespace std;
#define mod 100
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        n++;
        int d[n];
        int num;
        d[0] = 0;
        for(int i=1;i<n;i++){
            cin>>num;
            d[i] = num+d[i-1];
        }

        /*for(int i=0;i<n;i++)
            cout<<d[i]<<" ";
        cout<<endl;*/


        int arr[n][n] = { 0 };
        for(int i=0;i<n;i++) 
            arr[i][i] = 0;
        for(int l = 2;l<n;l++){

            for(int i = 1;i<=n-l;i++){

                int j = i+l-1;
                int min = INT_MAX;
                for(int k = i;k<j;k++){
                    int tmp = arr[i][k]+arr[k+1][j]+((d[k]-d[i-1])%mod)*((d[j]-d[k])%mod);
                    if(tmp<min)
                        min = tmp;
                }
                arr[i][j] = min;

            }

        }
        cout<<arr[1][n-1]<<endl;
        
        /*for (int i = 0; i < n; ++i)
        {
            for (int j= 0;j < n; ++j)
            {
                cout<<arr[i][j]<<"\t";
            }
            cout<<endl;
        }*/

    }
	return 0;
}