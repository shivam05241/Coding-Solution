#include <iostream>
#include<map>
using namespace std;

int main() {
    int t;
     map<int,int >m;
    cin>>t;
    while(t--)
    {
        
        int n,temp=0;
        cin>>n;
        
        int a[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        for(int i=0;i<n;i++)
        { 
            if(a[i]==10)
            {
                if(m[5]>=1)
                m[5]--;
                else
                {
                    temp=1;
                    break;
                }
            }
            
            if(a[i]==15)
            {
                if(m[10]>=1)
                m[10]--;
                else 
                {
                    if(m[5]>=2)
                    m[5]-=2;
                    else
                    {
                        temp=1;
                        break;
                    }
                }
            }
            
            m[a[i]]++;
            
            //cout<<m[5]<<" "<<m[10]<<" "<<m[15]<<"\n";
        }
        
        if(temp==1)
        cout<<"NO\n";
        else
        cout<<"YES\n";
        m.clear();
        
    }
	return 0;
}
