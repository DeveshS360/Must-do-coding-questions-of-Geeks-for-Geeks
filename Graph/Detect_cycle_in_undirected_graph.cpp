//Its a functional problem
// adj is adjacency list, V is number of vertices
/*Approach: We solve this problem by a parent apporach, we set
            parent for source vertex as -1 and we do a DFS, if
            we find any vertex who is visited earlier and we are 
            once again on that vertex and this vertex is not the
            parent, then we say there is a cycle in the graph
            */

void dfs(vector<int> adj[],int vis[],int s,int &res,int parent)
    {
        
        if(vis[s]==1 )
            return;
        vis[s]=1;
        for(auto x:adj[s]){
            if(vis[x]==1 && x!=parent)
                res=0;
            else
                dfs(adj,vis,x,res,s);
            
        }
        
    }
bool isCyclic(vector<int> adj[], int V)
{
    int vis[V];
    memset(vis,0,sizeof(vis));
    int res=1;
    for(int i=0;i<V;i++)
    {   
        int parent=i;
        if(vis[i] == 0) dfs(adj,vis,i,res,-1);
    }
    if(res==0)
        return true;
    return false;
    
   // Your code here
   
}
