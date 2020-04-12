#include <bits/stdc++.h>
using namespace std;

/*Approach: This problem is similar to knapsack problem, here also we make a
            2D array for tabulation and then for each coin we take maximum of
            whether we can take this coin or not in making the coin change*/


int main() {
    int q;cin>>q;
    while(q--)
        {
            int m;cin>>m;
            int arr[m];
            for(int i=0;i<m;i++)
                cin>>arr[i];
            int n;cin>>n;
            int dp[n+1][m+1];
            memset(dp,0,sizeof(dp));
            for(int i=0;i<=m;i++) dp[0][i] = 1 ;
            for(int i=0;i<=n;i++) dp[i][0] = 0 ;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(i>=arr[j-1]) dp[i][j] += dp[i-arr[j-1]][j] + dp[i][j-1];
                    else dp[i][j] += dp[i][j-1] ;
                }
            }
            
            cout << dp[n][m] << endl ;
        }
	//code
	return 0;
}