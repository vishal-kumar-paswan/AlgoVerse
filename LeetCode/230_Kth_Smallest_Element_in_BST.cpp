/*
Question : https://leetcode.com/problems/kth-smallest-element-in-a-bst

Intution : We create a inorder of the BST, which will be sorted due to the propertry of a BST i.e. left < Root < LEFT.
We store the inorder and give the desired element as output

//TC = O(n)
//SC = O(n)
*/

class Solution {
public:
    void inorder(TreeNode *root, vector<int>&ans)
    {
        if(root==NULL)
            return;
        
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        inorder(root,ans);
        return ans[k-1];
    }
};


/*
 Approach 2 : without storing the inorder.
 If we do not store the inorder then we can reduce the complexity .
 To do so we everytime we are at root we reduce the value of k, which will point to the ans when it becomes 0
//TC=O(n)
//SC=O(1)
*/

class Solution {
public:
    int ans;
    void inorder(TreeNode* root, int &k)
    {
        if(root==NULL)
            return;
        inorder(root->left,k);

        if(--k==0) {
            ans= root->val;
            return;
        }

        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};