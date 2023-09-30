

/*
Question : https://leetcode.com/problems/valid-palindrome/

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

solution using two pointer approach
TC = O(N)
SC = O(1)


*/

class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        int i=0;
        while(s[i]!='\0'){
            if((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122)||(s[i]>=48&&s[i]<=57)){
                t+=tolower(s[i++]);
            }
            else{
                i++;
            }
        }
        // t[j]='\0';
        cout<<t;
        i=0;
        int n=t.size()-1;
        while(i<=n){
            if(t[i]!=t[n])
                return false;
            i++;
            n--;
        }

        return true; 
    }
};