/*
                finding nth fabonicci number modulo 1e9+7 in O(8*log(n)) 
                ____shivam awsthi
                
                
                dp series
                {f[n],f[n-1]} = {{1,1},{1,0}}^(n-1) * {f[2],f[1]}
                                
 */

#include <bits/stdc++.h>
#define ll long long int 
using namespace std;


// matrix multiplication  ans=a*b
vector<vector<ll>> matrix_mul(vector<vector<ll>>a,vector<vector<ll>>b,ll mod)
{
    vector<vector<ll>>ans(2,vector<ll>(2,0));
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            ans[i][j]=0;
            for(int k=0;k<2;k++)
            {
                ans[i][j]+=a[i][k]*b[k][j];
                ans[i][j]%=mod;
            }
        }
    }
    return ans;
}


// matrix to power n modulo mod
vector<vector<ll>> mat_pow(vector<vector<ll>> a,ll n,ll mod)   
{
    ll a_size=a.size();
    vector<vector<ll>>res(a_size+1,vector<ll>(a_size+1,0));
    for(int i=0;i<=a_size;i++)
    res[i][i]=1;
    
    if(n==0)
    return res;
    
    while(n>0)
    {
        if(n&1)
        {
            res=matrix_mul(res,a,mod);
            n--;
        }
        
        if(n>0)
        a=matrix_mul(a,a,mod);
        n/=2;
    }
    
    return res;
}

ll nth_fab(ll n)
{
    if(n==0)
    return 0;
    
    vector<vector<ll>>input{{1,1},{1,0}};
    vector<vector<ll>>output;
   
    output=mat_pow(input,n-1,1000000007);
    return (output[1][0]+output[1][1])%1000000007;
}
int main()
{

    ll n;
    cin>>n;                             // enter number n
    cout<<nth_fab(n);
    
   return 0;
}

