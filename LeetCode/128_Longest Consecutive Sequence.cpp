// Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/
// Intuition: We can solve this problem using an unordered_map to keep track of the presence of each number.
// For each number in the input array, we check if it is the start of a consecutive sequence and find the length of the sequence.
// We update the 'longestconsecutivechain' variable with the maximum length encountered.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> present, checked;
        
        for (auto i : nums) {
            present[i] = true;
        }
        
        int longestconsecutivechain = 0;
        
        for (auto a : nums) {
            if (!checked[a] && !present[a - 1]) {
                int currentchain = 0;
                int start = a;
                
                while (present[start]) {
                    currentchain++;
                    checked[start] = true;
                    start++;
                }
                
                longestconsecutivechain = max(longestconsecutivechain, currentchain);
            }
        }
        
        return longestconsecutivechain;
    }
};

// Time Complexity: O(n), where n is the number of elements in the input array.
// Space Complexity: O(n), as we use two unordered_maps to store the presence and checked status of each number.
