#include <bits/stdc++.h>
using namespace std;

// This is a tough problem, and should be kept as hard according to me
/*Approach: First you have to make a graph containing all the lowercase characters
            You create a graph of size 26, and then add last character to first character
            adjacency list. We do this for all the strings
            And after the graph is formed, we need to check if a eulerian circuit
            is there in the graph or not.
            We check two conditions for the eulerian ciruit, first the graph should
            have only 1 strongly connected componenet,
            and second conditon that indegree and outdegree of each node should be equal.
            If both the above conditions are satisfied then there is a cycle or circle of string,
            else not.*/

bool compare(pair<int,int> p, pair<int,int> q)
    {
        return p.first>q.first;
    }

void dfs(int s,vector<int> adj[],bool vis[],int &post,vector<pair<int,int>> &p)
    {
        if(vis[s]==true)
            return;
        vis[s]=true;
        for(auto x:adj[s])
            dfs(x,adj,vis,post,p);
        p.push_back({post,s});
        post++;
        
    }
void dfs2(int s,vector<int> adj2[],bool vis[])
    {
        if(vis[s]==true)
            return;
        vis[s]=true;
        for(auto x:adj2[s])
            dfs2(x,adj2,vis);
    }

int kosaraju(int V, vector<int> adj[],int outd[])
{
    vector<int> adj2[V];
    for(int i=0;i<V;i++)
        for(auto x:adj[i])
            adj2[x].push_back(i);
    bool vis[V];
    int post=0;
    memset(vis,false,sizeof(vis));
    vector<pair<int,int>> podr;
    for(int i=0;i<V;i++)
        if(vis[i]==false)
            dfs(i,adj,vis,post,podr);
    sort(podr.begin(),podr.end(),compare);
    int scc=0;
    for(int i=0;i<V;i++)
        vis[i]=false;
    for(int i=0;i<podr.size();i++)
        {   
            if(vis[podr[i].second]==false){
                dfs2(podr[i].second,adj2,vis);
                if(outd[podr[i].second]!=0)
                    scc++;
            }
        }
        
    return scc;
    // Your code here
    

}

//The code above this a Kosaraju algorithm for finding the number of 
// strongly connected components

int main() {
    int q;cin>>q;
    while(q--)
        {
            int n;cin>>n;
            string arr[n];
            for(int i=0;i<n;i++)
                cin>>arr[i];
            vector<int> g[26];// adjecency list
            for(auto s:arr)
                g[s[0]-'a'].push_back(s[s.length()-1]-'a');// adding last character of string 
            //to first character's adjacency list
            
            int idr[26];// array to store indegree of nodes
            memset(idr,0,sizeof(idr));
            for(auto v:g)
                for(auto x:v)
                    idr[x]++;
            int outd[26];// array to store outdegree of nodes
            memset(outd,0,sizeof(outd));
            for(int i=0;i<26;i++)
                outd[i]=g[i].size();
            
            int f=1;// initially we assume to have a eulerian circuit
            if(kosaraju(26,g,outd)!=1)
               {
                   f=0;
               }
            for(int i=0;i<26;i++)
                if(idr[i]!=outd[i])
                    {
                        f=0;
                        break;
                    }
            if(f==1)
                cout<<"1"<<endl;
            else
                cout<<"0"<<endl;
            
        }
	//code
	return 0;
}