class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        Node* curr = root;
        while(curr != NULL){
            if(curr->left ){
                Node* prev = curr->left;
                while(prev ->right ){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
        // left part NULL
        // curr= root;
        // while(curr!= NULL){
        //     curr->left = NULL;
        //     curr = curr->right;
        // }
    }
};
Time Complexity: O(n)
Auxiliary Space: O(1)
