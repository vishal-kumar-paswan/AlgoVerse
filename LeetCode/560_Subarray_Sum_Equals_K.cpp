/*
Question URL: https://leetcode.com/problems/subarray-sum-equals-k/

Approach:
1. First, we will declare a map to store the prefix sums and their counts.
2. Then, we will set the value of 0 as 1 on the map.
3. Then we will run a loop(say i) from index 0 to n-1(n = size of the array).
4. For each index i, we will do the following:
    a) We will add the current element i.e. arr[i] to the prefix sum.
    b) We will calculate the prefix sum i.e. x-k, for which we need the occurrence.
    c) We will add the occurrence of the prefix sum x-k i.e. mpp[x-k] to our answer.
    d) Then we will store the current prefix sum in the map increasing its occurrence by 1.

Time Complexity: O(n)
Space Complexity: O(n)
*/


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;  
        int count = 0, sum = 0;

        m[0] = 1; 

        for(int i = 0; i < n; i++){
            sum += nums[i];     
            int rem = sum - k; 
            count += m[rem]; 
            m[sum]++;
        }

        return count;
        
    }
};
