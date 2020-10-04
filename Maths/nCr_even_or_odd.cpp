/*
this code is to check if combination is even or odd in O(log2(n)) , it will even work for n>pow(10,10)=10000000000  
*/

#include<bits/stdc++.h> 
#define ll long long int
using namespace std; 

int pascal[4][4];

void pascal_ncr()     // creating pascal triangle till n=2 for O(1) access of nCr if n<=2
{
    pascal[0][0]=1;
    pascal[1][0]=1;
    pascal[1][1]=1;
    pascal[2][0]=1;
    pascal[2][1]=2;
    pascal[2][2]=1;
}

int nCr(ll n, ll r) 
{ 
  if (r==0) 
	return 1; 

    int ni = n%2, ri = r%2; 
    
    if(pascal[ni][ri]%2)                                      // if pascal[ni][ri] is odd=1 return nCr(n/2, r/2) * (pascal[ni][ri]%2); 
    return (nCr(n/2, r/2) * (pascal[ni][ri]%2)) % 2;
    else                                                      // else pascal[ni][ri] will be 0 so multiplication will give zero as result so return zero
    return 0;
} 
   
int main() 
{ 
    ios::sync_with_stdio(0);                                   // FastIO
    cin.tie(0);
    cout.tie(0);
    
    pascal_ncr();                                             // calling pascal_ncr function
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,r;
        cin>>n>>r;
        cout<<nCr(n,r)<<"\n";
    }
    
	return 0; 
} 
