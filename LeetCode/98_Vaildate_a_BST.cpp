/* Method 1: Using inorder

Intution : We know that the inorder is left-root-Right.
Therefor from from the given root BT, we create a inorder and check if it is sorted order.
IF the inorder is sorted then it indicates that the given binary tree is a valid BST since inorder (LEFT, ROOT, RIGHT) 
else the binary tree is not a Binary search tree

TC = O(logN)
SC = O(N)

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
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);

        for(int i=1;i<ans.size();i++) {
            if(ans[i] <= ans[i-1])
                return false;
        }
        return true;
    }
};

/*
RECURSIVE METHOD -- Using LONG_MIN anmd LONG_MAX
Here we take a max and min value and comare it to the root . We know that the value left to root must be less than root . So it's 
value is limited to (min, current root's value).
Similarly, value right to the root will be greater than root. So it's range will be (current root value, max)

TC= O(n)
TC=O(1)
*/

class Solution {
public: 
    bool solve(TreeNode* root, long min, long max){
        if(root == NULL)   
            return true;
        
        if(root->val <= min || root->val >= max)  
            return false;
        
        return solve(root->left, min, root->val) && solve(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};