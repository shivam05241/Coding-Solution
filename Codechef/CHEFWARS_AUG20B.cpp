#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
   int t;
   cin>>t;
   
   while(t--)
   {
       
       ll p,h;
       cin>>h>>p;
       ll k=ceil(log2(p))+1;
       double ans=p*(1-pow(0.5,k))*2;
       if(h-ans<=0)
       cout<<"1\n";
       else
       cout<<"0\n";
   }
   
   return 0;
}
