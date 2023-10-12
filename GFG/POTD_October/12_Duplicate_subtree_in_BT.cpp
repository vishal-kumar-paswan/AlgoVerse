/*
QUESTION : https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1

INTUTION : 
=> Store the nodes that start with the same value in a vector of nodes using a hashmap except the leaf node(since duplicate tree size should be greater than or equal to 2).
=> Traverse through the map and check in the vector of nodes, are two nodes leading to the same tree, if yes then return 1. 
=> After traversing if we don't find any duplicity return 0.

TC: O(n)
SC: O(n)
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node *root = new Node(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current Node
			currNode->left = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


// } Driver Code Ends
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    bool isLeaf(Node *root)
    {
        return root->left==NULL && root->right==NULL;
    }
    
    bool isSameTree(Node *p, Node *q)
    {
        if(p==NULL || q==NULL)
            return (p==q);
        return ((p->data == q->data) && isSameTree(p->left, q->left) && isSameTree(p->right,q->right));
    }
    
    int dupSub(Node *root) {
         // code here
         unordered_map<int, vector<Node*>> mp;
         if(root==NULL)
            return 0;
         
         queue<Node*>q;
         q.push(root);
         
         while(!q.empty())
         {
             int sz=q.size();
             for(int i=0;i<sz;i++)
             {
                 Node* node = q.front();
                 q.pop();
                 
                 if(!isLeaf(node))
                    mp[node->data].push_back(node);
                 
                 if(node->left)
                    q.push(node->left);
                 if(node->right)
                    q.push(node->right);
             }
         }
         
         for(auto it:mp) {
             vector<Node*> need = it.second;
             for(int i=0;i<need.size();i++)
             {
                 for(int j=i+1;j<need.size();j++)
                 {
                     if(isSameTree(need[i],need[j]))
                     {
                         return 1;
                     }
                 }
             }
         }
         return 0;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		Solution ob;
		cout << ob.dupSub(root) << "\n";
	}
	return 0;
}
// } Driver Code Ends