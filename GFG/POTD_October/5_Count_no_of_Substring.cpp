/*
QUESTION: https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1

INTUTION :you just calculate all substrings having at most k characters and then 
subtract it from all subtrings having k-1 characters.

TC=O(s)
SC=O(1)
*/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long solve(string s, int k)
    {
        int i=0,j=0,cnt=0;
        vector<int>mp(26,0);
        long long ans=0;
        
        while(j<s.size()) {
            if(mp[s[j]-'a'] == 0)
                cnt++;
            mp[s[j++]- 'a']++;
            while(cnt>k) {
                if(mp[s[i] - 'a'] == 1)
                    cnt--;
                mp[s[i++]-'a']--;
            }
            ans += (j-i+1);
        }
        return ans;
    }
    long long int substrCount (string s, int k) {
    	//code here.
    	return solve(s,k) - solve(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends