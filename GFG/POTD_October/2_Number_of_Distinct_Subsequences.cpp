/*
QUESTION : https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1

INTUTION : Solution using DP. We generate the distince subsequence and store its count.

Example - ABCB
Notice that in last B we have 2 duplicate. It is because of the prev B. Understand that the prev B index - 1 contains A.
All the subsequences of A are being counted twice because there are 2 B's. This is why AB was at first B and AB again at last B.
So that is why we need to subtract A's subsequences from last B i.e. 2 subsequences.
output = 8

TC = O(n)
SC = O(n)
*/

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n=s.size();
	    long long dp[n+1]={0};
	    dp[0]=1;
	    vector<int> prev(26,-1);
	    for(int i=1;i<=n;i++){
	        if(prev[s[i-1]-'a']!=-1){
	            dp[i]=2LL*dp[i-1]-dp[prev[s[i-1]-'a']];
	        }
	        else{
	            dp[i]=2LL*dp[i-1];
	        }
	        dp[i]=dp[i]%1000000007;
	        prev[s[i-1]-'a']=i-1;
	    }
	    if(dp[n]<0){
            dp[n]+=1000000007;
        }
	    return dp[n];
	}
};