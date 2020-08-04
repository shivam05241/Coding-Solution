
#include <iostream>
#define N 62
int count[N],a[N][N],row[N];

using namespace std;

int input(int x1,int y1,int x2,int y2)
{
    int l;
    cout<<"1 "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl<<flush; //row a1  to column b1
    cin>>l;
  
    return l;
}

int find(int i,int low,int high,int value,int n)
{
    
    if(value==0)
    return 0;
    
    if(value==(high-low+1))
    {
        for(int j=low;j<=high;j++)
        a[i][j]=1;
        return 0;
    }
    
    if(low<high)
    {
    int mid=(low+high)/2;
    
    int value1=input(i,low,n,mid);
    int value2;
    if(i+1<=n)
    value2=input(i+1,low,n,mid);
    else
    value2=0;
    int value3=value1-value2;
    find(i,low,mid,value3,n);
    find(i,mid+1,high,value-value3,n);
    }
    
    return 0;
    
    
}

int solve()
{
    int n,p,i,j,k;
    cin>>n>>p;
    
    for(i=1;i<=n;i++)
    {
    
    count[i]=0;
    row[i]=0;
    for(int j=1;j<=n;j++)
    a[i][j]=0;
    }
    
    
    for(i=1;i<=n;i++)
    {
        cout<<"1 "<<i<<" 1 "<<n<<" "<<n<<endl;
        cin>>k;
        count[i]=k;
        
        if(k==0)
        break;
        
        if(k==(n*(n-i+1)))
        {
            for(int j=i;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    a[j][k]=1;
                }
                count[j]=n*(n-j+1);
            }
            
            break;
        }
    }
    
    for(j=2;j<=n;j++)
    {
       
        row[j-1]=count[j-1]-count[j];
        
        if(j==n)
        row[n]=count[j];
    }
    
    
    for(int i=1;i<=n;i++)
    {///cout<<row[i]<<" ";
        if(row[i]!=0)
        {
             find(i,1,n,row[i],n);
        }
        
    }
    
    cout<<"2"<<endl;
    for(int ii=1;ii<=n;ii++)
    {
        for(int jj=1;jj<=n;jj++)
        {
            cout<<a[ii][jj]<<" "<<flush;
        }cout<<endl<<flush;
    }
    
    int mm;
    cin>>mm;
    if(mm==-1)
    return 1;
    else
    return 0;
    
}

int main()
{
    int t;
    cin>>t;
    
    
    while(t--)
    {
        //a[N][N]={0};
        //row[N]={0};
        int s=solve();
        if(s==1)
        return 0;
        else
        continue;
    }

    return 0;
}
