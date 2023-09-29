/*
Question Link : https://leetcode.com/problems/symmetric-tree

This code can be solved via recurssion.
To check if a Binarty tree is symmetric we need to compare the node values and if it is same then we go for left node first and then the right node.
Base case will be when a node doesn't have left OR right node, it returns wether both are NULL or not.
 We check for one and call recursion twice for checking mirror image of BT by doing the following step: solve(left node, right node) && solve(right node, left node)
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
    bool solve(TreeNode* root1, TreeNode* root2)
    {
        if(root1==NULL || root2==NULL)
            return root1==root2;
        
        if(root1->val != root2->val)
            return false;
        
        return solve(root1->left,root2->right) && solve(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        
        return solve(root->left,root->right);
    }
};