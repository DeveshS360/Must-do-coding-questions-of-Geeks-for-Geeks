#include <bits/stdc++.h>
using namespace std;

// This is a dynamic programming problem
/* Approach: We know for n equals 1 and 2 we have 2,3 as a answer,
             now we can use this information to find the answer for any n.
             If n is 1 we will take it as seperate case.
             If n is greater than or equal to 2, we will make two arrays eo and ez, which stores
             the number of non consecutive ones strings ending with 1 and 0 respectively.
             Now by logic eo for a particluar length would be equal to eo for length one lesser,
             and ez for a particular length would be equal to ez + eo for length one lesser,
             since we cann add 0 to all the strings of one lesser length to form a string of this 
             length by adding 0 at the last 
             */


int main() {

    int q;cin>>q; // number of queries
    int p= pow(10,9)+7; // a very big interger to avoid interger overflow
    for(int k=0;k<q;k++)
        {
    
            int n;cin>>n; // length of string 
            if(n==1)
                cout<<2<<endl; // if length is 1 print 2 ( strings are 0,1)
            else{ // if n is not equal to 1
                int eo[n+1],ez[n+1];// two arrays containing number of strings ending with 1 and 0 respectively
                eo[2]=1,ez[2]=2; // for n=2 their values( you can check by doing it manually)
                for(int i=3;i<n+1;i++){ // for n greater than 3 applying dynamic approach
                    eo[i]=ez[i-1]%p;
                    ez[i]=(ez[i-1]+eo[i-1])%p;
                    
                }
                cout<<(eo[n]+ez[n])%p<<endl; // outputting the final number of strings of length n
            }
                
            
        }
	//code
	return 0;
}