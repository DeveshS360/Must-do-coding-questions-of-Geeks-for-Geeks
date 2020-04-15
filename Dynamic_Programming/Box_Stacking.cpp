//This is a functional frpblem, we have to complete the function
// which returns the maximum height of stack possible of the 
// available boxes


bool compare(vector<int> u, vector<int> v)// custom function for sorting the rotations based on area
    {
        return u[0]*u[1]>v[0]*v[1];
    }

int maxHeight(int height[],int width[],int length[],int n)
{
    vector<int> rtns[3*n+1];// rtns is an array to store all possible permutations of boxes dimensions
    rtns[0]={0,0,0};// setting values of 0th element
    for(int i=0;i<n;i++)
        {       
                int j=3*i+1;// j is a parameter for each row 1st element

                // storing by fixing length greter than height of the box without loss of generality
                if(length[i]>width[i])
                    rtns[j]={length[i],width[i],height[i]};
                else
                    rtns[j]={width[i],length[i],height[i]};
                if(width[i]>heigh[i])
                    rtns[j+1]={width[i],height[i],length[i]};
                else
                    rtns[j+1]={height[i],width[i],length[i]};
                if(height[i]>length[i])
                    rtns[j+2]={height[i],length[i],width[i]};
                else
                    rtns[j+2]={length[i],height[i],width[i]};
        }
    sort(rtns+1,rtns+3*n+1,compare);// sorting the rtns from index 1

    // Now we will simpley perform the longest decreasing subsequence algorithm
    
    int dp[3*n+1];
    dp[0]=0;
    for(int i=1;i<3*n+1;i++)
        {
            dp[i]=rtns[i][2];
            for(int j=i-1;j>=0;j--)
                {
                    if(rtns[i][0]<rtns[j][0] && rtns[i][1]<rtns[j][1])
                        dp[i]=max(dp[i],dp[j]+rtns[i][2]);
                }
        }
        
        int res=0;
        for(int i=1;i<3*n+1;i++)
            res=max(res,dp[i]);
        return res;
    //Your code here
}