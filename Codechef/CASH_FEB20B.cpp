#include <stdio.h>

int main(void) {
	unsigned long long int n,a,b,p,sum;
	scanf("%d",&n);
	for(long long int i=0;i<n;i++)
	{sum=0;
	    scanf("%d%d",&a,&b);
	    long long int c[1000000];
	    for(long long int j=0;j<a;j++)
	    {
	        scanf("%d",&c[j]);
	    }
	    for(long long int j=0;j<a;j++)
	    {
	       sum=sum+c[j]; 
	    }
	    
	    if(b!=0)
	    p= sum%b;
	    printf("%d\n",p);    
	}
	return 0;
}

