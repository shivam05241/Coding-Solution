#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   int t;
   cin>>t;
   for(int limit=1;limit<=t;limit++)
   {
       cout<<"Case #"<<limit<<": "; 
       
       long int n;
       cin>>n;
       
       char a[n+1];
       map<char,long int>m;
       for(long int i=0;i<n;i++)
       {
           cin>>a[i];
           m[a[i]]++;
       }
       //cout<<(m['B']+m['A'])<<" "<<(m['B']-m['A'])<<" ";
       if(abs(m['B']-m['A'])==1)
       cout<<"Y\n";
       else
       cout<<"N\n";
       
   }
   
   return 0;
}
