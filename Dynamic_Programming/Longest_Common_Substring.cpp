#include <bits/stdc++.h>
using namespace std;

/*Approach:If last characters match, then we reduce both lengths by 1
LCSuff(X, Y, m, n) = LCSuff(X, Y, m-1, n-1) + 1 if X[m-1] = Y[n-1]
If last characters do not match, then result is 0, i.e.,
LCSuff(X, Y, m, n) = 0 if (X[m-1] != Y[n-1])*/

int main() {
    int q;cin>>q;
    while(q--)
        {
            int n,m ; cin >> n >> m ;
            string s1,s2 ; cin >> s1 >> s2 ;
            int dp[n+1][m+1] ;
            memset(dp,false,sizeof(dp));
            for(int i=0;i<=n;i++)
            {
                for(int j=0;j<=m;j++)
                {
                    if(i == 0 || j == 0) dp[i][j] = 0 ;// since we are starting with index 1
                    else if(s1[i-1] == s2[j-1])
                    {
                       dp[i][j] = 1 + dp[i-1][j-1] ; 
                    }
                    
                    else dp[i][j] = 0 ;
                    
                }
            }
            
            int res = 0 ;
            for(int i=0;i<=n;i++)
            {
                for(int j=0;j<=m;j++) res = max(res,dp[i][j]);
            }
            
            cout << res << endl ;
            
            
            
        }
	//code
	return 0;
}