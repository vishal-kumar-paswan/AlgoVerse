/*
Question link: https://leetcode.com/problems/combination-sum/

Example: 
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Approach:
This problem is solved using recursion where if the index element is less than or equals to the target then we will add that element in
the ds vector and call the function again with the same index(as we can take an element multiple number of times) and reduce the
target by the element value(the goal is the make the target zero which means we have attained the goal). While back tracking we have to
remove the last added element from the ds vector as we are looking for other possible solutions to get the target. 
Once the index reaches the last element of the array and the target is attained we will push the ds vector in the ans vector. 
If the target is less then the index element then we will make the function call and skip that element and move to the next element keeping the target unchanged. 

Time Complexity: O(2^t * k) where t is the target, k is the average length
Space Complexity: O(k*x), k is the average length and x is the no. of combinations

*/

class Solution {
void solve(int i, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
    int num = arr.size();
    if (i == num) {
        if (target == 0) {
            ans.push_back(ds);
        }
        return;
    }
    
    // Include the current element arr[i] in the combination
    if (arr[i] <= target) {
        ds.push_back(arr[i]);
        solve(i, target - arr[i], arr, ans, ds);
        ds.pop_back(); // Backtrack by removing the last element
    }
    
    // Exclude the current element arr[i] from the combination
    solve(i + 1, target, arr, ans, ds);
}


public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        solve(0, target, candidates, ans, ds);
        return ans;
    }
};