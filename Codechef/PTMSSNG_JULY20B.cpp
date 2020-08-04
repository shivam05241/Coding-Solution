#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<ll,ll>m,o;
   int t;
   cin>>t;
   while(t--)
   {
       ll n;
       cin>>n;
       ll a,b;
       for(int i=0;i<4*n-1;i++)
       {
           cin>>a>>b;
           m[a]++;
           o[b]++;
       }
       for(auto i:m)
       {
           if(i.second%2!=0)
           {
               cout<<i.first<<" ";
               break;
           }
       }
       for(auto j:o)
       {
           if(j.second%2!=0)
           {
               cout<<j.first<<"\n";
               break;
           }
       }  
       m.clear();
       o.clear();
   }

    return 0;
}
