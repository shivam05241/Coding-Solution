#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool cmp(pair<ll, ll>& a, pair<ll,ll>& b) 
{ 
    return a.first < b.first; 
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<ll>v;
    map<ll,ll>m;
   int t;
   cin>>t;
   while(t--)
   {
       ll n,x;
       cin>>n>>x;
       ll a[n],b[n];
       for(ll i=0;i<n;i++)
       cin>>b[i];
       
       sort(b,b+n);
       ll j=0,c=0;
       for(ll i=0;i<n;i++)
       {
           if(b[i]>=x||b[i]*2>=x)
           {
               a[j]=b[i];
               j++;
           }
           else
           {
               c++;
           }
        }       
      ll count=0;
      count+=c;
            for(ll i=0;i<j;i++) 
            {
                ll b=a[i];
                b-=x;
                if(b<=0)
                {
                    x=a[i]*2;
                    //a[i]=0;
                }
                else
                {
                    i--;
                    x*=2;
                }
                count++;
            }
       cout<<count<<"\n";
       
        
   }

    return 0;
}
