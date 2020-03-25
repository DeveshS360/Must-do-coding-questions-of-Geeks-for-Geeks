/*Complete the function below
Node is as follows
struct Node{
    int data;
    Node *left, *right;
};
*/
/* Approach: PathSum returns the maximum path sum from a leaf to root
            res variable stores the final answer.
            */
int PathSum(Node *root,int &res){
    if(root==NULL) // base case
        return 0;
    if(!root->left && !root->right)// if both left and right subtree are not there
        return root->data;// then Pathsum becomes the data of root
    int l=PathSum(root->left,res);// value of left subtree PathSum
    int r=PathSum(root->right,res);// Value of right subtree PathSum
    if(root->left && root->right) // If both subtree are present then only we check for 
                                    // change in res, otherwise we don't check
        {
            res=max(res,l+r+root->data);
            return max(l,r)+root->data;
        }
    if(!root->left) // if only right subtree is there
        return r+root->data;// then PathSum becomes root data + PathSum of right subtree
    return l+root->data;//else the same goes for left part
        
}