#include <bits/stdc++.h>
#define ll unsigned long long int 

using namespace std;

ll power(ll x, ll y, ll p)  
{  
    ll res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
} 

int main()
{
   int t;
   cin>>t;
   for(int test=1;test<=t;test++)
   {
       cout<<"Case #"<<test<<": ";
       int n,count=0;
       cin>>n;
       char a[3][n+1];
       bool temp=0;
       for(int i=0;i<3;i++)
       {
           for(int j=0;j<n;j++)
           {
                cin>>a[i][j];
                if(i==1&&a[i][j]=='#')
                temp=1;
           }
       }
       a[0][n]='#';
       a[1][n]='#';
       a[2][n]='.';
       if(a[0][0]=='#'||a[2][n-1]=='#'||n%2==1)
       temp=1;
       bool tempp=0;
       if(temp)
       cout<<"0\n";
       else
       {
                for(int j=1;j<n;j+=2)
                {
                    bool ok=0,okk=0;
                    if(j+1>n)
                    break;
                    if(a[0][j]=='.'&&a[0][j+1]=='.')
                    {
                        ok=1;
                    }
                    
                   if(a[2][j]=='.'&&a[2][j+1]=='.')
                   {
                        okk=1;
                   }
                   if(ok==1&&okk==1)
                   count++;
                   if(ok==0&&okk==0)
                   {
                       tempp=1;
                       break;
                    }
                }
            if(tempp==1)
            cout<<"0\n";
            else
            {
                unsigned long long int ans=power(2,count,1000000007);
                cout<<ans%1000000007<<"\n";
            }
       }
       
   }
   
   return 0;
}