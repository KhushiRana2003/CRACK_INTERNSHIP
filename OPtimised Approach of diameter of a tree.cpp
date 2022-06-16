
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// time complxity : O(N)
class Solution {
    pair<int,int> diameterFast(Node* root){
        if(root==NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second+right.second+1; 
        
        pair<int,int> ans ;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
        
        return ans;
    }
  public:
    // Function to return the diameter of a Binary Tree.
        int diameter(Node* root){
            return diameterFast(root).first;
        }
    
};

/*
2nd Way : time Complexity : O(N^2)
class Solution {
    int height(Node * root){
        if(root==NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right)); 
    }
  public:
    // Function to return the diameter of a Binary Tree.
        int diameter(Node* root){
            if(root==NULL){
                return 0;
            }
            int op1=diameter(root->left);
            int op2 = diameter(root->right);
            int op3 = height(root->left) + height(root->right)+1;
            
            int ans = max(op1,max(op2,op3));
            
            return ans;
        }
    
};
*/

/*
Ist Way : Time Complexity : O(n^2);

int height(Node * root){
        if(root==NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right)); 
    }
    public:
    int diameter(Node* root) {
        // Your code here
        if(root==NULL){
            return 0;
        }
        return max((1+height(root->left)+height(root->right)),max(diameter(root->left),diameter(root->right)));
*/
