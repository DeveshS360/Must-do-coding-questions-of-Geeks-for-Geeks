// { Driver Code Starts
#include<iostream>
#include<stdio.h>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int intersectPoint(struct Node* head1, struct Node* head2);

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;

        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }

        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{   
    if(head1==NULL || head2==NULL) // if either of the list is empty then no common node
        return -1;
    int n1=1,n2=1; // else minimum length of both lists is 1
    Node *a=head1; // pointer to head of list1
    while(a->next) // while we reach the end of list 1 to get the length of list1
        {
            n1++; // 
            a=a->next;
        }
    a=head2; // pointer to the head of list2
    while(a->next) // same as list1 to get length of list2
        {
            n2++;
            a=a->next;
        }
    if(n1>n2) // now if the length of list1 is greter than the lengtht of list2
        {       
            a=head1; 
            for(int i=0;i<n1-n2;i++) // then we traverse list 1 until remaining length of both are same
                a=a->next;
            Node *b=head2;
            while(a->next && b->next) // now we traverse both lists simultaneously
                {
                    if(a==b) // if we find a common node or intersection point
                        return a->data; // we return the data associated with that node
                    a=a->next;
                    b=b->next;
                }
        }
    if(n2>n1) // similarly if length of list2 is greater, then we follow the same above steps,
        {
            a=head2;
            for(int i=0;i<n2-n1;i++)
                a=a->next;
            Node *b=head1;
            while(a->next && b->next)
                {
                    if(a==b)
                        return a->data;
                    a=a->next;
                    b=b->next;
                }
        }
    else // else if length of both the lists are same, then we directly traverse both
        { // the lists simultaneously
            a=head1;
            Node *b=head2;
            while(a->next && b->next)
                {
                    if(a==b)
                        return a->data;
                    a=a->next;
                    b=b->next;
                }
        }
    return -1;
        
    // Your Code Here
}

