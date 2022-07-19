// recursive way
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    if(root->data > x) 
        return searchInBST(root->left,x);
    if(root->data < x)
        return searchInBST(root->right,x);
    
}

// Iterative Way 
BinaryTreeNode<int> *temp = root;
    while(temp != NULL){
        if(temp->data == x)
            return true;
        
        if(temp->data > x)
            temp = temp->left;
        else
            temp=temp->right;
    }
    return false;
