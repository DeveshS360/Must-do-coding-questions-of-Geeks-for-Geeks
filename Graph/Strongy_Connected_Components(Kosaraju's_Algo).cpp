/*Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/

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

int kosaraju(int V, vector<int> adj[])
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
                scc++;
            }
        }
        
    return scc;
    // Your code here
    

}