//[https://practice.geeksforgeeks.org/problems/nmeetings-in-one-room/0 ]


#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

bool cmp(pair<int,pair<int,int>>f,pair<int,pair<int,int>>s)
{
    return (f.second).second<(s.second).second;
}

int main()
{
   int t;
   cin>>t;
   
   while(t--)
   {
       int n;
       cin>>n;

        int s[n+1],e[n+1];

        for(int i=0;i<n;++i)
        cin>>s[i];

        for(int i=0;i<n;++i)
        cin>>e[i];

        vector<pair<int,pair<int,int>>>v;

        for(int i=0;i<n;++i)
        {
            pair<int,int>p=make_pair(s[i],e[i]);
            pair<int, pair<int,int>>pp=make_pair(i+1,p);
            v.push_back(pp);
        }

        sort(v.begin(),v.end(),cmp);
        
        int size_v=v.size();
        vector<int>ans;
        int i,j;
        for(int i=0;i<size_v;i++)
        {
            ans.push_back(v[i].first);
            for( j=i+1;j<size_v;j++)
            {
                if((v[j].second).first>=(v[i].second).second)
                break;
            }
            i=j-1;
        }
        for(auto i:ans)
        cout<<i<<" ";
        cout<<"\n";
   }
   
   return 0;
}