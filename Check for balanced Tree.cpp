// Using brute force :
// height function uses:O(n) ans lly isbalanced function called also uses O(n)
// so total Time Complexity : O(N^2)

class Solution{
    int height(Node* root){
        if(!root){
            return 0;
        }
        int l = height(root->left);
        int r = height(root->right);
        return 1+max(l,r);
    }
    public:
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(!root){
            return true;
        }
        if(abs(height(root->left)-height(root->right))>1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }

};

// Optimized Approach
class Solution{
    public:
    pair<int,int> isBalancedFast(Node* root){
        // base case
        if(root==NULL){
            pair<int,int> p = make_pair(true,0);
            return p;
        }
        pair<int,int> left = isBalancedFast(root->left);
        pair<int,int> right = isBalancedFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = (left.second-right.second) <= 1;
        
        pair<bool,int> ans;
        ans.second = max(left.second,right.second) +1;
        
        if(leftAns && rightAns && diff){
            ans.first = true;
        }
        else{
            ans.first= false;
        }
        return ans;
        
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return isBalancedFast(root).first;
    }
};
