class Solution {
    
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);            // to mark the end of level
        Node* prev = root;          // to store the last visited node
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            if(!temp){               // we reach the end of one level
                prev->next = NULL;       // make the next pointer of the last node in a level point to NULL
                if(!q.empty()){
                    prev= q.front();        // store the first node of the next upcoming-level
                    q.push(NULL);
                }
                else break;          // if the queue is empty, no more levels to traverse
            }
            else{
                prev->next = temp;            // make the previous node's next pointer point to the current node
                prev = temp;                // make the current node as previous node to be use in the next iteration
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return root;
    }
};
