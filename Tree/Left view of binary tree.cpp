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
void left_view(node* root)
{
    if(root==NULL)
    return ;

    int dis=0;
    map<int,int>m;

    queue<node*>q;
    root->distance=dis;
    q.push(root);

    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();

        dis=temp->distance;
        if(m[dis]==0)
        m[dis]=temp->data;

        if(temp->left)
        {
            temp->left->distance=dis+1;
            q.push(temp->left);
        }
        if(temp->right)
        {
            temp->right->distance=dis+1;
            q.push(temp->right);
        }
    }

    for(auto i:m)
    {
        cout<<i.second<<" ";
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
    left_view(root);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE 
    freopen("__input.txt", "r", stdin); 
    freopen("__output.txt", "w", stdout); 
    #endif
    
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
