#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;

// This problem could be solved by modifying the merge function of merge sort algorithm
// There is no short technique to do this problem, you have to implement the full merge sort
// algorithm and then do just a little modification to it. 


void merge(int a[],int m,int L,int R,int &count){ // a[] is the original array to be sorted

                        // m is middle index

    int n1=m-L+1; // n1 is number of elements in the first half
    int n2=R-m;     // n2 is the number of elements in the second half

    int t1[n1]; // temporary array to store first half elements
    int t2[n2]; // temporary array to store second half elements

    for(int i=0,j=L;i<n1&&j<m+1;i++,j++) // populating the first half
        t1[i]=a[j];
    for(int i=0,j=m+1;i<n2&&j<R+1;i++,j++) // populating the second half
        t2[i]=a[j];

    
    int i=0;  // initalizing two variables for iterating through both the arrays
    int j=0;

    
    

    int c=L; // current index of the original array


    while(i!=n1 && j!=n2){ // while one of the array index is max index of that array
        if(t1[i]<=t2[j]){ // if current element of first half is less then equal to current element of second half
            a[c]=t1[i]; // then set it equal to the current element of the original array
            i++; // increment the first half index by 1
            
        }
        else // if second half current index element is lesser then
        {
            a[c]=t2[j]; // set current original array index element equal to second half current elemet
            j++; // increment the current index of second half array
            count+=n1-i; // count is basically the modification, it stores the 
                            // number of inversions, and for each second half array element
                            // it is equal to the mumber of elements in the first half from current
                            // because since the first half array is already sorted in ascending order
                            // the elements starting from the curren index to the end all are greater than
                            // the current element of the second half array so it adds to number of inversions 
                            // index of first half array to the end of first half array.
            
            
        }
        c++; // current index of the original array is incremented irrespecitve of the above conditions
        


    }

    
        for(int k=i;k<n1;k++) // if after comparisions if either half of array is not fully traversed
            {
                a[c]=t1[k];
                c++;
            }
    
        for(int k=j;k<n2;k++) 
            {
                a[c]=t2[k];
                c++;
            }

    

}

void mesort(int arr[],int L,int R,int &count ){ // merge sort function which uses merge function
    
    // L is left index , R is right index of the array to be sorted, count is for number of inversions
    
    if(L<R) 
    {
        int m = (L+(R-L)/2); // middle index

        

        mesort(arr,L,m,count); // sorting the first half
        mesort(arr,m+1,R,count); // sorting the second half

        merge(arr,m,L,R,count); // merging the sorted halves
    }

    

}

int32_t main(){
    int q;cin>>q; // q is number of queries
    for(int k=0;k<q;k++){
        int count=0; // initially number of inversions is 0
        int n; // array size
        cin>>n; 
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];          // populating the array
        }
    
        mesort(A,0,n-1,count);  // applying mergesort to the array
    
        cout<<count<<endl; // printing the number of inversions
    }

    return 0;

}