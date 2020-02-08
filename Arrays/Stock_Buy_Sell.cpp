#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;

// Approach: Take two indexes buy and sell, the day of buying and selling
/* Initially set both of them equal to 0, the first element index of the array
	Now follow the following rules for changing the buy and index values:
	1)If current element is lesser than sell index element,and if sell-buy>0,
		then that means there is a profit so push back in a vector buy and sell,
	2)If current index is greater than sell index element,then change sell to current
	*/


int32_t main(){
	int q;cin>>q; // q is number of queries
	for(int k=0;k<q;k++)
	{
		int n;cin>>n; // n is array size
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];  // populating the array 
		int buy=0,sell=0;
		vector<pair<int,int>> bsell; // vector for storing pair of buy and sell
		for(int i=0;i<n;i++)
		{	
			if(arr[i]>arr[sell]) // if this condition is true than that means update sell
				sell=i;
			
			if(arr[i]<arr[sell] || i==n-1){  // i==n-1 because there may be a case that arr[sell] keeps on increasing
				if(sell-buy>0 && arr[sell]>arr[buy]) // rule number 2
					bsell.push_back(make_pair(buy,sell));
				buy=i;
				sell=i;
			}


		}
		for(auto x:bsell)
			cout<<"("<<x.first<<" "<<x.second<<")"<<" "; // outputting in the given format of question
		if(bsell.size()==0) // if no profit is there
			cout<<"No Profit"; // outputting no profit
		cout<<endl;
	}
	return 0;
}