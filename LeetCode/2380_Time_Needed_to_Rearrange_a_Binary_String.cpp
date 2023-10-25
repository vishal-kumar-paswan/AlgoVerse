/*
Question: https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string

Intutuion:  The final string will be of the form 111...000....
- The total number of time taken for a '1' to reach its final position is number of '0's to its left + number of turns it waits.
- Every time we come across two consequetive ones, the waiting time increases by one.
- Everytime we come acress two consequetive zeroes, the waiting time decreases by one.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution
{
public:
    int secondsToRemoveOccurrences(string s)
    {
        int waitingTime = 0;
        int zeroCount = 0;
        int lastOcc = s.rfind('1');

        for (int i = 0; i <= lastOcc; i++)
        {
            // Increase waiting time if we come across 2 consecutive 1's
            // However, if there are no zeroes to the left, then there is no waiting time
            if (i > 0 && s[i] == '1' && s[i - 1] == '1' && zeroCount > 0)
                waitingTime += 1;

            // Decrease waiting time if we come across 2 consecutive 0's
            if (i > 0 && s[i] == '0' && s[i - 1] == '0' && waitingTime > 0)
                waitingTime -= 1;

            if (s[i] == '0')
                zeroCount += 1;
        }

        return zeroCount + waitingTime;
    }
};