class Solution{
    public:
    void solve(Node* root, int k, int &count, vector<int> path){
        if(root==NULL)
            return;
        
        path.push_back(root->data); //adding value of current node value to vector
        
        // left call
        solve(root->left,k,count,path);
        // right call
        solve(root->right,k,count,path);
        
        // checking k sum exist or not
        int size = path.size();
        int sum = 0;
        for(int i = size-1; i >= 0; i--){
            sum += path[i];
            if(sum == k){
                count++;
            }
        }
        path.pop_back();
    }
    

    int sumK(Node *root,int k)
    {
        // code here 
        vector<int> path;
        int count = 0; 
        solve(root,k,count,path);
        
        return count;
    }
};
