#include <bits/stdc++.h>
using namespace std;

/*Approach:the maximum value that can be obtained from n items 
            is max of following two values.
            1) Maximum value obtained by n-1 items and W weight 
            (excluding nth item).
            2) Value of nth item plus maximum value obtained by n-1 
            items and W minus weight of the nth item (including nth item).
*/
int main() {
    int q;cin>>q;
    while(q--)
        {
            int n,w;cin>>n>>w;
            int val[n];
            for(int i=0;i<n;i++)
                cin>>val[i];
            int wt[n];
            for(int i=0;i<n;i++)
                cin>>wt[i];
                
            int dp[w+1][n+1];
            memset(dp,0,sizeof(dp));
            for(int i=0;i<=w;i++)
                for(int j=0;j<=n;j++)
                    {
                        if(i==0 || j==0 ) continue;
                        
                        else if(i>=a[j-1])
                            dp[i][j]=max(dp[i][j-1],val[j-1]+dp[i-wt[j-1]][j-1]);
                        else
                            dp[i][j]=dp[i][j-1];
                    }
                    
            cout<<dp[w][n]<<endl;
            
            
            
                
            
        }
    //code
    return 0;
}