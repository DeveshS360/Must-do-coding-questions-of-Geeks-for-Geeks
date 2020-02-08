#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

// Approach: use starting row index, ending row index, starting coulumn index and 
//           ending column index
// Print rightwards then down then left and finally up. Do this until starting row 
// index equals ending row index or starting column index equals ending column index

int32_t main(){
    int q;cin>>q; // q is number of queries
    for(int k=0;k<q;k++)
    {
        int m,n;cin>>m>>n; // m is number of rows, n is number of columns
        int arr[m][n]; // matrix of size m*n

        for(int i=0;i<m;i++)      //populating the
            for(int j=0;j<n;j++)    //arr matrix
                cin>>arr[i][j];        
        int sc=0,ec=n-1,sr=0,er=m-1; // setting initial values of above explanied variables
                                        // sc is starting column and others similarly


        while(sc<=ec && sr<=er)        // setting loop terminating condition
        {
            for(int i=sc;i<=ec;i++) // printing rightwards
                cout<<arr[sr][i]<<" ";
            sr++;                    // incresing starting row index

            if(sr<=er){
                for(int i=sr;i<=er;i++) // printing downwards
                    cout<<arr[i][ec]<<" ";
                ec--;
            }                   // decresing ending column index

            if(sr<=er){                    // If sr<er, then printing leftwards
                for(int i=ec;i>=sc;i--)
                    cout<<arr[er][i]<<" ";
                er--;                        // decresing ending row
            }
            if(sc<=ec){                        
                for(int i=er;i>=sr;i--)   // if sc<ec, then printing upwards
                    cout<<arr[i][sc]<<" ";
                sc++;
            }


        }
        cout<<endl; // printing a blank line after 1 query is done
    }
    return 0;
}