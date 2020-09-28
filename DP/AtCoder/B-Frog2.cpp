/*
Problem link: https://atcoder.jp/contests/dp/tasks/dp_b
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main()
{
    int n,k;
    cin>>n>>k;
    
    ll h[n+1];
    
    for(int i=1;i<=n;i++)
    cin>>h[i];
    ll dp[n+1];
    
    for(int i=1;i<=n;i++)
    dp[i]=1e9;
    
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if((i-j)<1)
            break;
            
            dp[i]=min(dp[i],dp[i-j]+abs(h[i-j]-h[i]));
        }
    }
   cout<<dp[n];
    return 0;
}
