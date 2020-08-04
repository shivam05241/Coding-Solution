#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
       unsigned long long int ts,p,count=0,count2=0,q;
        cin>>ts;
        
        if(ts%2==1)
        {
            count=ts/2;
            cout<<count<<"\n";
        }
        else
        {
            p=ts;
            
            while(p%2==0)
            {
                count2++;
                p/=2;
            }
            p=pow(2,count2+1);
            q=ts/p;
            cout<<q<<"\n";
        }
        
    }
	return 0;
}
