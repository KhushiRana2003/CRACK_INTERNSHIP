/*Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.

An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

*/

class Solution
{
    public:
    pair<bool,int> isSumTreeFast(Node* root){
        
        if(root==NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        if(root->left == NULL && root->right==NULL){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int> leftAns = isSumTreeFast(root->left);
        pair<bool,int> rightAns = isSumTreeFast(root->right);
        
        bool left = leftAns.first;
        bool right = rightAns.first;
        bool cndtn = root->data == leftAns.second+rightAns.second;
        
        pair<bool,int> ans;
        if(left & right && cndtn){
            ans.first=true;
            ans.second= 2*root->data;
        }
        else{
            ans.first=false;
        }
        return ans;
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         return isSumTreeFast(root).first;
    }
};
