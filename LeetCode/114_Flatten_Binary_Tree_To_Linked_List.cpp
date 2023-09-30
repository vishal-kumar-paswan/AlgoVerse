/*
Question : https://leetcode.com/problems/flatten-binary-tree-to-linked-list
Solution using Using Recursion
TC = O(N)
SC = O(N)

The algorithm steps can be stated as: 

If we observe, we are moving in a reverse postorder way : i.e  right, left, root. 
We take a reference variable (say prev) to store the previous node( initialized to NULL).
Whenever we visit a node, we set the right child to the prev and left child to NULL. 
Next we assign this current node to prev.
We perform the above two operations on all the nodes in the traversal.

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
    void flatten(TreeNode* root) {
        TreeNode *curr=root;
        while(curr)
        {
            if(curr->left)
            {
                TreeNode *prev=curr->left;

                while(prev->right)
                    prev=prev->right;
                prev->right=curr->right;
                curr->right=curr->left;

                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};