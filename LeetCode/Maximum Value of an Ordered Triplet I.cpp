// Problem Link: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/
// Intuition: We want to find the maximum value of (nums[i] - nums[j]) * nums[k] for all possible triplets (i, j, k) where i < j < k.
// To do this, we can use three nested loops to iterate through all possible combinations of (i, j, k).
// For each triplet, we calculate the value (nums[i] - nums[j]) * nums[k] and keep track of the maximum value we've seen so far.
// Time Complexity: O(n^3), where n is the number of elements in the input vector.
// Space Complexity: O(1)

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long value;
        long long maxi = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    value = (long long)(nums[i] - nums[j]) * nums[k];
                    maxi = max(maxi, value);
                }
            }
        }
        
        return maxi;
    }
};
