#include <bits/stdc++.h>
using namespace std;

// It is functional problem, we have to complete function findIslands
// } Driver Code Ends
/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/

/* Appraoch: Here we can solve this proble very easily by performin,DFS
             on the array itself rather making a graph with nodes*/
void DFS(vector<int> a[],int i,int j,int n,int m){
    if(i<0 || i>=n || j<0 || j>=m ||a[i][j]==0) return;
    
    a[i][j]=0;
    DFS(a,i+1,j,n,m);
    DFS(a,i-1,j,n,m);
    DFS(a,i,j+1,n,m);
    DFS(a,i,j-1,n,m);
    DFS(a,i+1,j+1,n,m);
    DFS(a,i-1,j-1,n,m);
    DFS(a,i-1,j+1,n,m);
    DFS(a,i+1,j-1,n,m);
}

int findIslands(vector<int> a[], int N, int M)
{
//Your code here 
    int count=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            {
                if(a[i][j]==1)
                 {  
                     DFS(a,i,j,N,M);
                      count++;
                 }
            }
    }
    return count;
}
