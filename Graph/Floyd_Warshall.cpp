#include <bits/stdc++.h>
using namespace std;

//Floyd Warshall algorithm sets the shortest distance possible between
//any two nodes or vertices.
//It is a very simple algorithm which involves a concept of 
//the intermediate vertex.

int main() {
    int q;cin>>q;
    
    while(q--)
        {
            int n;cin>>n;
            int arr[n][n];
            int dis[n][n];
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                    {
                        cin>>arr[i][j];
                        dis[i][j]=arr[i][j];
                    }
            }
            
            for(int k=0;k<n;k++)
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                        if(dis[i][j]>dis[i][k]+dis[k][j])
                            dis[i][j]=dis[i][k]+dis[k][j];
            
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                    {
                        if(dis[i][j]==10000000)
                            cout<<"INF"<<" ";
                        else
                            cout<<dis[i][j]<<" ";
                    }
                cout<<endl;
            }
        }
	//code
	return 0;
}