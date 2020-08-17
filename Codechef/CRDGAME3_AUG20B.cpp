#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
   int t;
   cin>>t;
   
   while(t--)
   {
       ll a,b;
       cin>>a>>b;
      
       ll c,d;
       c=ceil(double(a)/9);
       d=ceil(double(b)/9);
       
       if(c>=d)
       {
           cout<<"1 "<<d<<"\n";
       }
       else
       cout<<"0 "<<c<<"\n";
       
       
   }
   
   return 0;
}
