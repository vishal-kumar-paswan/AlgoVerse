/*
Question : https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1

INTTUTION : Split the Roman Numeral string into Roman Symbols (character).
 
Convert each symbol of Roman Numerals into the value it represents.
 
Take symbol one by one from starting from index 0:
If current value of symbol is greater than or equal to the value of next symbol, then add this value to the running total.
 
else subtract this value by adding the value of next symbol to the running total.

TC : O(|string|)
SC : O(|string|)

*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
         int n = str.size();
        int ans = 0;
        
        for(int i = 0; i < n; ++ i) {
            if (i < n - 1 && mp[str[i]] < mp[str[i + 1]]) {
                ans -= mp[str[i]];
            }
            else ans += mp[str[i]];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends