#include <bits/stdc++.h> 
#define llu long long int 
using namespace std; 
 
double area(const vector<pair<int,int>>& fig) {
    double res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        pair<int,int> p = i ? fig[i - 1] : fig.back();
        pair<int,int> q = fig[i];
        res += (p.first - q.first) * (p.second + q.second);
    }
    return fabs(res) / 2;
}

llu cross_product(pair<int,int> O, pair<int,int> A, pair<int,int> B) 
{ 
	return (A.first - O.first) * (B.second - O.second) - (A.second - O.second) * (B.first - O.first); 
} 
 
vector<pair<int,int>> convex_hull(vector<pair<int,int>> A) 
{ 
	int n = A.size(), k = 0; 

	if (n <= 3) 
		return A; 

	vector<pair<int,int>> ans(2 * n); 
	sort(A.begin(), A.end()); 

	// Build lower hull 
	for (int i = 0; i < n; ++i) { 
		while (k >= 2 && cross_product(ans[k - 2], ans[k - 1], A[i]) <= 0) 
			k--; 
		ans[k++] = A[i]; 
	} 

	// Build upper hull 
	for (size_t i = n - 1, t = k + 1; i > 0; --i) { 
		while (k >= t && cross_product(ans[k - 2], ans[k - 1], A[i - 1]) <= 0) 
			k--; 
		ans[k++] = A[i - 1]; 
	} 

	// Resize the array to desired size 
	ans.resize(k - 1); 

	return ans; 
} 

int main() 
{ ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
	vector<pair<int,int>> points,v,c; 
	vector<pair<int,int>>::iterator it;

	// Add points 
	int n,xx,yy;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	    cin>>xx>>yy;
	    points.push_back(make_pair(xx,yy)); 
	    v.push_back(make_pair(xx,yy)); 
	    
	}
	int mmm;
	cin>>mmm;
	int p=points.size()-2;
	while(p--)
	{
    	vector<pair<int,int>> ans = convex_hull(points); 
        map<double,set<pair<int,int>>>m;
     
         for(int i=0;i<ans.size();i++)
         {vector<pair<int,int>>w;
            for(int j=0;j<points.size();j++)
            {
                if(ans[i].first==points[j].first&&ans[i].second==points[j].second)
                {
                    continue;
                }
                else
                {
                    w.push_back(make_pair(points[j].first,points[j].second));
                }
            }
                //points.erase(points.begin()+j);
                vector<pair<int,int>> ans1 = convex_hull(w);
                double ar=area(ans1);
                m[ar].insert(make_pair(ans[i].first,ans[i].second));
                //points.insert(points.begin(), make_pair(ans[i].first,ans[i].second));
            
         }
         auto itrr=((*m.begin()).second);
         c.push_back(make_pair((*itrr.begin()).first,(*itrr.begin()).second));
     
        for(int j=0;j<points.size();j++)
        if((*itrr.begin()).first==points[j].first&&(*itrr.begin()).second==points[j].second)
        {
            points.erase(points.begin()+j);
        }
        if((*m.begin()).first==0)
        break;
	}
	p=points.size();

	sort(points.begin(),points.end());
	for(int po_lo=0;po_lo<p;po_lo++)
	 c.push_back(make_pair(points[po_lo].first,points[po_lo].second));

	 for(int i=0;i<c.size();i++)
	 {
	     for(int j=0;j<v.size();j++)
	     {
	         if(c[i].first==v[j].first&&c[i].second==v[j].second)
	         {
	             cout<<j+1<<" ";
	             break;
	         }
	     }
	 }
	 
	return 0; 
} 
