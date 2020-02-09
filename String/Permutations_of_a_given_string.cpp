#include <bits/stdc++.h>
using namespace std;

// This is kept as a basic question which it is not at all, if not hard
// it should atleast be kept as a medium quesiton
/* Approach: Backtracking using recursion to print all permutations,
             only leaf nodes of a recursion tree are to be printed, because
             they contain all the permutations
             */

void perm(string s,int l,int r,vector<string> &v) // takes four parameters: string to be permuted, left inedex
    {                                              // right index, vector vec
        if(l==r) // if leaf node
            v.push_back(s); // then push string permutation in the vector
        else  // if not leaf node
            {
                for(int i=l;i<=r;i++) // run the loop to swap every index with every other greater than it
                    {
                        swap(s[l],s[i]); // swapping
                        perm(s,l+1,r,v); // running recursive function on swapped string
                        swap(s[l],s[i]); // reswapping so that we can iterate on original string before swapping
                    }
            }
    }

int main() {
    int q;cin>>q; // number of quries
    for(int k=0;k<q;k++)
        {
            string s;cin>>s; // input string whose permutations to be printed
            vector<string> vec; // vector to store permutations of string
            perm(s,0,s.length()-1,vec); // calling recursive function
            sort(vec.begin(),vec.end()); // sorting the vector to print strings in lexographical order
            for(auto x:vec)
                cout<<x<<" "; // outputting the strings
            cout<<endl; // adding new line finally
            
        }
	//code
	return 0;
}