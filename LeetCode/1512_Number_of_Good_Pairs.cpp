// Problem Link: https://leetcode.com/problems/number-of-good-pairs/
// Intuition: We can solve this problem using an unordered_map to keep track of the frequency of each number.
// For each number in the array, we check how many times it has appeared before and add that count to the 'count' variable.
// Then, we increment the frequency of the current number in the unordered_map.
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> map; // Create an unordered_map to store the frequency of each number.
        int count = 0; // Initialize a variable to count the number of good pairs.
        int n = nums.size(); // Get the total number of elements in the input array.

        for (int i = 0; i < n; i++) {
            if (map.find(nums[i]) != map.end()) {
                count += map[nums[i]]; // Add the count of previous occurrences of the current number.
                map[nums[i]]++; // Increment the frequency of the current number in the unordered_map.
            } else {
                map[nums[i]] = 1; // If the number is not in the unordered_map, initialize its frequency to 1.
            }
        }
        return count;
    }
};
// Time Complexity: O(n), where n is the number of elements in the input array.
// Space Complexity: O(n), as we use an unordered_map to store the frequency of each number.
