#include <bits/stdc++.h>
using namespace std;

// This question is a typical backtracking question
// I suggest to learn this type of this problem and solution
//Approach: There are only 2 cases for any element, either it is 
//          included in the sum or not included.
//          We achieve this by a function recurse.


void recurse(vector<vector<int>> &ans,vector<int> res,int arr[],int i,int sum,int n)
    {
        if(sum<0)// base condition
            return;
        if(sum==0){// if desired sum is reached then we push back the result in ans
            ans.push_back(res);
            return;
        }
        if(i>=n)// index out of bound
            return;
        res.push_back(arr[i]);// pushing current element in res 
        recurse(ans,res,arr,i+1,sum-arr[i],n);// recurse by reducing the sum
        res.pop_back();// popping back the added element, so that we can again fill res
        while(i<n-1 && arr[i]==arr[i+1])// checking for alternate solution which doesn't 
            i++;                        // include the current element
        recurse(ans,res,arr,i+1,sum,n);// recusing for alternate solution
    }

int main() {
    int q;cin>>q;// number of queries
    while(q--)
        {
            int n;cin>>n;// size of array
            int arr[n];// declaring the array of size n
            for(int i=0;i<n;i++)// populating the array
                cin>>arr[i];
            int b;cin>>b;
            int sum=b;// desired sum
            sort(arr,arr+n);// sorting cause we need the solution in sorted order
            vector<vector<int>> ans;// vector which stores all possible solutions
            vector<int> res;// vector for storing one solution
            recurse(ans,res,arr,0,sum,n);// calling recurse for the 0th index
            if(ans.size()==0)// if solution set is empty
                cout<<"Empty"<<endl;
            else// if not empty then printing the solutions in given format
                {
                    for(int i=0;i<ans.size();i++)
                        {
                            cout<<"(";
                            for(int j=0;j<ans[i].size();j++)
                                {
                                    if(j!=ans[i].size()-1)
                                        cout<<ans[i][j]<<" ";
                                    else
                                        cout<<ans[i][j]<<")";
                                }
                        }
                    cout<<endl;
                }
            
        }
	//code
	return 0;
}