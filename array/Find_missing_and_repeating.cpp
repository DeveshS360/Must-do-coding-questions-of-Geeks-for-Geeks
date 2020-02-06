#include <bits/stdc++.h>
using namespace std;

// This is an excellent problem, which teaches you something
// Learning: Sometimes not storing the readed elements to array helps
/*Approach: make an array of given size + 1
            then initialize that array to 0, then read the array elements, increase of 
            index which is equal to read element by 1,
            if at some index value is 2, then that means that has been repeated,
            and if value is still 0 apart from index 0, then that element is missing
            */
int main() {
    int q;cin>>q; // number of queries
    for(int k=0;k<q;k++)
        {
            int n;cin>>n; // given array size
            int arr[n+1]; // making array of size n+1
            for(int i=0;i<n+1;i++)
                arr[i]=0; // initializing to 0
            for(int i=0;i<n;i++)
                {   
                    
                    int x;cin>>x;
                    arr[x]++; // reading an element and increasing value at that index
                }
            int rep,miss=0; // two variables for repeating and missing elements
            for(int i=1;i<n+1;i++)
                {
                    if(arr[i]==2) // if arr[i] is 2 then that means it is repeating
                        rep=i;
                    if(arr[i]==0) // if arr[i] is 0 apart from 0 index then that means it is missing
                        miss=i;
                }
            cout<<rep<<" "<<miss<<endl; // outputting repeating and missing elements
            
                
            
                    
        }
	//code
	return 0;
}