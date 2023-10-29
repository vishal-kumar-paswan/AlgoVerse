/*
Problem Link: https://leetcode.com/problems/count-vowels-permutation/

Intuition: We want to count the number of valid strings of length 'n' using the vowels 'a', 'e', 'i', 'o', and 'u' with specific rules about which vowels can follow each other.

We use a dynamic programming approach with a 2D array dp where dp[i][j] represents the count of permutations at the i-th position with vowel j.

We initialize the first row of the dp array with all counts set to 1 because we can start with any vowel.

We iterate through the positions in the string (from 1 to n-1) and calculate the count of permutations for each vowel at each position based on the rules. For example, 'a' can follow 'e', 'e' can follow 'a' and 'i', and so on.

Once we've filled the dp array, we sum up the counts for all vowels at the last position (i.e., dp[n-1][0] + dp[n-1][1] + dp[n-1][2] + dp[n-1][3] + dp[n-1][4]) to get the total count of valid permutations for a string of length 'n'.

The final sum represents the answer, which is the count of valid strings of length 'n'.

Time Complexity: O(n^2) , for building all possible valid string to length n.
Space Complexity: O(n^2) , for using dp grid.
*/
class Solution
{
public:
    int countVowelPermutation(int n)
    {
        // Initialize a 2D array to store the count of permutations for each vowel at each position.
        // dp[i][j] represents the count of permutations for the i-th position with vowel j.
        int dp[20001][5];

        // Initialize the first row of dp array. Set all counts to 1 because we start with any vowel.
        for (int i = 0; i < 5; i++)
            dp[0][i] = 1;

        int mod = 1e9 + 7; // Define the modulo value to prevent overflow.

        for (int i = 1; i < n; ++i)
        {
            // Calculate permutations for each vowel at the i-th position based on previous positions.
            dp[i][0] = dp[i - 1][1];                        // 'a' can follow 'e'.
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod; // 'e' can follow 'a' and 'i'.
            dp[i][2] = (((dp[i - 1][0] + dp[i - 1][1]) % mod + dp[i - 1][3]) % mod + dp[i - 1][4]) % mod;
            // 'i' can follow 'a', 'e', 'o', and 'u'.
            dp[i][3] = (dp[i - 1][2] + dp[i - 1][4]) % mod; // 'o' can follow 'i' and 'u'.
            dp[i][4] = dp[i - 1][0];                        // 'u' can follow 'a'.
        }

        // Calculate the total count of permutations for a string of length n by summing all possibilities.
        int sum = 0;
        for (int i = 0; i < 5; ++i)
            sum = (sum + dp[n - 1][i]) % mod;

        return sum;
    }
};
