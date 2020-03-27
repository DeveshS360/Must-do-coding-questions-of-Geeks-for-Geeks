#include <bits/stdc++.h>
using namespace std;

// This question could be solved easily with help of priority queues stl
// in minimum time complexity
/* Approach:Maintain a Minheap of size K, thus heap will contain minimum
            element at the top in that pile size. Remove top element 
            if the new element is greater than the top element
            and insert the new element from input array. 
            Thus follow this procedure.*/
int main() {
    int q;cin>>q; // number of queries
    while(q--)
        {
            int k,n;cin>>k>>n; // inputting kth largest element parameter and size of array
            int arr[n]; // declaring the n sized array
            for(int i=0;i<n;i++) // flooding the array
                cin>>arr[i];
            priority_queue<int,vector<int>,greater<int>> mh; // min heap priority queue
            for(int i=0;i<n;i++)// traversing the array
                {   
                
                    if(i<k-1){ // until kth element is not there
                        mh.push(arr[i]);// push into priority queue
                        cout<<"-1 "; // output -1
                    }
                        
                    else
                        {
                            if(mh.size()==k){ // if k sized minheap is full
                                if(mh.top()<arr[i]){// and if next element is greater than top(min)
                                    mh.pop();// we pop the top element 
                                    mh.push(arr[i]);// push the new element
                                }
                            }
                            else
                                mh.push(arr[i]); // if minheap is not full we push the next element
                            cout<<mh.top()<<" ";// output the kth largest element
                            
                        }
                   
                    
                }
            cout<<endl;// new line for multiple queries
        }
	//code
	return 0;
}