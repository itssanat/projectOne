#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int arr[11],top = -1;
ll ans;

ll digisum(ll num){
    ll sum = 0;
    while(num > 0){
        sum = sum+num%10;
        num = num/10;
    }
    return sum;
}

int minInd(){
    int id  = 0;
    for(int i=1;i<=top;i++){
        if(arr[id] > arr[i])
            id = i;
    }
    return id;
}

void Answ(ll n, ll d){
    n = n%9;
    if(n == 0)
        n = 9;
    arr[++top] = n;
    while(true){
        n = (n + d%9)%9;
        if(n == 0)
            n = 9;
        if(n == arr[0])
            break;
        arr[++top] = n;
    }
    int id = minInd();
    ans = arr[id];
}

long long int func(ll n,ll d,int h){
    if(h == 20)
        return INT_MAX;
    if(n == ans)
        return 0;
    h++;
    return 1 + min(func(digisum(n),d,h),func(n+d,d,h));
}

int main(){
    ll t,n,c,d;
    cin>>t;
    while(t--){
        cin>>n>>d;
        Answ(n,d);
        c = func(n,d,0);
        cout<<ans<<" "<<c<<endl;
        top = -1;
    }
}