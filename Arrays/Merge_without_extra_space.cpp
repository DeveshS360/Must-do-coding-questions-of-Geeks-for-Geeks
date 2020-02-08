#include <bits/stdc++.h>
using namespace std;

// This is a tricky question with a very simple solution
/* Approach: Since we cannot have extra space hence we cannot use the approch to make another
             array and then add elements of both the given arrays. So what to do?
             Solution: Well we can do one thing, we can iterate through any of the array 
                        and then compare that element with each element of the another array
                        if we find any lesser element than the current element we print that 
                        and keep on doing this until element in the another array is not lesser,
                        at this point we print the current element.
            The worst time complexity of this algorithm is O(n+m), since both arrays are
            iterated once only.
                        */

int main() {
    int q;cin>>q; // q is number of queries
    for(int k=0;k<q;k++)
        {
            int n,m;cin>>n>>m; // n,m are respective array sizes of the two arrays
            int arr[n],brr[m];// the two arrays
            for(int i=0;i<n;i++)
                cin>>arr[i];  // populating first array
            for(int i=0;i<m;i++)
                cin>>brr[i];  // populating second array
            int j=0; // starting index of second array 
            for(int i=0;i<n;i++) // iterating through 1st array 
                {
                    while(j<m) // maximum value of j can be m-1
                        {
                            if(brr[j]<arr[i]){ // if any element of 2nd array is less than current
                                                    // element of the 1st array, then print it, and
                                                    // increment j, index of second array 
                                cout<<brr[j]<<" ";
                                j++;
                            }
                            else if(brr[j]>=arr[i]) // if above condition is false then break no need to go on, since arrays are sorted individually
                                break;
                        }
                    cout<<arr[i]<<" ";   // printing the current element of 1st array
                }
            for(int i=j;i<m;i++)
                cout<<brr[i]<<" "; // when we are done with the first array and still some elements are left in second array which are left to be printed
            cout<<endl;    // new line for multiple test cases format
        }
	//code
	return 0;
}