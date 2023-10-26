/*
QUESTION: https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1
INTUTION: The task is to complete the function buildBalancedTree() which takes root as the input argument and returns the root of the tree after converting the given BST into a balanced BST with the minimum possible height. The driver code will print the height of the updated tree in the output itself. 
TC:O(N) 
SC : O(N) 
Here N denotes the total number of nodes in a given BST.
*/
class Solution{
    
    public:
    //You are required to complete this function
    // function should return the root of the modified BST
    void inorder(Node* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    Node* buildtree(vector<int> &ans,int left,int right){
        if(left > right){
            return NULL;
        }
        else{
            int mid= (left + right)/2;
            Node* root=new Node(ans[mid]);
            root->left=buildtree(ans,left,mid-1);
            root->right=buildtree(ans,mid+1,right);
            
        }
    }
    Node* buildBalancedTree(Node* root)
    {
        // Code here
        vector<int> ans;
        inorder(root,ans);
        
        return buildtree(ans,0,ans.size()-1);
        
    }
};
