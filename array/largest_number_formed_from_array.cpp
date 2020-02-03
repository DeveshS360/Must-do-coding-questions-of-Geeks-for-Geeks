#include <bits/stdc++.h>
using namespace std;

// This is a tricky question which could be easily solved by using string comparision
//Approach:
/* We basically need to make a custom sorting function which sorts the 
    array of strings such that string1+string2 > string2+string1,
    so finally what we get is an array of strings sorted as maximum number*/


bool compare(string s1,string s2){ // this is a custom sorting funciton
    return s1+s2>s2+s1;
}

int main() { 
    int q;cin>>q; // number of queries
    for(int k=0;k<q;k++)
        {
            int n;cin>>n;  // array size
            string arr[n]; // declaring an array of strings
            for(int i=0;i<n;i++)
                cin>>arr[i];
            sort(arr,arr+n,compare); // sorting using custom sorting funciton
            for(int i=0;i<n;i++)
                cout<<arr[i];  // outputting each element of sorted array
            cout<<endl;
        }
	//code
	return 0;
}