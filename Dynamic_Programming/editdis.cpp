#include <bits/stdc++.h>
using namespace std;

/*Approach: We make a 2D array and follow a bottom up approach,
			We make a mat 2D array of n+1*m+1 dimension, then 
			we iterate for 0 index of 1 and other indexes of other dimension,
			and set edit distance for that equal to other index.
			Since insertion in one string is equivalent to deletion from other string,
			hence according to us only two operations are there deletion and replacing 
			Then we iterate on rest of the array and we check for two conditions,
			which are there in the code, and set minimum of edit distance upto that 
			entry*/

int main() {
    int q;cin>>q;
    while(q--)
        {
            int n,m;cin>>n>>m;
            string s1,s2;cin>>s1>>s2;
            int mat[n+1][m+1];

	    for(int i=0;i<=n;i++)
		    mat[i][0]=i;
	    for(int i=0;i<=m;i++)
		    mat[0][i]=i;

	    for(int i=1;i<=n;i++)
		    for(int j=1;j<=m;j++)
		    {	
			    int a=0;
			    if(s1[i-1]==s2[j-1])
				    a= mat[i-1][j-1];
			    else 
			        a= mat[i-1][j-1]+1;
			    mat[i][j]=min({mat[i-1][j]+1,mat[i][j-1]+1,a});
		    }

	cout<<mat[n][m]<<endl;
        }
	//code
	return 0;
}