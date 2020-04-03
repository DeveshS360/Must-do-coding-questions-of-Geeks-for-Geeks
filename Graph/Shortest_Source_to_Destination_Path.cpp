#include <bits/stdc++.h>
using namespace std;

//Approach:
//         This problem could be solved very easily be applying BFS on the 
//         array rather than making graph from the nodes.

int main() {
    int q;cin>>q;
    while(q--)
        {
            int n,m;cin>>n>>m;
            vector<int> arr[n];
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    {
                        int x;cin>>x;
                        arr[i].push_back(x);
                    }
            vector<bool> vis[n];
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    vis[i].push_back(false);
            vector<int> dis[n];
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    dis[i].push_back(-1);
            queue<pair<int,int>> q;
            
            if(arr[0][0]==1){
                q.push({0,0});
                dis[0][0]=0;
            }
            while(!q.empty())
                {
                    auto p=q.front();q.pop();
                    int a=p.first,b=p.second;
                    vis[a][b]=true;
                    if(a-1>=0 && vis[a-1][b]==false && arr[a-1][b]==1){
                        q.push({a-1,b});
                        dis[a-1][b]=dis[a][b]+1;
                    }
                    if(a+1<=n && vis[a+1][b]==false && arr[a+1][b]==1){
                        q.push({a+1,b});
                        dis[a+1][b]=dis[a][b]+1;
                    }
                    if(b-1>=0 && vis[a][b-1]==false && arr[a][b-1]==1){
                        q.push({a,b-1});
                        dis[a][b-1]=dis[a][b]+1;
                    }
                    if(b+1<=m && vis[a][b+1]==false && arr[a][b+1]==1){
                        q.push({a,b+1});
                        dis[a][b+1]=dis[a][b]+1;
                    }
                    
                        
                }
            
            int x,y;cin>>x>>y;
            if(dis[x][y]==-1)
                cout<<"-1"<<endl;
            else
                cout<<dis[x][y]<<endl;
        }
	//code
	return 0;
}