/*The function should return a string denoting the
order of the words in the Alien Dictionary */

/*Approach: Create a graph of size of number of characters in the 
            alien dictionary. Then iterate through the strings one 
            by one and add an edge to the first characters not matching
            in two adjacent strings, adding to the adjacency list of character
            of the first string.
            Then just do the topological soritng of this graph
            */

void dfs(int s,map<char,vector<char>> &adj,map<char,bool> &vis,vector<char> &res)
    {
        if(vis[s]==true)
            return;
        vis[s]=true;
        for(auto x:adj[s])
            dfs(x,adj,vis,res);
        res.push_back(s);
    }
char* topoSort(int V, map<char,vector<char>> &adj) {
    // Your code here
    map<char,bool> vis;
    vector<char> res;
    for(auto i:adj)
        if(vis[i.first]==false)
            dfs(i.first,adj,vis,res);
    char *arr;
    arr=new char[res.size()];
    for(int i=0;i<res.size();i++)
        arr[res.size()-i-1]=res[i];
    return arr;
}


string printOrder(string dict[], int n, int k) {
    
    map<char,vector<char>> graph;

    for(int i=0;i<n-1;i++)
        {
            if(dict[i].size()<=dict[i+1].size())
                {
                    for(int k=0;k<dict[i].size();k++)
                        if(dict[i][k]!=dict[i+1][k]){
                            graph[dict[i][k]].push_back(dict[i+1][k]);
                            break;
                        }
                        
                }
            else
                {
                    for(int k=0;k<dict[i+1].size();k++)
                        if(dict[i][k]!=dict[i+1][k]){
                            graph[dict[i][k]].push_back(dict[i+1][k]);
                            break;
                        }
                }
            
                
        }

    char *res=topoSort(k,graph);
    string s=res;
    //cout<<s<<endl;
    return s;
    // Your code here
}