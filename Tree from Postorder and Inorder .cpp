void CreateMapping(int in[], map<int,int> &nodeIndexMap, int n){
    for(int i = 0; i < n; i++){
        nodeIndexMap[in[i]] = i;
    }
}
Node* solve(int in[],int post[], int &Index, int inStart, int inEnd, int n, map<int,int> &nodeIndexMap){
        // base case
        if( Index < 0 || inStart > inEnd) {
            return NULL;
        }
        
        int element = post[Index--];
        Node* temp = new Node(element);
        int pos = nodeIndexMap[element];
        // int pos = findPosition(in,element,n);
        // recursive calls
        
        temp->right = solve(in, post, Index, pos+1, inEnd ,n, nodeIndexMap);
        temp->left = solve(in, post, Index, inStart, pos-1,n, nodeIndexMap);
        
        return temp;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postOrderIndex = n-1;
    map<int,int> nodeIndexMap;
    CreateMapping(in,nodeIndexMap,n);
    Node* ans = solve(in,post,postOrderIndex,0,n-1,n,nodeIndexMap);
    return ans;
}
