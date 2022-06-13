class Solution {
    int find_HeightParent(TreeNode* curr,int &parent,int value,int height){
        if(!curr){
            return 0;
        }
        if(curr->val == value){
            return height;
        }
        parent = curr->val;
        int left = find_HeightParent(curr->left,parent,value,height+1);
        if(left)
            return left;
        
        parent = curr->val;
        int right = find_HeightParent(curr->right,parent,value,height+1);
        
        return right;
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        if(root->val == NULL || root->val == y){
            return false;
        }
        int xparent = -1;
        int xHeight= find_HeightParent(root,xparent,x,0);
        int yparent=-1;
        int yHeight = find_HeightParent(root,yparent,y,0);
        
        if(xparent != yparent && xHeight == yHeight){
            return true;
        }
        return false;
        
    }
};
