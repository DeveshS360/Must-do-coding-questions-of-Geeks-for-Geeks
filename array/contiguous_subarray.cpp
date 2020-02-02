#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

// Kadane's algorithm is a famous algorithm to solve this

// below there is also a dynamic algorithm code 

int32_t main(){
	int q;cin>>q; // q is number of queries
	for(int k=0;k<q;k++)
	{
		int n;cin>>n; // n is array size
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int lsum=arr[0],gsum=arr[0];// setting local and global sum to first array element
		for(int i=1;i<n;i++)
		{
			lsum=max(lsum+arr[i],arr[i]); // this is major part of kadane's algorithm
			gsum=max(lsum,gsum);		  // it is basically implementation of dynamic progrmming in indirect way

		}
		cout<<gsum<<endl; // outputting the maximum sum 
	}
	return 0;
}

/*
using namespace std;

// Kadane's algorithm is a famous algorithm to solve this

int32_t main(){
  int q;cin>>q; // q is number of queries
  for(int k=0;k<q;k++)
  {
    int n;cin>>n; // n is array size
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    int sums[n];
    sums[0]=arr[0];
    for(int i=1;i<n;i++)
      sums[i]=max({sums[i-1]+arr[i],arr[i]}); // sums[i] stores the local maximum sum dynamically
    int ans=sums[0];
    for(int i=0;i<n;i++)
        if(sums[i]>ans)
            ans=sums[i];
    cout<<ans<<endl;
  }
  return 0;
}
*/