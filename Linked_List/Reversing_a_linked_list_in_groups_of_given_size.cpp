// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct node *reverse (struct node *head, int k);

struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* UTILITY FUNCTIONS */
/* Function to push a node */

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */

     int t;
     cin>>t;
     
     while(t--)
     {
         struct node* head = NULL;
         struct node* temp = NULL;
         int n;
         cin >> n;
         
         for(int i = 0;i<n;i++){
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
         }
        
        int k;
        cin>>k;
        head = reverse(head, k);

        printList(head);
    
     }
     
     return(0);

}

// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/
// This function is to be completed which by us in the question
// this function retunrns the head of the modified linkedlist
struct node *reverse (struct node *head, int k)
{   
    node *prev=NULL,*curr=head,*after=NULL; // we initialize three pointers prev, curr, after
    int a=k; // a is set equal to k, and then a is decresed to 0
    
    while(a-- &&curr!=NULL) // we reverse the list of length untill a==0 and curr is not null
        {
            after=curr->next; // after stores the pointer to the next element in the list
            curr->next=prev;// reverse present element
            prev=curr; // update prev 
            curr=after;// update curr 
        }
    if(after!=NULL) // pointer to the next element is not null
        head->next=reverse(after,k); // then we reverse next sublist of length k
    
    return prev; // we return prev which becomes new head of the current sublist
    // Complete this method
}
