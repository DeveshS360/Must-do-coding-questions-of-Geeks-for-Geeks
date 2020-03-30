#include<bits/stdc++.h>
using namespace std;

// Efficient apprach involves hashing where we store the frequencies 
// of the remainders of the elements

int main(){

	int q;cin>>q;// numbe of queries
	while(q--)
		{
			int n;cin>>n;// array size
			int arr[n];// declaring the array of size n
			int sum=0;// initializing sum as 0
			for(int i=0;i<n;i++){// adding each element to the sum
				cin>>arr[i];
				sum+=arr[i];
			}
			int k;cin>>k;// divisiblity factor
			if(sum%2!=0 || n%2!=0)// if odd sized array or sum is odd
				cout<<"False"<<endl;
			
			else// if not then
			{	
				int f=1;// flag variable
				map<int,int> fr;// mapping of frequecy of remainders
				for(int i=0;i<n;i++)
					fr[arr[i]%k]++;// incrementing count of frequency
				for(auto x:fr){// iterting through each remainder
					if(x.first*2==k || x.first==0){// if remainder is 0 or half of k
						if(x.second%2!=0)// then there must be even number of occurences of this remainder
							f=0;
					}
					else// if it is different from 0 and half of k
						if(fr[k-x.first]!=fr[x.first])//then must be equal frequencies of remainder and k-remainder
							f=0;


				}
				if(f)
					cout<<"True"<<endl;
				else
					cout<<"False"<<endl;
			}
		}	




	return 0;
}