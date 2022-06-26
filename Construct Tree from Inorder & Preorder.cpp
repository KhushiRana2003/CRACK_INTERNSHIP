// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    // int findPosition(int in[], int element,int n){
    //     // whether of using this function we create a map and find index from there 
    //     for(int i = 0; i < n; i++){
    //         if(in[i] == element){
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
    void CreateMapping(int in[], map<int,int> &nodeIndexMap, int n){
        for(int i = 0; i < n; i++){
            nodeIndexMap[in[i]] = i;
        }
    }
    
    Node* solve(int in[],int pre[],int &Index, int inStart, int inEnd, int n, map<int,int> &nodeIndexMap){
        // base case
        if( Index >= n || inStart > inEnd) {
            return NULL;
        }
        
        int element = pre[Index++];
        Node* temp = new Node(element);
        int pos = nodeIndexMap[element];
        // int pos = findPosition(in,element,n);
        // recursive calls
        
        temp->left = solve(in, pre, Index, inStart, pos-1,n, nodeIndexMap);
        temp->right = solve(in, pre, Index, pos+1, inEnd ,n, nodeIndexMap);
        
        return temp;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex = 0;
        map<int,int> nodeIndexMap;
        CreateMapping(in,nodeIndexMap,n);
        Node* ans = solve(in,pre,preOrderIndex,0,n-1,n,nodeIndexMap);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends
