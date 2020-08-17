#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
   int t;
   cin>>t;
   
   while(t--)
   {
       string s,p;
       cin>>s>>p;
       map<char,ll>ss;
       set<char>s1;

       for(ll i=0;i<s.length();i++)
       {
           ss[s[i]]++;
           s1.insert(s[i]);
       }
       for(ll i=0;i<p.length();i++)
       {
            ss[p[i]]--;
            s1.insert(p[i]);
       }

           string ans="",ans1=""; 
           
       for(char j:s1)
       {
           if(j==p[0])
           ans1+=p;
         
               while(ss[j]>0)
               {
                   ans+=j;
                   ans1+=j;
                    ss[j]--;
               }
           
           if(j==p[0])
           {
               ans+=p;
           }
       }
       
       cout<<min(ans1,ans)<<"\n";
   }
   
   return 0;
}
