/*
QUESTION : https://leetcode.com/problems/search-in-a-binary-search-tree

INTUTION : We will be using a simple approach for this solution.
We start a while loop for condition if the root is not be null and curr val is not equal to required val then untill this condition is not satisfied we compare given value with root . 

Since it is a BST we know that the LHS values are always smaller than root and RHS is greater than root. Therefore, if key is less than current cal wo move to left of tree or else to the right.

TC=O(logN) : In worst case we iterate the full tree i.e. we traverse through the height of tree which is log N
SC=O(1)
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        while(root!=NULL && root->val!=val)
            root= val<root->val ? root->left:root->right;
        return root;
    }
};