#include <bits/stdc++.h>
using namespace std;

// This is a very good question if you want to do it in minimum time complexity,
    // which comes out to be O(n), with O(1) extra space
/* Approach: Make variables for result, current length, previous index(prev),
            Previous index is for the starting index of the current substring,
            current length gives the length of the current substring.
            Also we have to make a array to store the latest index of a character.
            We initially makes the index for every character as -1.
            1)Now we start traversing the array , and if we find the latest index of 
            the character we are traversing to be -1 or less than prev than set the 
            latest index of character to be current index and increment length of
            current index by 1
            2)But if the above condition is not true, then we set prev as the latest index
            of the character+1 and set latest index to be the current index.
            Finally we check if the curren length is greater than the result, we
            change resut to the curren index
            */

int main() {
    int q;cin>>q;// number of queries
    for(int k=0;k<q;k++)
        {
            string s;cin>>s; // inputting the string
            int t=s.length(); // t is length of string
            int res=0; // initializing result to zero
            int arr[26]; // making an array to store latest indexes of characters
            for(int i=0;i<26;i++)
                arr[i]=-1; // initializing arr as -1
            int prev=0; // initializing previous index as -1
            int currl=0; // initializing current length as 0
            for(int i=0;i<t;i++)
                {
                    if(arr[s[i]-'a']==-1 || arr[s[i]-'a']<prev){ // executing point 1) of the approach
                        arr[s[i]-'a']=i;
                        currl++;
                    }
                    else{ // executing pint 2) of the appraoch 
                        prev=arr[s[i]-'a']+1;
                        arr[s[i]-'a']=i;
                        currl=i-prev+1;
                    }
                res=max(res,currl); // taking max of result and current length
                }
            cout<<res<<endl;  // outputting the result
        }
	//code
	return 0;
}