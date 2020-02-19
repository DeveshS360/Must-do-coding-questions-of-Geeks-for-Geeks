#include <bits/stdc++.h>
using namespace std;

// This is a very tough problem as it involves an algorithm which is just perfect

/* Approach:1) First make a map of of charcter and their frequency for both
                the string and the pattern.
            2)Then start traversing the string and match it with the characters of
            the pattern, increase a counter and check if it becomes equal to the 
            length of the pattern, if this happens then this means that a window is
            found which contains all the characters of the pattern.
            3)If the window is found then we can reduce the length of this window by
            removing the non required characters.
            4) This is important to note that once the count is equal to pattern length
                then always as we traverse more in the array then also we check for the 
                optimum window
            5) As we check for the lenght of the window, and we keep the mimimum length of 
                the window, and it becomes our optimum window
            6) Finally we print the optimum window
            */

int main() {
    int q;cin>>q; // number of queries
    for(int k=0;k<q;k++)
        {
            string s,t;cin>>s>>t; // inputting the string and the pattern
            map<char,int> my; // map for pattern characters and frequency
            int a=s.length(),b=t.length(); // variables for length of string and pattern
            for(int i=0;i<b;i++)
                my[t[i]]++; // incresing the frequency of character of the pattern
            if(b>a)
                cout<<"-1"<<endl; // if lenght of pattern is greater than the length of 
                                    // string then no window is possible, else
            else{
                    int count=0; // count for checking if any window exists which contain all characters of pattern
                    map<char,int> mp; // map for string characters and frequency
                    int msi=-1; // this is the starting index of final optimum window
                    int minlen=a,st=0; // initailly setting the mininmum length to be equal to string length
                    for(int i=0;i<a;i++)
                        {   
                            
                            mp[s[i]]++; // increasing the frequency of the string characters
                            if(mp[s[i]]<=my[s[i]] && my[s[i]]!=0 ) // if matching character is found in the pattern
                                count++;
                            if(count==b) // if count any window is found
                                {
                                    while(mp[s[st]]>my[s[st]] || mp[s[st]]==0) // checking to remove unwanted characters from the window
                                        {
                                            mp[s[st]]--; // frequency of charcter is reduced by one
                                            st++; // st to move further in the window
                                        }
                                    int len= i-st+1; // length of the window after removing unwanted chars
                                    if(len<minlen) // if this length is minimum uptill now
                                        {
                                            minlen=len; // then minimum is set to be equal to this
                                            msi=st; // and starting index of this is set to that of optimum
                                        }
                                        
                                        
                                }
                            
                        }
                if(msi==-1) // if there is no optimum window
                    cout<<"-1"; // printing -1
                else // else printing the optimum window
                    {
                        for(int i=msi;i<msi+minlen;i++)
                            cout<<s[i];
                    }
                cout<<endl; // new line for multiple testcases
            }
                        
                    
                    
                    
                    
    
                        
                
        }
	return 0;
}