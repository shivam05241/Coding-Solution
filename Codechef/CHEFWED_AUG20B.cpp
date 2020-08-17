#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#define mp make_pair
#define LLONG_MAX 1e18
#define pb push_back
#define pf push_front
#define pu push
#define po pop

#define ll long long int
#define mod 1000000007
using namespace std; 

ll solve()
{
    ll n,k;
	    cin>>n>>k;
	    map<ll,ll>m;
	    ll a[n+1];
        

	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	  ///////////////////  dup table  ///////////////////////////
        ll dup_table[n+1][n+1]={{0}};   // dup_table is duplicates table , calculate no of duplicate in range
        
        for(int i=0;i<n+1;i++)
	    for(int j=0;j<n+1;j++)
	    dup_table[i][j]=0;
	    
        for(ll i=0;i<n;++i)
        {
            for(ll j=i;j<n;++j)
            {
                m[a[j]]++;
                
                if(j==0)
                dup_table[i][j]=0;
                else
                dup_table[i][j]=dup_table[i][j-1];

                    if(m[a[j]]==2)
                    dup_table[i][j]+=2;
                    else if(m[a[j]]>2)
                    dup_table[i][j]+=1;
                   
            }
            m.clear();
            
        }
        
        ///////////////////////  dup table end  //////////////////////
        
	    ll dp[101][1001]={{0}};
	    for(int i=0;i<101;i++)
	    for(int j=0;j<101;j++)
	    dp[i][j]=0;

        for(ll i=1;i<=n;i++)
        {
            dp[1][i]=dup_table[0][i-1];
        }
        
        for(int i=2;i<=100;++i )
        dp[i][1]=0;

        for(ll i=2;i<=100;++i)
        {
            for(ll j=2;j<=n;++j)
            {
                ll optimal_ans=LLONG_MAX;
                for(ll kk=1;kk<j;++kk)
                {
                    optimal_ans=min(optimal_ans,dp[i-1][kk]+dup_table[kk][j-1]);
                }
                dp[i][j]=optimal_ans;
            }
        }
        ll ans=LLONG_MAX;
        for(int i=1;i<=100;++i)
        {
            ans=min(ans,i*k+dp[i][n]);
        }
        return ans;
}
int main() 
{ 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
    for(int i=0;i<t;i++)
    cout<<solve()<<"\n";
	return 0; 
} 
