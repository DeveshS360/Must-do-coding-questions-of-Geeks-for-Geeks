#include <bits/stdc++.h>
using namespace std;

// Dynamic programming approach is used to solve the problem
/* Approach: taken from GFG
    Let the input string be str[l……h]. The problem can be broken down into three parts:
    Find the minimum number of insertions in the substring str[l+1,…….h].
    Find the minimum number of insertions in the substring str[l…….h-1].
    Find the minimum number of insertions in the substring str[l+1……h-1].
    where l is the starting index of substring and h is the ending index of 
    the substring.
    Now if the length of substring is 1 then no need to insert any character.
    And if the length of substring is 2 then there are two cases:
    i) If both the characters of the substring are same then no need to insert
        any character
    ii) If both are different then to add 1 character to the substring to form 
        a palindrome out of it
        */

int main() {
    int q;cin>>q; // q is the number of queries
    for(int k=0;k<q;k++)
        {
            string s;cin>>s; // input string s
            int n=s.length(); // n is length of the string
            int arr[n][n]; // array to store the number of characters to be inserted to the substring in a table form
            memset(arr,n,sizeof(arr)); // initializing all table elements to be length of the string
            for(int i=0;i<n;i++) // if substring is of length 1,
                arr[i][i]=0; //  then no need to add any character

            for(int i=0;i<n-1;i++){ // if substring is of length 2, then
                if(s[i]==s[i+1]) // if both characters are same
                    arr[i][i+1]=0; // no need to add any character
                else
                    arr[i][i+1]=1; // else 1 character to be added
            }
            
            for(int t=3;t<n+1;t++) // iterating for length greater than or equal to 3
                for(int i=0;i<n-t+1;i++) // executing the above explained approach
                    {
                        int j=i+t-1; // ending index of the substring
                        if(s[i]==s[j]) // if ending and starting characters are same
                            arr[i][j]=arr[i+1][j-1]; // then number of characters are equal to 
                                                    //characters inserted in substring smaller by one 1 character 
                                                    // from both ends
                        else
                            arr[i][j]=min(arr[i][j-1],arr[i+1][j])+1; // else it is equal to minimum of number of characters
                                                                    // inserted in 1 character removed by either end or start
                    }
                     
            cout<<arr[0][n-1]<<endl; // outputting the number of characters to be inserted in the original string
        }
	//code
	return 0;
}