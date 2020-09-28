/*
Problem link:  https://atcoder.jp/contests/dp/tasks/dp_a
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
 
int main()
{
    int n;
    cin>>n;
    
    int h[n+1];
    
    for(int i=1;i<=n;i++)
    cin>>h[i];
    
    int dp[n+1];
    
    dp[1]=0;
    dp[0]=0;
    dp[2]=abs(h[2]-h[1]);
    for(int i=3;i<=n;i++)
    {
        dp[i]=min(dp[i-1]+abs(h[i-1]-h[i]),dp[i-2]+abs(h[i-2]-h[i]));
    }
    
    cout<<dp[n];
    return 0;
}
