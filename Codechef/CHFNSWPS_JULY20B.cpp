#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<ll> vec;
    unordered_map<ll,ll>m,o;
    set<ll>s;
   int t;
   cin>>t;
   while(t--)
   {
       ll p=0;
        int n;
        cin>>n;
        ll a[n],b[n],mi=1000000007;
        for(int i=0;i<n;i++)
        {
           cin>>a[i];
           m[a[i]]++;
           s.insert(a[i]);
           mi=min(mi,a[i]);
        }
        for(int i=0;i<n;i++)
        {
           cin>>b[i];
           o[b[i]]++;
           s.insert(b[i]); 
           mi=min(mi,b[i]);
        }
        int temp=0,temp1=0;
        
        for(ll i:s)
        {
            if(m[i]!=o[i])
            {
                temp1=1;
                p=abs(m[i]-o[i]);
                if(p%2==0)
                {
                    {
                        ll qq=p/2;
                        while(qq--)
                        {
                            vec.push_back(i);
                        }
                        
                    }
                }
                else
                {
                    temp=1;
                    break;
                }
            }
        }
        if(temp==1)
            cout<<"-1\n";
        else
        {
            if(temp1==0)
            cout<<"0\n"; 
            else
            {
                sort(vec.begin(),vec.end());
                
                ll h;
                h=vec.size();
               
                 long long int sum=0;
                if(h>0)
                for(ll i=0;i<h/2;i++)
                {
                    sum+=min(mi*2,vec[i]);
                }
                cout<<sum<<"\n";
            }
        }
        
        
       m.clear();
       o.clear();
       vec.clear();
       //vec1.clear();
       s.clear();
   }

    return 0;
}
