/*
QUESTION : https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1

INTUTION : We don't need to read input or print anything. Our task is to complete the function findCommon() that takes roots of the two BSTs as input parameters and returns a list of integers containing the common nodes in sorted order. 

TC :O(N1 + N2) where N1 and N2 are the sizes of the 2 BSTs.
SC : O(H1 + H2) where H1 and H2 are the heights of the 2 BSTs.
*/

class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        stack<Node*>s1;
        stack<Node*>s2;
        Node* curr1=root1;
        Node* curr2=root2;
        vector<int>ans;
        while(!s1.empty()||!s2.empty()||curr1||curr2){
            while(curr1){
                s1.push(curr1);
                curr1=curr1->left;
            }
            while(curr2){
                s2.push(curr2);
                curr2=curr2->left;
            }
            
            if(s1.empty()||s2.empty()){
                break;
            }
            curr1=s1.top();
            curr2=s2.top();
            if(curr1->data>curr2->data){
                s2.pop();
                curr2=curr2->right;
                curr1=NULL;
            }
            else if(curr1->data<curr2->data){
                s1.pop();
                curr1=curr1->right;
                curr2=NULL;
            }
            else{
                ans.push_back(curr1->data);
                s1.pop();
                s2.pop();
                curr1=curr1->right;
                curr2=curr2->right;
            }
        }
        
        return ans;
    }
};
