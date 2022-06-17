class Solution {
    int minCameraCoverBT(TreeNode* root) {
        if(root==NULL){
            return 1;
        }
        int leftAns = minCameraCoverBT(root->left);
        int rightAns = minCameraCoverBT(root->right);
        
        if(leftAns == -1 || rightAns == -1){
            cameras++;
            return 0;
        }
        
        if(leftAns == 0 || rightAns == 0){
            return 1;
        }
        return -1;
    }
public:
    int cameras =0;
    int minCameraCover(TreeNode* root) {
        if(minCameraCoverBT(root)==-1) cameras++;
        
        return cameras;
    }
};
