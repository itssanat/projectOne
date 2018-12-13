#include<iostream>
#define ll long long int
using namespace std;

ll digSum(ll n)
{   ll c=0;
    ll sum = 0;
    if(n<10)
    return c;
 c++;
    while(n > 0 || sum > 9)
    {
        if(n == 0)
        { c++;
            n = sum;
            sum = 0;
        }
        sum += n % 10;
        n /= 10;
    }
    return c;
}

int main()
{ int t;
  cin>>t;
  while(t--)
  {  ll n,d,D,N,a;
    ll ans[1000]={0},m1=19,k=0,f=0;
    ll freq[1000]={0};
    ll ans1,ans2;
    bool count[10];
    for(int i=0;i<10;i++)
    count[i]=false;
    cin>>n>>d;
    N=n;
    D=d;
      n=n%9;
      d=d%9;
      a=n;
      if(n==0)
      {n=9;
        a=9;
      }
      if(d==0)
      {d=9;
      }
      ans[k]=n;
      freq[k]=0;
      while(n!=1)
      {k++;
      while(n<10)
      { n+=d;
       f++;
     }
     n=n%9;
     if(n%9==0)
     n=9;
     ans[k]=n;
     freq[k]=f;
     if(!count[n])
     count[n]=true;
     else
     break;
      }
      int p;
     for(int i=0;i<=k;i++)
      {
        if(m1>ans[i])
        {m1=ans[i];
          p=i;
        }
      }
       if(m1==a)
       {ans1=a;
         ans2=digSum(N);
       }
       else
       {
         ans1=m1;
         ans2=freq[p]+digSum(N+D*freq[p]);
       }
     cout<<ans1<<" "<<ans2<<endl;
   }

}
