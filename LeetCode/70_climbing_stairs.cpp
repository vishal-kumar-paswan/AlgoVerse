/*
Question URL: https://leetcode.com/problems/climbing-stairs/description/

Examples:
1.
- Input: n = 2
- Output: 2
- Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps

2.
- Input: n = 3
- Output: 3
- Explanation: There are three ways to climb to the top.
    1. 1 step + 1 step + 1 step
    2. 1 step + 2 steps
    3. 2 steps + 1 step


Approach:
1. Create an array dp of size n + 1 to store the number of ways to reach each step.
2. Initialize dp[0] and dp[1] to 1 because there is only one way to climb 0 or 1 step.
3. Use a loop to fill in the dp array from step 2 onwards. For each step i from 2 to n, the number of ways to reach step i is the sum of the number of ways to reach step i - 1 and step i - 2. This is because you can either take one step from step i - 1 or two steps from step i - 2.
4. Finally, return dp[n], which will contain the total number of ways to climb the staircase with n steps.

Time Complexity: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

int main()
{
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    int ways = climbStairs(n);
    cout << "Number of ways to climb " << n << " stairs: " << ways << endl;

    return 0;
}