#include <iostream>
using namespace std;

// This is a very tricky problem to be solved in O(n) time complexity
// Approach is taken from GFG hint box. Wasn't able to solve on my own.
/* Approach : As we need the max difference j - i such that A[i]<= A[j],
 hence we do not need to consider element after the index j and element before index i.
make 2 arrays, 
First, will store smallest occuring element before the element
Second, will store largest occuring element after the element

Traverse the Second array, till the element in second array is larger than or equal to First array, and store the index difference. And if it becomes smaller, traverse the first array till it again becomes larger.

And store the max difference of this index difference.
*/

int main() {
    int q;cin>>q;  // number of queries
    for(int k=0;k<q;k++)
        {
            int n;cin>>n; // array size
            int arr[n];
            for(int i=0;i<n;i++)
                cin>>arr[i];  // populating the array
            int crr[n],brr[n];     // crr for storing min from left, brr for storing max from right
            int mi=arr[0],mx=arr[n-1]; // intial values exteme elements
            for(int i=0;i<n;i++)
                {
                    mi=min(mi,arr[i]); // storing min upto that index
                    crr[i]=mi;
                }
            for(int i=n-1;i>=0;i--)
                {
                    mx=max(mx,arr[i]); // storing max upto that index
                    brr[i]=mx;
                }
            int mdi=0; // to store maximum difference j-i
            for(int i=0,j=0;i<n&&j<n;)
                {
                    
                    if(crr[i]>brr[j]) // if minimum value before a element greater than max value after the element
                        i++; // then we move ahead in the crr 
                    else
                        {
                        mdi=max(mdi,j-i);     // else we store the max diff j-i, and move ahead in brr
                        j++;
                        }
                }
            cout<<mdi<<endl; // printing the maximum j-i
            
            
            
        }
	//code
	return 0;
}