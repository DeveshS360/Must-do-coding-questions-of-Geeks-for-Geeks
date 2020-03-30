#include <bits/stdc++.h>
using namespace std;

// This is a very tricky solution, tried many thing but had to see the 
// soluiton which is dam perfect
/*Approach: Make a sum array which which stores the sum upto that index
            for all indexes. Also make a map of these sums and their 
            frequencies.
            Now traverse the array if sum is zero then add the ans.
            Then add to the count the frequency of the current sum.
            Then increase the sum frequency by 1.
            It is interesting to note that why there is a special case 
            for 0, because if sum is zero it then it is a subarry with 
            sum, but also if there are many 0's sums then there exists
            subarrays between these zero sums whose sum is also zero.
            */



int main() {
    int q;cin>>q;// number of queries
    while(q--)
        {
            int n;cin>>n;// array size
            int arr[n];// declaring the array
            for(int i=0;i<n;i++)
                cin>>arr[i];// populating the array
            int count=0;// variable for the final answer
            int S[n];// sum array
            unordered_map<int,int> mp;// map of sums and frequencies
            int sum=0;// initializing the sum as 0
            for(int i=0;i<n;i++)
                {
                    sum+=arr[i];// adding array element to sum
                    S[i]=sum;// summation upto this index is equal to sum
                
                }
            for(int i=0;i<n;i++)// traversing the array final time
                {
                    if(S[i]==0)// if sum upto this index is zero
                        count++;// increment the count
                    count+=mp[S[i]];// incrementing the count by frequency of this sum
                    
                    mp[S[i]]++;// incrementing the frequency of this sum by 1
                }
            cout<<count<<endl;// printing the final answer and a new line
        }
	//code
	return 0;
}