/*
QUESTION: https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1

INTUTION:
To convert a positive integer into its corresponding Excel column title, we need to perform a base-26 conversion.
In this conversion, we consider 'A' as 1, 'B' as 2, ..., 'Z' as 26. However, in Excel's numbering system.
If the remainder is not 0, it corresponds to 'A' + (remainder - 1).we have to convert the number from base 10 to the base 26.
We will do this by using recursion by calling the recursion for smaller numbers(i.e n/26).

Implementation:
The base case of the recursion is when n is 0. In this case, an empty string is returned.
The loop calls itself with n / 26 to handle the quotient, and (char) (--n % 26 + 'A') is appended to the result.
n / 26 calculates the quotient, and the function is called with this value.
--n % 26 + 'A' calculates the remainder, decrements it by 1 (to make it 0-based), adds 'A' to convert it to the corresponding character.

TC = O(log N)
SC = O(n)

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans="";
        while(n-- > 0)
        {
            ans.push_back((char)'A' + n%26);
            n=n/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends