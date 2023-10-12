/*
Question Url: https://leetcode.com/problems/number-of-flowers-in-full-bloom

Approach: The code performs a count of currently blooming flowers at various specified times through the following steps:
    - Extracting start and end times from the flowers and sorting them.
    - For each time in the 'people' array, it calculates the number of flowers that started before this time and subtracts the number of flowers that have already finished blooming. The result is the count of flowers currently in bloom.
    - The counts for all times in 'people' are stored and returned as the result.

Time Complexity: O((n + m)logn), where n is the number of flower and m is the number of people
Space Complexity O(n), for creating two extra vectors of start and end
*/

class Solution
{
public:
    vector<int> fullBloomFlowers(vector < vector<int> & flowers, vector<int> &people)
    {
        // Create three vectors to store start time, end time, and the answer.
        vector<int> start, end, ans;

        // Extract start and end times of flower blooming from the 'flowers' vector.
        for (auto &flower : flowers)
        {
            start.push_back(flower[0]); // Store the start time of flower blooming.
            end.push_back(flower[1]);   // Store the end time of flower blooming.
        }

        // Sort both the start and end vectors to efficiently find the number of flowers currently blooming
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        for (auto &i : people)
        {
            // Find the index of the first element in 'start' greater than 'i'.
            int idx1 = upper_bound(start.begin(), start.end(), i) - start.begin();

            // Find the index of the first element in 'end' greater than or equal to 'i'.
            int idx2 = lower_bound(end.begin(), end.end(), i) - end.begin();

            // Calculate the number of flowers currently blooming at time 'i' and add it to the answer.
            ans.push_back(idx1 - idx2);
        }

        return ans; // Return the vector containing the answers for each time in 'people'.
    }
};
