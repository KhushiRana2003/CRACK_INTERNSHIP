class Solution {
    int solve(TreeNode* root, int &maxSum){
        if(root==NULL){
            return 0;
        }
        int l = solve(root->left,maxSum);
        int r = solve(root->right,maxSum);
        maxSum = max(maxSum,l+r+root->val);
        return max(max(l,r)+root->val,0); //returning this maxSum of the path passing from this node, if this sum<0 then ignore this path element..
    }
public:
    int maxPathSum(TreeNode* root) {
        // int sum = 0;
        int maxSum = INT_MIN;
        solve(root,maxSum);
        return maxSum;
    }
};
