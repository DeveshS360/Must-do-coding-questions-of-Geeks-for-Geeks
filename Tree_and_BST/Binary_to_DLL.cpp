/*struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should convert a given Binary tree to Doubly
// Linked List


// This is a easy question but is a bit tricky since it uses a concept of OOP
//Approach:The idea is to do inorder traversal of the binary tree. While doing 
//inorder traversal, keep track of the previously visited node in a variable say prev. 
//For every visited node, make it next of prev and previous of this node as prev.
// Here prev needs to a static variable
void bToDLL(Node *root, Node **head_ref)// here initially head_ref would be NULL
{
    
    if(root==NULL)// base condition
        return;
    static Node *prev=NULL; // declaring a static variable prev
    bToDLL(root->left,head_ref); // converting the left subtree
    if(*head_ref==NULL){// finding the left most part of the tree and setting it as head_ref
        prev=NULL;// for leftmost part prev would be NULL
        *head_ref=root;
    }
    else // if we are not at leftmost part
        {
            prev->right=root; // next of prev is root
            root->left=prev; // previous of root is prev
        }
    prev=root; // now prev becomes root
    bToDLL(root->right,head_ref); // converting the right subtree to DLL
        
    
    
    
    // your code here
}

