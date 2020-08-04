#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct node
{
    int data;
    int distance;
    node *left,*right;
    node(int key)
    {
        data=key;
        distance=INT_MAX;
        left=right=NULL;
    }
};

void diagonal(node* root,int val,auto &m)
{
    if(root==NULL)
    return;

    m[val].push_back(root->data);

    diagonal(root->left,val+1,m);
    diagonal(root->right,val,m);
}
void diagonal_order(node* root)
{
    map<int,vector<int>>m;
    int val=0;
    diagonal(root,val,m);

    for(auto i:m)
    {
        auto j=i.second;
        for(auto k:j)
        cout<<k<<" ";
        cout<<"\n";
    }
}
node* insertion(node* root,int key)
{
    if(root==NULL)
    {
        node* temp=new node(key);
        return temp;
    }

    queue<node*>q;
    q.push(root);

    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();

        if(temp->left)
        q.push(temp->left);
        else
        {
             node* temp1=new node(key);
             temp->left=temp1;
             break;
        }

        if(temp->right)
        q.push(temp->right);
        else
        {
             node* temp1=new node(key);
             temp->right=temp1;
             break;
        }
    }
    return root;
}
void solve()
{
	int n;
    cin>>n;
    node* root=NULL;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        root=insertion(root,a);
    }
    int val;
    cin>>val;
    //const int level=1;
    //nth_node(root,val);
    diagonal_order(root);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for(int test=1;test<=t;test++)
    {
        cout<<"Case #"<<test<<": ";
        solve();
        cout<<"\n";
    }
   
    return 0;
}
