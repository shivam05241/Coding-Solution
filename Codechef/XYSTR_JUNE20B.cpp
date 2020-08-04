#include <iostream>
using namespace std;

int main() {
int t;
cin>>t;
while(t--)
{
    string a;
    cin>>a;
    
    int count=0;
    for(int i=0;i<a.length()-1;i++)
    {
       if((a[i]=='x'&&a[i+1]=='y')||(a[i+1]=='x'&&a[i]=='y'))
       {
           i++;
           count++;
       }
       
       
       
    }
    
    cout<<count<<"\n";
}
	return 0;
}
