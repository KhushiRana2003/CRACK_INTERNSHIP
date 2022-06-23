// Ist Approach

void solve(Node *root,vector<int>temp,vector<int>&ans,int node){
    if(root==NULL)return;
   
    temp.push_back(root->data);
    if(root->data==node){
        
        ans=temp;return;
    }
    solve(root->left,temp,ans,node);
    solve(root->right,temp,ans,node);
    temp.pop_back();
    
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    vector<int>ans,temp;
    solve(root,temp,ans,node);
    if(k+1>ans.size())return -1;
    reverse(ans.begin(),ans.end());
    return ans[k];
}


// 2nd Approach


Node* solve(Node* root,int &k, int &node){
    if(root==NULL)
        return NULL;
    
    if(root->data == node)
        return root;
        
    Node* leftAns = solve(root->left,k,node);
    Node* rightAns = solve(root->right,k,node);
    
    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k <= 0){
            k=INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k <= 0){
            k=INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node* ans = solve(root,k,node);
    if(ans == NULL || ans->data == node){
        return -1;
    }
    
    return ans->data;
    
}
