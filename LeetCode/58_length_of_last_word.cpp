/*
Question URL: https://leetcode.com/problems/length-of-last-word/description/

Examples:
1. Input:
    - s = "Hello World"
    - Output: 5
    - Explanation: The last word is "World" with length 5.

2. Input:
    - s = "   fly me   to   the moon  "
    - Output: 4
    - Explanation: The last word is "moon" with length 4.

3. Input:
    - s = "luffy is still joyboy"
    - Output: 6
    - Explanation: The last word is "joyboy" with length 6.


Approach:
1. It defines a function lengthOfLastWord that takes a single string s as its argument.
2. It initializes two variables, length and i. length is used to store the length of the last word, and i is used as an index to traverse the string from right to left.
3. The code enters a while loop to skip any trailing spaces at the end of the string. It decrements i while the character at position i in the string is a space.
4. After skipping the trailing spaces, it enters another while loop. This loop counts the length of the last word by incrementing the length variable and decrementing i while the character at position i is not a space.
5. Finally, it prints the length of the last word to the console.

Time Complexity: O(n)
*/

#include <iostream>
using namespace std;

string lengthOfLastWord(string s)
{
    int length = 0;
    int i = s.length() - 1;

    // Check if there is any space, skip the trailing space.
    while (i >= 0 && s[i] == ' ')
        i--;

    // Count the length of the word.
    while (i >= 0 && s[i] != ' ')
    {
        length++;
        i--;
    }

    cout << "Length of the last word: " << length << endl;
}

int main()
{
    string str = "Hello World";
    lengthOfLastWord(str);
    return 0;
}