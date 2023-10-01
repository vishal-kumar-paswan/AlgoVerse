/*
Question Link: https://leetcode.com/problems/combination-sum-ii/

Example: 
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Approach:

The combinationSum2 function is the entry point of the algorithm. It initializes the result vector to store the resulting combinations, creates an empty path vector to build combinations, and sorts the candidates array for efficient duplicate skipping.

The backtrack function is a recursive helper function that explores combinations. It takes several parameters:

start: The index to start exploring candidates.
target: The remaining target sum to reach.
candidates: The sorted array of candidates.
path: The current combination being built.
result: The vector to store valid combinations.
Within the backtrack function:

If the target becomes zero, it means we found a valid combination, so we add it to the result vector.

We use a for loop to iterate through candidates, starting from the current index start.

We skip duplicate candidates to avoid duplicate combinations. This is done by checking if the current candidate is the same as the previous candidate and whether we're starting from an index greater than start.

If the current candidate is less than or equal to the remaining target, we add it to the path, make a recursive call to continue exploring with the updated parameters, and then backtrack by removing the candidate from the path.

After backtracking, the combinationSum2 function returns the result, which contains all unique combinations of elements that sum up to the target.
*/


class Solution {
    void backtrack(int start, int target, vector<int>& candidates, vector<int>& path, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;  // Skip duplicates to avoid duplicate combinations
            }

            if (candidates[i] <= target) {
                path.push_back(candidates[i]);
                backtrack(i + 1, target - candidates[i], candidates, path, result);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());  // Sort to easily skip duplicates
        backtrack(0, target, candidates, path, result);
        return result;
    }
};
