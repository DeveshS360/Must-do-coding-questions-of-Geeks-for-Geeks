#include <bits/stdc++.h>
using namespace std;

/*Approach: Maintain two priority queues min and max heap, from observation
            we can see that median can be seen as the element which have 
            equal number of elements lesser than it and equal number of elements greater than it.
            So consider max heap before median and min heap after median,
            then we could update the new median by following some rules.
            */


int main() {
    int n;cin>>n; // number in streams
    int a;cin>>a;// first number in a stream
    int med=a; // first number is the initial median
    priority_queue<int> mx; // max heap
    priority_queue<int,vector<int>,greater<int>> mi;// min heap
    mx.push(med);// pushing into max heap(we can push initially into any heap)
    cout<<med<<endl;// printing median
    n--;
    while(n--)// for following numbers in a stream
        {
            int temp;cin>>temp;// inputting the a number one by one
            if(mx.size()>mi.size())// if size of max heap greater than min heap
                {
                    if(temp>med)// if new number is greater than current median
                        {
                            mi.push(temp);// pushing new number into min heap
                        }
                    else// if new number less than or equal to current median
                        {
                            mi.push(mx.top());// removing top of max heap and adding 
                            mx.pop();       // it to max heap
                            mx.push(temp);// pushing new number into max heap 
                        }
                    med=(mx.top()+mi.top())/2;// median is average of both max and min heaps top value
                }
            else if(mi.size()>mx.size())// else if size of min heap greater than max heap
                {
                    if(temp<med)// if new number is lesser than median
                        {
                            mx.push(temp);// pushing new number into max heap
                        }
                    else 
                        {
                            mx.push(mi.top());// pushing top of min heap in max heap
                            mi.pop();// popping max heap
                            mi.push(temp);// pushing new number in min heap
                        }
                    med=(mx.top()+mi.top())/2;// median is average of both
                }
            else// if both the heaps have same size
                {
                    if(temp<med)// if new number is less than the median
                        {
                            mx.push(temp);// pushing the new number in max heap
                            med=mx.top();// median is top of max heap
                        }
                    else// else
                        {
                            mi.push(temp);// pushing the new number in min heap
                            med=mi.top();// median is top of min heap
                        }
                }
            cout<<med<<endl;// printing the median
        }
    return 0;
}