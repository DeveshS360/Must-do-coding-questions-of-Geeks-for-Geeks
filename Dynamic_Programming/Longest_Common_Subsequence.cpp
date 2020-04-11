#include<bits/stdc++.h>
using namespace std;

/*Approach: We create a 2D array of size n+1*m+1, n & m being the 
            size of the two strings, now we do two things, and we
            set 0 index for any dimension as 0.*/

int main() {
    int q;cin>>q;
    while(q--)
        {
            int n,m;cin>>n>>m;
            string s1,s2;cin>>s1>>s2;

            int dp[n+1][m+1];
            memset(dp,0,sizeof(dp));
            
            
            for(int i=0;i<=n;i++)
                for(int j=0;j<=m;j++)
                    {
                        if(i==0 || j==0)
                            dp[i][j]=0;
                        else if(s1[i-1]==s2[j-1])
                            dp[i][j]=dp[i-1][j-1]+1;
                        else
                            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
        cout<<dp[n][m]<<endl;
        }
	//code
	return 0;
}