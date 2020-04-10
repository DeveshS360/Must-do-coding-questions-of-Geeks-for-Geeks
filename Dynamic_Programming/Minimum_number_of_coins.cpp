#include <bits/stdc++.h>
using namespace std;

//This question is a bit tricky because in this you have to print the 
// values of the denominations instead of the minumum number of the denominations
/* Approach: You have to make a different array to store the current value of denomination,
            at that value and then reduce the value until it becomes zero*/
int main() {
    int q;cin>>q;
    while(q--)
        {
            int n;cin>>n;
            int dp[n+1];
            int res[n+1];// for storing the coin value used at that value
            memset(res,0,sizeof(res));
            for(int i=0;i<=n;i++)
                dp[i]=INT_MAX;
            vector<int> p={1,2,5,10,20,50,100,200,500,2000};
            for(int x:p)
                if(x<=n)
                    dp[x]=1;
            for(int i=1;i<=n;i++){
                res[i]=i;
                for(int x:p)
                    if(x<=i)
                        {   
                            
                            if(dp[i-x]+1<dp[i])
                                {
                                    dp[i]=dp[i-x]+1;
                                    res[i]=x;
                                }
                            
                            
                        }
            }
            vector<int> v;
            while(n)
                {
                    v.push_back(res[n]);
                    n=n-res[n];
                }
            sort(v.begin(),v.end(),greater<int>());
            for(auto x:v)
                cout<<x<<" ";
            cout<<endl;
            
        }
	//code
	return 0;
}