class Solution {
public:
    string tree2str(TreeNode* root) {
        string ans = to_string(root->val);
        if(root->left){
            ans += "(" + tree2str(root->left) + ")";
        }
        
        if(root->right){
            if(!root->left) ans+="()";
            ans += "(" + tree2str(root->right) + ")" ;
        }
        
        return ans;
    }
};

Time complexity: O(n) -> n is number of nodes in the binary tree.
Space complexity: O(h) ->h is the height of the binary tree.
  
