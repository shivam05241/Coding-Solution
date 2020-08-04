#include <iostream>
#include<algorithm>
#define l long int
#define li long long int
using namespace std;

int main() 
{
l t,n,q;
li c,count=0;
l a[26];

cin>>t;
while(t--)
{
    for(int i=0;i<26;i++)
    a[i]=0;
    
    cin>>n>>q;
    char b[n+1];
    for(l i=0;i<n;i++)
    {
        cin>>b[i];
        switch(b[i])
        {
            case 'a':a[0]++;break;
            case 'b':a[1]++;break;
            case 'c':a[2]++;break;
            case 'd':a[3]++;break;
            case 'e':a[4]++;break;
            case 'f':a[5]++;break;
            case 'g':a[6]++;break;
            case 'h':a[7]++;break;
            case 'i':a[8]++;break;
            case 'j':a[9]++;break;
            case 'k':a[10]++;break;
            case 'l':a[11]++;break;
            case 'm':a[12]++;break;
            case 'n':a[13]++;break;
            case 'o':a[14]++;break;
            case 'p':a[15]++;break;
            case 'q':a[16]++;break;
            case 'r':a[17]++;break;
            case 's':a[18]++;break;
            case 't':a[19]++;break;
            case 'u':a[20]++;break;
            case 'v':a[21]++;break;
            case 'w':a[22]++;break;
            case 'x':a[23]++;break;
            case 'y':a[24]++;break;
            case 'z':a[25]++;break;
        }
    }
        
        for(l j=0;j<q;j++)
        {count=0;
            cin>>c;
            for(int k=0;k<26;k++)
            {
                if(a[k]>c)
                count+=(a[k]-c);
            }
            cout<<count<<"\n";
        }
        
    
}


	return 0;
}
