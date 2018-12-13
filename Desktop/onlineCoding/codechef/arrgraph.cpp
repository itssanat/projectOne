#include<bits/stdc++.h>
#define ll long long int;
#define v vector
using namespace std;
int isPrime[51];

int main()
{
	int t,n;
	cin>>t;
	isPrime[2]=isPrime[3]=isPrime[5]=isPrime[7]=isPrime[11]=isPrime[13]=isPrime[17]=isPrime[19]=isPrime[23]=1;
	isPrime[29]=isPrime[31]=isPrime[37]=isPrime[41]=isPrime[43]=isPrime[47]=1;
	while(t--){
		cin>>n;
		int arr[n],mx =-1,index = -1,flag = 0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(isPrime[arr[i]] == 1 && arr[i]>mx){
				mx = arr[i];
				index = i;
			}
		}
		//cout<<mx<<" "<<index<<endl;
		if(index != -1){
			for(int i=0;i<n;i++){
				if(i!= index && arr[i]%mx == 0 ){
					flag = 1;
					break;
				}
			}
		}
		else{
			for(int i=0;i<n;i++){
				for(int j =0;j<n;j++)
					if(arr[j]%arr[i] == 0 && i != j)
						flag = 11;
			}
		}
		if(flag == 0){
			cout<<0<<endl;
			for(int i=0;i<n;i++)
				cout<<arr[i]<<" ";
		}
		else if(flag == 1){
			cout<<1<<endl;
			arr[index] = 47;
			for(int i=0;i<n;i++)
				cout<<arr[i]<<" ";
		}
		else{
			cout<<1<<endl;
			arr[0] = 47;
			for(int i=0;i<n;i++)
				cout<<arr[i]<<" ";
		}
	}
	return 0;
}