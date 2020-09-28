/*
Problem link: https://atcoder.jp/contests/dp/tasks/dp_c
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main()
{
    int n;
    cin>>n;
    
    ll h[n+1][4];
    
    for(int i=1;i<=n;i++)
    cin>>h[i][1]>>h[i][2]>>h[i][3];
    
    ll dp[n+1][4];
    
    dp[1][1]=h[1][1];
    dp[1][2]=h[1][2];
    dp[1][3]=h[1][3];
    
    for(int i=2;i<=n;i++)
    {
        dp[i][1]=h[i][1]+max(dp[i-1][2],dp[i-1][3]);
        dp[i][2]=h[i][2]+max(dp[i-1][1],dp[i-1][3]);
        dp[i][3]=h[i][3]+max(dp[i-1][1],dp[i-1][2]);
    }
   cout<<max(dp[n][1],max(dp[n][2],dp[n][3]));
    
    

    return 0;
}
