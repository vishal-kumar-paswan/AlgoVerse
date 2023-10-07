/*
QUESTION : https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1

INTUTION: 
We have to swap two corresponding nodes i.e. if the Linked List is : 1 2 3 4 5 6
Then after swapping it becomes : 2 1 4 3 6 5
So here we swap the current element with nect element and point the current element's next to the next of next of next element
Lets see the iterative code for better understanding
TC =O(n)
SC = O(1)
*/

//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        if(head->next == NULL)
            return head;
        
        Node *prev=head;
        Node *curr=head->next;
        Node *nxt=curr->next;
        Node *head2=curr;
        
        while(true)
        {
            curr->next=prev;
            if(nxt ==NULL || nxt->next==NULL) {
                prev->next = nxt;
                break;
            }
            prev->next = nxt->next;
            
            prev = nxt;
            curr= nxt->next;
            nxt = curr->next;
        }
        return head2;
    }
};

//{ Driver Code Starts.

void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		map<Node*, int> mp;
		mp[head] = head->data;
		for (int i = 0; i<n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
			mp[tail] = tail->data;
		}
		struct Node *failure = new Node(-1);
		Solution ob;
		head = ob.pairWiseSwap(head);
		int flag = 0;
		struct Node *temp = head;
		while(temp){
		    if(mp[temp] != temp->data){
		        flag = 1;
		        break;
		    }
		    temp = temp->next;
		}
		if(flag)
		    printList(failure);
		else
		    printList(head);
	}
	return 0; 
}

// } Driver Code Ends







/*
Recurssive approach for the following concept
*/

class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        if(!head || !head->next) {
            return head;
        }
        Node * temp= head->next;
        head->next = pairWiseSwap(head->next->next);
        temp->next = head;
        return temp;
    }
};