/*
QUESTION : https://practice.geeksforgeeks.org/problems/floor-in-bst/1
Intuition:
BST has the left element values always smaller than the root values while the data in right nodes are always greater than the root
This property can be used for an optimised solution to the problem. 
So if the root data is less than x then we will move to right node and store its data as the tentative answer 
else move to the left node and whenever we get the root data equal to x then we return root data.

TC = O(n)
SC = O(1)
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends
// Function to search a node in BST.
class Solution{

public:
    int floor(Node* root, int x) {
        // Code here
        if(root==NULL)
            return -1;
        
        int ans=-1;
        
        while(root)
        {
            if(root->data == x)
                return root->data;
            else if(root->data > x)
                root=root->left;
            else
            {
                ans=root->data;
                root=root->right;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    }
}

// } Driver Code Ends