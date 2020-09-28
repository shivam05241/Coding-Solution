/*
Problem link: https://atcoder.jp/contests/dp/tasks/dp_d
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main()
{
    int n,W;
    cin>>n>>W;
    ll w[n+1]={0},v[n+1]={0};
    
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
    }
    
    ll dp[n+1][W+1]={0};
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0||j==0)
            dp[i][j]=0;
            else if(j<w[i])
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                if((j-w[i])>=0)
                dp[i][j]=max(v[i]+dp[i-1][j-w[i]],dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][W];
    return 0;
}
