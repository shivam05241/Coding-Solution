#include <iostream>
using namespace std;

int main() {
long int t;
cin>>t;
while(t--)
{
    long int n,k;
    cin>>n>>k;
    long int a[n],sum=0;
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
     for(int i=0;i<n;i++)
    {
        if(a[i]>k)
        sum=sum+(a[i]-k);
    }
    cout<<sum<<"\n";
}
	return 0;
}
