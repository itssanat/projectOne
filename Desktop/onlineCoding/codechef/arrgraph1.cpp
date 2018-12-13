#include<bits/stdc++.h>
#define v vector
using namespace std;

int main()
{
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int arr[n],index  = -1,flag = 0,upperBound = -1,initial;
		for(int i =0;i<n;i++){
			cin>>arr[i];
		}
		for(int i=0;i<n;i++){
			if(arr[i] != -1){
				index = i;
				break;
			}
		}
		if(index == -1){
			cout<<"inf"<<endl;
			continue;
		}
		//initial = index;
		for(int i =index+1;i<n;i++){
			if(arr[i] == -1)
				continue;
			if(upperBound != -1){
				if(((i-index-1)%arr[upperBound] + 1)!=arr[i]){
					flag =1;
					break;
				}
			}
			else{
				if(arr[i] < arr[index]+(i -index) &&  arr[i] == ){
					if(arr[i] ==(arr[index]+(i-index))%arr[index]){
						upperBound = index;
						continue;
					}
					if(arr[i] == )
					//}
					/*else{
						flag  = 1;
						upperBound = index;
						break;
					}*/
				}
				else if((arr[index]+(i-index))%arr[i] == 0){
					index = i;
				}
				else{
					flag = 1;
					upperBound = index;
					break;
				}
			}
		}
		//cout<<index<<" "<<arr[upperBound]<<" "<<flag<<endl;
		if(upperBound == -1)
			cout<<"inf"<<endl;
		else if(flag == 0){
			cout<<arr[upperBound]<<endl;
		}
		else{
			cout<<"impossible"<<endl;
		}
	}
	return 0;
}
