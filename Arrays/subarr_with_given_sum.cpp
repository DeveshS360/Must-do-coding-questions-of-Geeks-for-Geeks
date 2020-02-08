#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

// Naive approach doesn't work : Time complextity is O(n2)

//Approach: sliding window 
/*Application of approach: First adding array elements to the window, until 
    sum of sliding window doesn't exceed the given sum, if this happens window
    size is reduced from the beginning */
// Time complexity is O(n)

int32_t main(){// int_32 because int is defined long long but main takes int
    int q;cin>>q;   // q is number of queries
    for(int i=0;i<q;i++)
    {
        int n,s;cin>>n>>s;// n is array size, s is given sum
        int arr[n];
        for(int j=0;j<n;j++)
            cin>>arr[j];
        int f=0;    // flag is initially zero 
        int sum=0;
        vector<int> v;// vector to store answer
        for(int a=0,b=0;a<n&&b<n+1;){// here b<n+1 becuause when last element to be inserted b becomes n
            
            if(sum==s)
            {
                f=1;
                v.push_back(a+1);v.push_back(b);// here b becuse b is already b+1
                break;// if window sum is equal to given sum then no need to move further
            }
            else if(sum>s){
                sum-=arr[a];// removing first element of window
                a++;
            }
            else{
                sum+=arr[b];// if no element is removed then further element to be added
                b++;
            }
            
        }
        if(f)
            cout<<v[0]<<" "<<v[1]<<endl;
        else
            cout<<"-1"<<endl;

    }
    return 0;
}