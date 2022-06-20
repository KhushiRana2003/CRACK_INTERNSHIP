class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> res;
    	if(root==NULL){
    	    return res;
    	}
    	queue<Node*> q;
    	q.push(root);
    	bool lr = true;
    	while(!q.empty()){
    	   
    	   int size=q.size();
    	   vector<int> ans(size);
    	   // level process
    	   for(int i = 0; i < size; i++){
    	       Node* frontNode= q.front();
    	       q.pop();
    	       
    	       //normal insert or everse insert.
    	       int index=lr ? i : size-i-1;
    	       ans[index]=frontNode->data;
    	       if(frontNode->left){
    	           q.push(frontNode->left);
    	       }
    	       if(frontNode->right){
    	           q.push(frontNode->right);
    	       }
    	   }
    	   //direction change;
    	   lr = !lr;
    	   for(auto i : ans){
    	       res.push_back(i);
    	   }
    	}
    	return res;
    }
};
