/*
Question URL: https://leetcode.com/problems/valid-parentheses/description/

Examples:
1. Input: s = "()",  Output: true
2. Input: s = "()[]{}", Output: true
3. Input: s = "(]", Output: false

Approach:
1. Initialize an empty stack 'st' to store opening variables.
2. Initialize an unordered map 'closingToOpening' to store mappings from closing brackets to their corresponding opening brackets.
3. Iterate through each character 'ch' in the input string 's':
    - If 'ch' is an opening bracket ( '(', '{', '[' ), push it onto the stack.
    - If 'ch' is a closing bracket ( ')', '}', ']' ), do the following:
        - Check if the stack is empty. If it is, return false because there's no corresponding opening bracket.
        - Check if the the top of the stack contains the corresponding opening bracket for 'ch' using the 'closingToOpening' map. If they match, pop the opening bracket from the stack.
        - If the opening bracket at the top of the stack does not match the current closing bracket, return false.
4. After the loop, check if the stack is empty. If it is, return true, indicating that the string has valid parentheses. Otherwise, return false because there are unmatched opening brackets.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    unordered_map<char, char> closingToOpening = {
        {')', '('},
        {'}', '{'},
        {']', '['},
    };

    for (char ch : s)
    {
        // Check if the parenthesis are present. If so then push into the stack.
        if (ch == '(' || ch == '{' || ch == '[')
            st.push(ch);

        else if (ch == ')' || ch == '}' || ch == ']')
        {
            // Check if the stack is empty or check whether the top element of the stack doesn't match the corresponding opening bracket for the current closing bracket.
            if (st.empty() || st.top() != closingToOpening[ch])
                return false;

            st.pop();
        }
    }

    return st.empty();
}

int main()
{
    string input = "{[()]}";
    bool isValidParenthesis = isValid(input);

    if (isValidParenthesis)
        cout << "The string is valid." << endl;
    else
        cout << "The string is not valid." << endl;

    return 0;
}