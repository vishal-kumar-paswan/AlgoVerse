/*
QUESTION : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

INTUTION: We will be solving this problem using the Level Order Traversal.
To solve this problem, we substitute node 3’s left child with some value to indicate that the left child is missing. 
So we can substitute with any character except for a number since the node values are numbers already, we would get confused.

The character that we are going to use to substitute is “#”.
TC :O(n) + O(n) = O(N
SC=O(1)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()) {
            TreeNode *curr=q.front();
            q.pop();
            if(curr==NULL)
                s.append("#,");
            else
                s.append(to_string(curr->val)+',');
            if(curr!=NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return NULL;
        
        stringstream s(data);
        string str;

        getline(s,str,',');
        TreeNode *root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode *node=q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#")
                node->left=NULL;
            else {
                TreeNode *leftNode=new TreeNode(stoi(str));
                node->left=leftNode;
                q.push(leftNode);
            }

            getline(s,str,',');
            if(str=="#")
                node->right=NULL;
            else {
                TreeNode *rightNode=new TreeNode(stoi(str));
                node->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));