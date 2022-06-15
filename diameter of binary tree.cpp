class Solution {
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = height(root->left)+height(root->right);
        
        int ans = max(op1,max(op2,op3));
        
        return ans;
    }
};
