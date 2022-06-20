class Solution {
public:
    void traverseLeft(Node* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            return;
        }
        ans.push_back(root->data);
        if(root->left){
            traverseLeft(root->left,ans);
        }
        else
            traverseLeft(root->right,ans);
    }
    
    void traverseLeaf(Node* root,vector<int> &ans){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
        }
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
        
    }
    
    void traverseRight(Node* root,vector<int> &ans){
        // base cas
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            return ;
        }
        if(root->right){
            traverseRight(root->right,ans);
        }
        else{
            traverseRight(root->left,ans);
        }
        // storing values wapas jaate hue
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        // left print
        traverseLeft(root->left,ans);
        
        // leaf node traverse
        // for left subtree
        traverseLeaf(root->left,ans);
        // for right subtree
        traverseLeaf(root->right,ans);
        
        
        //traverse right part
        traverseRight(root->right,ans);
        
        return ans;
    }
};
