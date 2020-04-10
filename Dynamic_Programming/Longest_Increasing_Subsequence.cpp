#include <bits/stdc++.h>
using namespace std;

/*Approach: We have to make a 1D array to store the maximum value of 
            increasing subsequence upto that point, then we simply take
            the maximum of all the values of this array.
            And for obtaining the maximum value of each element of array,
            we first set max value for that element 1, then we iterate from
            index of that element upto 0 and if this condition arr[j]<arr[i],
            j being the index less than i, and i being index of element,
            then we set dp[i]=max(dp[i],dp[j]+1)*/

int main() {
    int q;cin>>q;
    while(q--)
        {
            int n;cin>>n;
            int arr[n];
            for(int i=0;i<n;i++)
                cin>>arr[i];
            int dp[n];
            memset(dp,0,sizeof(dp));
            for(int i=0;i<n;i++)
                {
                    dp[i]=1;
                    for(int j=i-1;j>=0;j--)
                        {
                            if(arr[j]<arr[i])
                                dp[i]=max(dp[j]+1,dp[i]);
                            
                        }
                }
                
            int res=0;
            for(int i=0;i<n;i++)
                    res=max(res,dp[i]);
            
            cout<<res<<endl;
            
        }
	//code
	return 0;
}