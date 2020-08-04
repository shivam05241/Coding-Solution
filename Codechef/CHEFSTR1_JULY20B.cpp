#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
   ll t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       long int a[n];
       ll sum=0;
       cin>>a[0];
       for(int i=1;i<n;i++)
       {
           cin>>a[i];
           sum+=abs(a[i]-a[i-1])-1;
           
       }
       cout<<sum<<"\n";
       
   }

    return 0;
}
