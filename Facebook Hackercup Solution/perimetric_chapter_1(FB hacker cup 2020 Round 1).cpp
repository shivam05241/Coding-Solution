#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main()
{
    
   int t;
   cin>>t;
   for(int limit=1;limit<=t;limit++)
   {
       cout<<"Case #"<<limit<<": "; 
       
        long int n,k,w;
        cin>>n>>k>>w;

        vector<ll> l,h;
        ll l_temp,h_temp;
        for(ll i=0;i<k;i++)
        {
            cin>>l_temp;
            l.push_back(l_temp);
        }

        ll al,bl,cl,dl;
        cin>>al>>bl>>cl>>dl;

        for(ll i=k;i<n;i++)
        {
            l_temp=(((al%dl)*(l[i-2])%dl)%dl+((bl%dl)*(l[i-1])%dl)%dl+cl)%dl+1;
            l_temp%=dl;
            l.push_back(l_temp);
        }

        ll ah,bh,ch,dh;
        for(ll i=0;i<k;i++)
        {
            cin>>h_temp;
            h.push_back(h_temp);
        }

        cin>>ah>>bh>>ch>>dh;
        for(ll i=k;i<n;i++)
        {
            h_temp=(((ah%dh)*(h[i-2])%dh)%dh+((bh%dh)*(h[i-1])%dh)%dh+ch)%dh+1;
            h_temp%=dh;
            h.push_back(h_temp);
        }


        vector<ll> perimeter;
        ll peri=0;
        ll maxx=0;
        ll ans=1;
        perimeter.push_back(2*(h[0]+w)%mod);
        ans*=perimeter[0];
        ans%=mod;
        peri=perimeter[0];
        for(ll i=1;i<n;i++)
        {
            maxx=0;
            if((l[i]-l[i-1])<=w)
            {
                maxx=0;
                for(ll j=i-1;j>=0;j--)
                {
                    if(l[j]<(l[i]-w))
                    break;

                    maxx=max(maxx,h[j]); 
                }
                if(h[i]<=maxx)
                peri+=2*(abs(l[i]-l[i-1]));
                else
                peri+=2*(abs(l[i]-l[i-1]))+2*(abs(h[i]-maxx));

                peri%=mod;

            }
            else
            {
                peri+=2*(w+h[i]);
                peri%=mod;
            }

            perimeter.push_back(peri%mod);
            ans*=perimeter[i];
            ans%=mod;
        }

        cout<<ans%mod<<"\n";
       
   }
   
   return 0;
}