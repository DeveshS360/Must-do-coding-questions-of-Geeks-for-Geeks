#include <bits/stdc++.h>
using namespace std;

// This is straight forward question with some caution
/* Approach : Iterate through the string if you find any element whose next
              element is also same then iterate through this element until 
              you don't find an element which is not equal to this or you reach
              the end of the string, keep the count of these duplicates and delete 
              these many characters starting from the element.
              Do this until you don't find any character to delete
              */

int main() {
    int q;cin>>q;// number of queries
    for(int k=0;k<q;k++)
        {
            string s;cin>>s; // input string
            int count=-1; // initializing count as negative
            while(count!=0){ // while we don't find any character to delete
                count=0; // now initilizing setting count as 0
                for(int i=0;i<s.length();)
                    {
                        if(s[i]==s[i+1]) // approach discussed above
                            {   
                                int t=0; // to store number of dupicates starting from the element
                                int j=i; // initializing a variable j to the element index
                                while(s[i]==s[j] && j<s.length()) // till we don't find a different element
                                    {
                                        t++;j++;    // increasing count of duplicates and index j
                                    }
                                s.erase(i,t); // erasing the duplicates 
                                count++;
                            }
                        else
                            i++; // if we don't find a above condition to be true we keep on 
                                    // iterating through the string 
                    }
                    
                    
            }
            cout<<s<<endl; // outputting the resulting string
            
        }
	//code
	return 0;
}