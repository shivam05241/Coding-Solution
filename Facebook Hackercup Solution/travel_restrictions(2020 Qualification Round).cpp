#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
   int t;
   cin>>t;
   for(int limit=1;limit<=t;limit++)
   {
       cout<<"Case #"<<limit<<":\n"; 
       
       int n;
       cin>>n;
       
       char a[n+1],b[n+1],c[n+1][n+1];
       
       for(int i=0;i<n;i++)
       cin>>a[i];
       
       for(int i=0;i<n;i++)
       cin>>b[i];
       
       for(int i=0;i<n;i++)
       {
           for(int j=i;j<n;j++)
           {
               if(j==i)
               c[i][i]='Y';
               else
               {
                   if(b[j-1]=='Y'&&a[j]=='Y'&&c[i][j-1]=='Y')
                   c[i][j]='Y';
                   else
                   c[i][j]='N';
               }
            }
           for(int j=i-1;j>=0;j--)
           {
               if(b[j+1]=='Y'&&a[j]=='Y'&&c[i][j+1]=='Y')
                   c[i][j]='Y';
                   else
                   c[i][j]='N';
           }
       }
       
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           cout<<c[i][j];
           cout<<"\n";
       }
   }
   
   return 0;
}
