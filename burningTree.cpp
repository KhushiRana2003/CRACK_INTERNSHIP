

// Time complexity : O(n)
// Space compecity : O(n)
class Solution {
  public:
//   create mapping 
// retune target node

// storing parent of every node
    Node* createParentMapping(Node* root, int target, map<Node*,Node*> &nodeToParent){
        Node* res = NULL;
        queue<Node*> q;
        q.push(root);
        
        nodeToParent[root] = NULL;
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            if(front->data == target){
                res = front;
            }
            
            if(front->left){
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            
            if(front->right){
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
            
            
        }
        
        return res;
    }
    
    int burnTree(Node* root, map<Node*,Node*> &nodeToParent){
        map<Node*,bool> visited;
        queue<Node* > q;
        
        
        q.push(root);
        visited[root]  = true;
        
        int ans = 0;
        
        while(!q.empty()){
            bool flag = 0;
            int size = q.size();
            for(int i =0; i < size; i++){
                // process neigbouring node
                Node* front = q.front();
                q.pop();
                
                if(front->left  && !visited[front->left]){
                    flag =1;
                    q.push(front->left);
                    visited[front->left] = 1;
                }
                
                if(front->right  && !visited[front->right]){
                    flag =1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag =1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]]=1;
                }
            }
            if(flag == 1){
                ans++;
            }
        }
        return ans;
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        // algo : 
        // 1. Create node to parent mapping.
        // 2. find target node
        // 3. burn thre tree in min time
        
        map<Node*,Node*> nodeToParent;
        Node* targetNode = createParentMapping(root,target, nodeToParent);
        
        int ans = burnTree(targetNode, nodeToParent);
        return ans;
    }
};

