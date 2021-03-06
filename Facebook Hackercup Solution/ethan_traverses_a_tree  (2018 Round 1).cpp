#include <bits/stdc++.h>

using namespace std;

  
// Graph class represents a undirected graph 
// using adjacency list representation 
class Graph 
{ 
    int V;    // No. of vertices 
  
    // Pointer to an array containing adjacency lists 
    list<int> *adj; 
  
    // A function used by DFS 
    void DFSUtil(int v, bool visited[],int arr[],int p); 
public: 
    Graph(int V);   // Constructor 
    ~Graph(); 
    void addEdge(int v, int w); 
    int connectedComponents(int arr[]); 
}; 
  
// Method to print connected components in an 
// undirected graph 
int Graph::connectedComponents(int arr[]) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    int p=0;
    for(int v = 0; v < V; v++) 
        visited[v] = false; 
  
    for (int v=0; v<V; v++) 
    { 
        if (visited[v] == false) 
        { 
            // print all reachable vertices 
            // from v 
            DFSUtil(v, visited,arr,p); 
                p++;
            //cout << "\n"; 
        } 
    } 
    delete[] visited; 
    p--;
    return p;
} 
  
void Graph::DFSUtil(int v, bool visited[],int arr[],int p) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
    //cout << v << " "; 
    arr[v]=p;
  
    // Recur for all the vertices 
    // adjacent to this vertex 
    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFSUtil(*i, visited,arr,p); 
} 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
Graph::~Graph() 
{ 
    delete[] adj; 
} 
  
// method to add an undirected edge 
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
}

struct node
{
    int data;
    node *left,*right;
    node(int key)
    {
        data=key;
        left=right=NULL;
    }
};
void printPreorder(struct node* temp,vector<int >&v) 
{ 
    if (temp == NULL) 
    {
        return; 
    }
    v.push_back(temp->data);
    //cout << temp->data << " "; 
    // first recur on left subtree 
    printPreorder(temp->left,v); 
   
    printPreorder(temp->right,v); 
  
   
    // now deal with the node 
     
}
void printPostorder(struct node* temp,vector<int >&vv) 
{ 
    if (temp == NULL) 
    {
        return; 
    }
  
    // first recur on left subtree 
    printPostorder(temp->left,vv); 
   
    printPostorder(temp->right,vv); 
    vv.push_back(temp->data);
     //cout << temp->data << " "; 
    // now deal with the node 
     
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
       
       int n,k;
       cin>>n>>k;
       Graph g(n+1);
       vector<node*>v;
       for(int i=1;i<=n;i++)
       {
           node* temp=new node(i);
           v.push_back(temp);
       }
       node* root=v[0];
       for(int i=0;i<n;i++)
       {
           int l,r;
           cin>>l>>r;
           if(l!=0)
           v[i]->left=v[l-1];
           else
           v[i]->left=NULL;
           
           if(r!=0)
           v[i]->right=v[r-1];
           else
           v[i]->right=NULL;
           
       }
        vector<int >vvv,vv;
        //cout<<"\n";
        printPostorder(root,vvv);
       //cout<<"\n";
        printPreorder(root,vv);
       //cout<<"\n";
        int limit=vv.size();
        
        int arr[limit+1];
        for(int i=0;i<=limit;i++)
        {
            arr[i]=-1;
        }
       // cout<<"\n";
        for(int i=0;i<limit;i++)
        {
            g.addEdge(vv[i],vvv[i]); 
        }
        int val=g.connectedComponents(arr); 
        
        if(val<k)
        cout<<"Impossible";
        else
        {
            for(int i=1;i<=limit;i++)
            {
                if(arr[i]<=k)
                cout<<arr[i]<<" ";
                else
                cout<<k<<" ";
            }
        }
        cout<<"\n";
   }
   
   return 0;
}
