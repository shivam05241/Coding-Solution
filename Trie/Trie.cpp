#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

struct trie
{
    bool is_end;
    trie *children[26];
    
    trie()
    {
        is_end=false;
        for(int i=0;i<26;i++)
        children[i]=NULL;
    }
};

void insert(trie* root,string key)
{
    trie* temp=root;
    
    for(int i=0;i<key.length();i++)
    {
        int index=key[i]-'a';
        if(!temp->children[index])
        {
            temp->children[index]=new trie();
        }
        temp=temp->children[index];
    }
    temp->is_end=true;
}

bool search(trie *root,string key)
{
    trie *temp=root;
    for(int i=0;i<key.length();++i)
    {
        int index=key[i]-'a';
        if(!temp->children[index])
        return false;
        temp=temp->children[index];
    }
    
    if(temp!=NULL&&temp->is_end==true)
    return true;
    return false;
}

bool isEmpty(trie* temp)
{
    for(int i=0;i<26;i++)
    {
        if(temp->children[i])
        return false;
    }
    return true;
}
trie* Tdelete(trie* temp,string key,int depth=0)
{
    if(temp==NULL)
    return NULL;
    
    if(depth==key.length())
    {
        temp->is_end=false;
        
        if(isEmpty(temp))
        {
            delete(temp);
            temp=NULL;
        }
        return temp;
    }
    
    int index=key[depth]-'a';
    temp->children[index]=Tdelete(temp->children[index],key,depth+1);
    
    if(isEmpty(temp)&&temp->is_end==false)
    {
        delete(temp);
        temp=NULL;
    }
    return temp;
    
}
int main()
{
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    trie* root=new trie();
    for(auto i:keys)
        insert(root,i);             // insert string int trie
    
    search(root,"there")?cout<<"yes\n":cout<<"no\n";            // search key string in trie
    Tdelete(root,"there");                                      // delete key string from trie
    search(root,"there")?cout<<"yes":cout<<"no";
 


    
    return 0;
}
