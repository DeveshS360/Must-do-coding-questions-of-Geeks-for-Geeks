/*Structure of the node of the tree is as
struct Node
{
	int data;
	struct Node* left, *right;
};
*/
// complete this function
// return true/false if the is Symmetric or not

// We have to write the isSymmetri function in the problem
/* Approach:  Performing level ordre traveseal and storing the distance of each node
    from the root node, and then finally checking if all positive and negative
    distances have all the same value.
*/
bool isSymmetric(struct Node* root)
{
    if(root==NULL) // if root is null then tree is symmetric
        return true;
    queue<pair<Node*,int>> q; // queue for storing node and its dis
    int vl=0; // distance of root from the root is zero
    q.push({root,vl}); // pushing the root node
    map<int,vector<int>> mp;// map for storing all the node data at particular dis
    mp[vl].push_back(root->data);// pushing the root data in vector of 0 distance
    while(!q.empty()) // perfroming the level ordre traversal of the tree
        {
            Node *temp=q.front().first;
            vl=q.front().second;q.pop();
            if(temp->left)
                {
                    vl--;// if we move left then dis is decreased by 1
                    q.push({temp->left,vl});
                    mp[vl].push_back(temp->left->data);
                    vl++;// in order to set dis again to dis of the temp
                }
            if(temp->right)
                {
                    vl++;// if we move right then dis is increased by 1
                    q.push({temp->right,vl});
                    mp[vl].push_back(temp->right->data);
                    vl--;// to maintain the correct distance of the temp
                }
        }
    for(auto x:mp)
        sort(mp[x.first].begin(),mp[x.first].end()); // sorting all the dis vectors
    for(auto x:mp)
        {   
            if(mp[x.first].size()!=mp[(-1*x.first)].size())// if size is not equal for the symmetric distances
                return false;
            for(int i=0;i<mp[x.first].size();i++)// iterting through both the vectors of symmetric dis
                if(mp[x.first][i]!=mp[(-1*x.first)][i])// if found unequal 
                    return false;
        }
    return true; // finally if all data is same then the tree is symmetric
	// Code here
}