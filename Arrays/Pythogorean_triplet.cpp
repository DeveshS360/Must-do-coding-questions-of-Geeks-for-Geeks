#include <bits/stdc++.h>
#define int long long
using namespace std;

// This is listed in as a basic question but it is not
// also the worst time complexity in optimized algorithm is O(n2)
// but the constraints of the problem is way too high for that, so it's 
// technically incorrect, we cannot improve it beyond O(n2)
// If you go by Naive approach then it will be O(n3)

/* Approach: First store squares of numbers in a array, then sort in descending order
            then iterate through every squared element, and take two indexes starting
            and ending to go through another loop which checks that whether the sum of
            starting and ending index elements is equal to the current iterated element,
            if yes then we break the loop and stop our searching and output Yes else No
            */

int32_t main() {
    int q;cin>>q; // q is number of queries
    for(int k=0;k<q;k++)
        {
            int n;cin>>n; // n is size of array
            int arr[n];
            for(int i=0;i<n;i++)
                cin>>arr[i];
            int flag=0;  // initially setting flag to 0
            for(int i=0;i<n;i++)
                arr[i]=pow(arr[i],2); // replacing the element with its square
            sort(arr,arr+n,greater<int>()); // sorting 
            for(int i=0;i<n;i++){
                int st=i,end=n-1; // intital values
                while(st!=end)
                    {
                        if(arr[st]+arr[end]==arr[i]) // equality condition
                            {
                                flag=1; // if condition is true then flag=1
                        
                                break; // breaking the loop 
                            }
                        else if(arr[st]+arr[end]<arr[i])// if current element is greater then, decresing end so that the other sum increases(due to sorting)
                            end--;
                        else
                            st++; // if current sum is lesser, than increasing starting index so that we move near to current index element
                    }
                if(flag) // another break to break outer loop
                    break;
            }
            if(flag)
                cout<<"Yes"<<endl; // if we found the triplet then Yes
            else
                cout<<"No"<<endl;// else No
            
            
            
            
        }
    //code
    return 0;
}