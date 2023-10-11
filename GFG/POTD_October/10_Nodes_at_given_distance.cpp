/*
QUESTION : https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1

INTUTION : Traverse the tree and search for the target node. If found, keep returning the distance from it to ancestral nodes.
If target is found at distance d in left subtree, then select all nodes at distance k-d in right tree sub tree and vice versa.

Time Complexity: O(N*logN)
Auxiliary Space: O(Height of tree)
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    int findDistance(Node* root, int target, vector<int>& result, int k) {
    if (!root) {
        return -1;
    }

    if (root->data == target) {
        atdistnode(root, result, k);
        return 0;
    }

    int leftDist = findDistance(root->left, target, result, k);
    if (leftDist != -1) {
        if (leftDist + 1 == k) {
            result.push_back(root->data);
        } else {
            atdistnode(root->right, result, k - leftDist - 2);
        }
        return 1 + leftDist;
    }

    int rightDist = findDistance(root->right, target, result, k);
    if (rightDist != -1) {
        if (rightDist + 1 == k) {
            result.push_back(root->data);
        } else {
            atdistnode(root->left, result, k - rightDist - 2);
        }
        return 1 + rightDist;
    }

    return -1;
}

void atdistnode(Node* root, vector<int>& res, int dis) {
    if (!root || dis < 0) {
        return;
    }

    if (dis == 0) {
        res.push_back(root->data);
        return;
    }

    atdistnode(root->left, res, dis - 1);
    atdistnode(root->right, res, dis - 1);
}
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
         vector<int> result;
    findDistance(root, target, result, k);
    sort(result.begin(), result.end());
    return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends