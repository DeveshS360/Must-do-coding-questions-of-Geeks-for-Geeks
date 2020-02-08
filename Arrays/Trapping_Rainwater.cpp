#include <bits/stdc++.h>
using namespace std;

// It is a tricky question, according to me it's something which you won't get if you haven't seen
/* Approach:
    Make two more arrays for storing max height from left side, and right side
    Then water level at particular location would be difference of min of these heights
    at this place and height in the original array.
    Finally add these water level at each location to get total amount of water
    */

int main() {
    int q;cin>>q; // q is number of queries
    for(int k=0;k<q;k++)
        {
            int n;cin>>n;// n is array size
            int arr[n];
            for(int i=0;i<n;i++)
                cin>>arr[i];// populating the array
            int ls[n],rs[n];// two arrays for storing the max height as iterated from left and right
            int mls=arr[0];
            for(int i=0;i<n;i++){   // populating the left height array
                mls=max(mls,arr[i]);
                ls[i]=mls;
            }
            int mrs=arr[n-1];
            for(int i=n-1;i>=0;i--){ // populating the right side array
                mrs=max(mrs,arr[i]);
                rs[i]=mrs;
            }
            int sum=0; // initial amount of water is 0
            for(int i=0;i<n;i++)
                sum+=(min(rs[i],ls[i])-arr[i]); // adding to water amount water level at each location
            cout<<sum<<endl; // finally outputting the total amount of water
                
        }
	//code
	return 0;
}