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
       long int a[n],b[n];
       ll sum=0,sum1=0,c=0,d=0;
       
       for(int i=0;i<n;i++)
       {
           cin>>a[i]>>b[i];
           while(a[i]>0)
           {
               sum+=a[i]%10;
               a[i]/=10;
           }
           while(b[i]>0)
           {
               sum1+=b[i]%10;
               b[i]/=10;
           }
           if(sum>sum1)
           c++;
           else if(sum<sum1)
           d++;
           else
           {
               c++;
               d++;
           }
           sum=0;
           sum1=0;
           
       }
            if(c>d)
            cout<<"0 "<<c<<"\n";
            else if(c<d)
            cout<<"1 "<<d<<"\n";
             else
             cout<<"2 "<<c<<"\n";
    
       
   }

    return 0;
}
