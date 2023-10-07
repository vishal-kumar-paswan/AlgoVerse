// Problem Link: https://leetcode.com/problems/two-sum/
// Intuition: We are given an array of integers and a target value. Our goal is to find two numbers in the array that add up to the target.
// To solve this, we use a hashmap to store the values we have seen so far along with their indices. As we iterate through the array,
// for each element, we calculate the remaining value needed to reach the target. If the remaining value exists in the hashmap,
// we have found our pair, and we return their indices. If no pair is found, we continue the iteration.

// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(n) due to the use of a hashmap.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> index_map; // Create a hashmap to store values and their indices.

        for (int i = 0; i < n; i++) {
            int remaining = target - nums[i]; // Calculate the remaining value needed to reach the target.

            // Check if the remaining value exists in the hashmap.
            if (index_map.find(remaining) != index_map.end()) {
                // If found, return the indices of the two numbers that add up to the target.
                return {index_map[remaining], i};
            } else {
                // Otherwise, store the current number and its index in the hashmap.
                index_map[nums[i]] = i;
            }
        }

        // Return an invalid pair if no solution is found.
        return {-1, -1};
    }
};
