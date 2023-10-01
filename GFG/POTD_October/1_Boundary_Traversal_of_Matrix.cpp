/*
=>This is a very simple problem that can be solved by applying Brute force method
We need to traverse the boundaries from all 4 sides of a matrix in following direction : left->right , top to bottom , right->left, bottom ->up.

=> To do so we just observe the index of a matrix and write different loops to traverse though the edges
1)left to right : simply iterate in 1st row , pick all elements
2)top to down : iterate in last column , leaving the first and last row
3)right to left : simply iterate in last low, pick all elements in reverse (m-1)
4)down to up : iterate in 1st col from last row to first , leaving 1st and last row

=>EDGE CASES : when iterating through (3) & (4) check if n and m are greater than 1 
since the matrix size can be 1*4 or 3*1 in which output will varry.

Time Complexity: O(N + M)
Auxiliary Space: O(N+M)


*/

//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
        vector<int>ans;
        for(int i=0;i<m;i++)
            ans.push_back(matrix[0][i]);
        
        for(int i=1;i<n-1;i++)
            ans.push_back(matrix[i][m-1]);
            
        if(n>1)    
        for(int i=m-1;i>=0;i--)
            ans.push_back(matrix[n-1][i]);
        
        if(m>1)
        for(int i=n-2;i>0;i--)
            ans.push_back(matrix[i][0]);
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends