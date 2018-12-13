#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    double x[n],y[n],r[n];
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i]>>r[i];

    double m1[n][n],m2[n][n],cc,r1,r2,u=0;
    vector<pair<double, double> > v;
    vector<pair<double, double> >:: iterator it;

    for(int i=0;i<n-1;i++)
    {   
        for(int j=i+1;j<n;j++)
        {
            cc=((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            cc=sqrt(cc);

            if(cc>abs(r[i]-r[j])&&cc<abs(r[i]+r[j]))
            {   
                m1[i][j]=0;
                m2[i][j]=abs(cc+r[i]+r[j]);
                v.push_back(make_pair(m1[i][j],m2[i][j]));
            }
            else if(cc>=(r[i]+r[j]))
            {
                m1[i][j]=abs(cc-r[i]-r[j]);
                m2[i][j]=abs(cc+r[i]+r[j]);
                v.push_back(make_pair(m1[i][j],m2[i][j]));
            }
            else if(abs(r[i]-r[j])>=cc)
            { 
                if((x[i]==x[j])&&(y[i]==y[j]))
                {
                    m1[i][j]=m2[i][j]=abs(r[i]-r[j]);
                    v.push_back(make_pair(m1[i][j],m2[i][j]));
                }
                else
                {   
                    r1=max(r[i],r[j]);
                    r2=min(r[i],r[j]);
                    m1[i][j]=r1-cc-r2;
                    m2[i][j]=abs(cc+r[i]+r[j]);
                    v.push_back(make_pair(m1[i][j],m2[i][j]));
                }
            }
        }
    }
    sort(v.begin(), v.end());

    while(q--)
    {
        int k,high=v.size()-1,low=0,mid,p;
        long int c=0;
        cin>>k;
        mid=(low+high)/2;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(v[mid].first>k)
            {
                high = mid-1;
            }
            else if(v[mid].first<k)
            {
                low=mid+1;
            }
            else{
                low = mid+1;
            }
        }
        p = mid;
        for(it=v.begin();it!=v.begin()+p+1;it++)
        {
            if(it->second>=k&&it->first<=k)
            c++;
        }
        cout<<c<<endl;
    }
    return 0;
}