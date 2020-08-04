#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,l=0;
        cin>>n;
        
        int a[n][n];
        long long int p=1;
        
        for(int i=0;i<n;i++)
        {
            if(l==0)
            {
                for(int j=0;j<n;j++)
                {
                    a[i][j]=p;
                    
                    p++;
                }
               
                
            }
            if(l==1)
            {
               for(int j=n-1;j>=0;j--)
                {
                    a[i][j]=p;
                   
                    p++;
                }
                
                
            }
            
            if(l==0)
            l=1;
            else
            l=0;
        }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                {
                    cout<<a[i][j]<<" ";
                }
                cout<<"\n";
        }
        
    }
	return 0;
}
