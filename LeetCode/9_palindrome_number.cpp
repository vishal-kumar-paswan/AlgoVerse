/*
Question URl: https://leetcode.com/problems/palindrome-number/description/

Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
- Input: x = 121
- Output: true
- Explanation: 121 reads as 121 from left to right and from right to left.


Example 2:
- Input: x = -121
- Output: false
- Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
- Input: x = 10
- Output: false
- Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Approach:
1. The function isPalindrome takes an integer n as input and returns a boolean value indicating whether it is a palindrome or not.

2. First, the code checks if the number is negative or equal to zero. Negative numbers and numbers ending with zero (except for zero itself) cannot be palindromes, so in such cases, the function returns false.

3. The code then uses a while loop to reverse the second half of the number and compares it with the first half. If the reversed second half is equal to the first half, or it is equal to the first half divided by 10 (for odd-length palindromes), the number is a palindrome.

4. In the main function, the user is prompted to input a number, and the isPalindrome function is called with that input. The result is then displayed.

Time Complexity: O(log(n))
*/

#include <iostream>
using namespace std;

bool isPalindrome(int n)
{
    // Negative numbers or equal to zero are not a palindrome numbers
    if (n < 0 || (n % 10 == 0 && n != 0))
        return false;

    int reverseHalf = 0;
    while (n > reverseHalf)
    {
        reverseHalf = reverseHalf * 10 + n % 10;
        n /= 10;
    }

    return n == reverseHalf || n == reverseHalf / 10;
}

int main()
{
    int n; // n is the number
    cout << "Input any number: ";
    cin >> n;

    bool result = isPalindrome(n);
    if (result)
        cout << "Number " << n << " is Palindrome";
    else
        cout << "Number " << n << " is not Palindrome";
    return 0;
}