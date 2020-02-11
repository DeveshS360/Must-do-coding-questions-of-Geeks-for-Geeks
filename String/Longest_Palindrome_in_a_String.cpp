#include <bits/stdc++.h>
using namespace std;

// This can be solved with a naive apprach with time complexity of O(n3)
// But by using Dynamic Programming approach it can be solved in O(n2)
/* Approach: First make a boolean array of size (string length * string length), ispl
             Then initialize the array to false or 0.
             Then as we know that any substring of length of 1 is a palindrome,hence 
             we set all ispl[i][i] as 1.
             We also make a starting index variable to store the starting index of the longest palindrome.
             Now we set the substring of length 2 which are palindromes as true, by running 
             a loop from 0 to n-1 and checking s[i]==s[i+1].
             Now we run a loop for all the substring of length greater than or equal to 3,
             and check if ispl[i+1][j-1] is true and s[i]==s[j], then we make ispl[i][j] true.
             Finally we check if the current substring palindrome length is greater than the
             current maxlength than we change starting index variable to i and maxlength to 
             current maxlength(here t in code).
             */ 

int main() {
    int q;cin>>q; // number of queries
    for(int k=0;k<q;k++)
        {
            string s;cin>>s; // inputting the string
            int n=s.length(); // n is length of the string
            bool ispl[n][n]; // boolean array to store if the substring is a palindrome or not
            memset(ispl,0,sizeof(ispl)); // initializing the ispl to 0
            for(int i=0;i<n;i++) // setting the all substring of length 1 as true
                ispl[i][i]=1;
            int st=0; // initializing the starting index variable as 0
            int maxl=1; // initializing the maximum length to be 1
            int count=0; // this variable is used to print the least starting index, in case of a conflict
            for(int i=0;i<n-1;i++)
                if(s[i]==s[i+1]){
                    ispl[i][i+1]=1;
                    count++;
                    if(count==1){ // only once the starting index is altered if string of length 2 is there
                        st=i;
                        maxl=2; 
                    }
                }
            for(int t=3;t<n+1;t++) // checking for all substring of length greater than or equal to 3
                for(int i=0;i<n-t+1;i++)
                    {
                        int j=i+t-1; // another variable which stores the ending index of the substring
                        if(ispl[i+1][j-1] && s[i]==s[j]) // checking if the current substring is a palindrome
                            {
                                ispl[i][j]=1; // if yes then setting it as true
                                if(t>maxl) // if current length of substring is greater than max length
                                {
                                    st=i; // then changing the starting index to starting index of current substring
                                    maxl=t; // and changing the maxlength to current length
                                }
                            }
                    }
            for(int i=st;i<st+maxl;i++)
                cout<<s[i]; // printing the longest palindrme
            cout<<endl; // printing a new line for the more than one queries
            
        }
	//code
	return 0;
}