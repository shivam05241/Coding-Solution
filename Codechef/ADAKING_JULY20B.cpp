#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,a=0;
       cin>>n;
       
       for(int i=0;i<8;i++)
       {
           for(int j=0;j<8;j++)
           {
               if(a==0)
               cout<<"O";
               else if(a<n)
               cout<<".";
               else
               cout<<"X";
               
               a++;
           }cout<<"\n";
       }
       cout<<"\n";
    
       
   }

    return 0;
}
