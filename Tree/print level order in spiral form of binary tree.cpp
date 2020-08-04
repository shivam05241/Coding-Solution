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
int height(node* root)
{
    if(root==NULL)
    return 0;
    
    int heightl=height(root->left);
    int heightr=height(root->right);
    return max(heightl,heightr)+1;
}
void printlevel1(node* root,int level)
{
    if(root==NULL)
    return;
    
    if(level==1)
    cout<<root->data<<" ";
    
    printlevel1(root->left,level-1);
    printlevel1(root->right,level-1);
}
void printlevel2(node* root,int level)
{
    if(root==NULL)
    return;
    
    if(level==1)
    cout<<root->data<<" ";
    
    printlevel2(root->right,level-1);
    printlevel2(root->left,level-1);
}

void level_order_in_Spiral_form(node *root)
{
    int h=height(root);
    
    int t=1;
    for(int i=1;i<=h;i++)
    {
        if(i%2==0)
        printlevel1(root,i);
        else
        printlevel2(root,i);
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
    level_order_in_Spiral_form(root);

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
