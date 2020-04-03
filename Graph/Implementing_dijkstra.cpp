// This is a functional problem
/*Function to implement Dijkstra
*   graph: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/



void dijkstra(vector<vector<int>> graph, int src, int V)
{
    int dis[V];
    for(int i=0;i<V;i++)
        dis[i]=INT_MAX;
    
    dis[src]=0;
    set<int> s;
    set<pair<int,int>> ms;
    ms.insert({dis[src],src});
    while(s.size()!=V)
        {
            pair<int,int> p=*ms.begin();
            int a=p.second;
            ms.erase(ms.begin());
            for(int j=0;j<V;j++)
                if(graph[a][j])
                    {
                        if(dis[j]>dis[a]+graph[a][j]){
                            dis[j]=dis[a]+graph[a][j];
                            ms.insert({dis[j],j});
                            
                        }
                            
                    }
            
            s.insert(a);
            
        }
    for(int i=0;i<V;i++)
        cout<<dis[i]<<" ";
    // Your code here
}