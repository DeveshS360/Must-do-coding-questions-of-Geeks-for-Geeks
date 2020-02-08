#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

// Naive algorithm uses 3 loops thus gives time complexity of O(n3)
// Constraints given in the problem suggests that O(n2) could work
// Approach:
/* First sort the array in incresing order, then traverse the array for every array element 
   bidirectionally by taking start(a here) and end(b here) variables and follow the following rules:
   1) If sum of array elements at the two positions equals the sum of current array element,
      then increase start and decrease end.
   2) If sum of start and end less than current array element, then increase start
   3) Else decrease end
   Finally break the loop for bidirectional traversal if start is same as end
   */

int32_t main(){
	int q;cin>>q; // number of queries
	for(int k=0;k<q;k++)
	{
		int n;cin>>n;// array size n
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n, greater<int>());// sorting in decending order
		int count=0;// stores count of the triplets
		for(int i=0;i<n-2;i++)// is is current index
			{
				int a=i+1,b=n-1;// a is start , b is end
				while(a<b)  // this while loop executes the above explained approach
				{
					if(arr[i]==arr[a]+arr[b]){
						count++;
						a++,b--;
					}
					else if(arr[i]>arr[a]+arr[b])
						b--;
					else
						a++;

				}
			}

		if(count)
			cout<<count<<endl;// if count is not zero then printing the result
		else
			cout<<"-1"<<endl;// if count is zero then printing -1 
	}
	return 0;
}