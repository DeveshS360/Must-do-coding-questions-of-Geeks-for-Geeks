// It is functional problem where we just have to complete the given 
// function

// This is a very tricky problem when it comes to solve most efficiently
/* Approach: We have to make a map of sum upto the index and pair where we store the 
            first occuring sum value in the first value of the pair, and
            in the second value of the pair we store the subsequent indexes of 
            the same sum value.
            Also we have to consider a case where although there is no second
            value in the pair, but sum upto that index is 0. */

int maxLen(int arr[], int n) {
    int res=0;// intializing the result as 0
    map<int,pair<int,int>> mp;// map of sum and pair
    int S[n];// S array stores the sum upto the index of array
    memset(S,0,sizeof(S));// intializing all the values as 0
    int sum=0;// temporary variable 
    for(int i=0;i<n;i++)
        {
            sum+=arr[i];// incrementing sum by arr[i]
            S[i]=sum;// then S[i] becomes sum
        }
    
    for(int i=0;i<n;i++)// initializing all the sum value pair as -1,-1
        mp[S[i]]={-1,-1};
    for(int i=0;i<n;i++)
        {
            if(mp[S[i]].first==-1)// if this sum value is found for the first time
                mp[S[i]].first=i;// then the first value of pair becomes this index
            else// if the sum value is found more than 1 times
                {
                    mp[S[i]].second=i;// second value of the sum pair becomes this index
                    res=max(res,i-mp[S[i]].first);// res is maximum of res and length of 0 subarray
                }
            if(S[i]==0)// if sum upto this index is 0
                res=max(res,i+1);// res is max of sum and this index
        }
    return res;// returning the final max length of subarray with sum 0
    // Your code here
}
