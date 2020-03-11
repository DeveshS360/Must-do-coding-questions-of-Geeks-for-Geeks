#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

/* This is a standard question but it involves a particular process
   to solve the problem using stacks to solve in order of O(n^2)
   */

int32_t main() {
    ios_base::sync_with_stdio(false); // for fast input output
    cin.tie(NULL); // for not flushing the output every time
    int q;cin>>q; // number of quesries
    for(int k=0;k<q;k++)
        {
            int n;cin>>n; // array size
            int arr[n]; 
        
            for(int i=0;i<n;i++)
                cin>>arr[i]; // populating the array
            stack<int> st; // making a stack
            st.push(arr[0]); // pushing the first element of the array in the stack
            for(int i=1;i<n;i++) 
                {

                    int next=arr[i]; // setting the next as the current element of the array
                    while(!st.empty()) // if stack is not empty
                                {   
                                    if(st.top()<next) //if it is less than next element
                                        cout<<next<<" ";// then the next larger element for this element is next
                                    st.pop();// popping this element 
                                }
                        
                    st.push(next); // push the next in the stack
                    
                }
            while(!st.empty()) // if stack is not empty
                {
                    cout<<"-1"<<" "; // then for all the elements in stack there is no next larger element
                    st.pop(); // popping the element
                }
            cout<<endl; // new line for other queries
        }
	//code
	return 0;
}