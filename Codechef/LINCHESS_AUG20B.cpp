#include <bits/stdc++.h>
#define ll long long int

using namespace std;
int main()
{
   int t;
   cin>>t;
   
   while(t--)
   {
       bool temp=0;
       ll value=1000000009;
       ll n,k,num=0;
       cin>>n>>k;
       
       ll a[n];
       for(int i=0;i<n;i++)
       {
           cin>>a[i];
           
           if(k%a[i]==0)
           {
               temp=1;
               if(k/a[i]<value)
               {
                   value=k/a[i];
                   num=i;
               }
           }
       }
       if(temp)
       cout<<a[num]<<"\n";
       else
       cout<<"-1\n";
   }
   
   return 0;
}
