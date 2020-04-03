#include <bits/stdc++.h>
using namespace std;

//This is very nice problem which seems to be very hard,
// but could be easily solved by converting a 2D graph to 1D graph
// and using BFS

int main() {
    int q;cin>>q;
    while(q--)
        {
            int n;cin>>n;
            int arr[31];
            int N=30;
            memset(arr,-1,sizeof(arr));
            for(int i=0;i<n;i++)
                {   
                    int a,b;
                    cin>>a>>b;
                    arr[a]=b;
                }
                
            queue<pair<int,int>> q;
            q.push({0,1});
            bool vis[N+1];
            memset(vis,false,sizeof(vis));
            int res=-1;
            while(!q.empty())
                {
                    
                    auto p=q.front();
                    
                    int i=p.second;
                    vis[i]=true;
                    int dis=p.first;
                    q.pop();
                    if(i==N)
                        {
                            res=dis;
                            break;
                        }
                    for(int j=i+1;j<=i+6  && j<=N;j++)
                        {
                            if(vis[j]==false)
                                {
                                    if(arr[j]!=-1)
                                        q.push({dis+1,arr[j]});
                                    else
                                        q.push({dis+1,j});
                                }
                                
                        }
                }
                
            cout<<res<<endl;
                
            
        }
	//code
	return 0;
}