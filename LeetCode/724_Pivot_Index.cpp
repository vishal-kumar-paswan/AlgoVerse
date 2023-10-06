// Problem Link: https://leetcode.com/problems/find-pivot-index/
// Intuition: We are trying to find the pivot index in an array where the sum of all elements to the left of the index is equal to the sum of all elements to the right of the index. To do this, we first calculate the total sum of all elements in the array. Then, we iterate through the array, maintaining two variables: 'prefix' and 'sum'. 'prefix' keeps track of the cumulative sum of elements from the beginning, and 'sum' keeps track of the cumulative sum of elements up to the current index. We check at each index if 'prefix - nums[i] == sum', and if this condition holds true, we return the current index as the pivot index. If no pivot index is found, we return -1.

// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int prefix = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            prefix += nums[i];
        }

        for (int i = 0; i < n; i++) {
            if (prefix - nums[i] == sum) {
                return i;
            }
            sum += nums[i];
            prefix -= nums[i];
        }

        return -1;
    }
};
