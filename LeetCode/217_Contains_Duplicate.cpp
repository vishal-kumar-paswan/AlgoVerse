/*
Problem Link: https://leetcode.com/problems/contains-duplicate/
Intuition:
- We want to determine if there are any duplicate elements in the input array.
- We can use an unordered_map to store the frequency of each number.
- If we encounter a number with a frequency greater than 1, it means there's a duplicate.
- Iterate through the array, update the frequency map, and check for duplicates.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Create an unordered_map to store the frequency of each number.
        unordered_map<int, int> frequencyMap;
        
        // Iterate through the input vector 'nums'.
        for(int i = 0; i < nums.size(); i++) {
            // Increment the frequency of the current number in the map.
            frequencyMap[nums[i]]++;
        }
        
        // Iterate through the input vector 'nums' again.
        for(int i = 0; i < nums.size(); i++) {
            // If the frequency of the current number is greater than 1, it means there is a duplicate.
            if(frequencyMap[nums[i]] > 1) {
                return true;
            }
        }
        
        // If no duplicates are found, return false.
        return false;
    }
};
