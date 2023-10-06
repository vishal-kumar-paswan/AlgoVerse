// Question Link: https://leetcode.com/problems/brick-wall/
// Intuition: We are trying to find the minimum number of bricks that need to be crossed to go from one end of the wall to the other. To do this, we iterate through each row of the wall, keeping track of the cumulative distance of cracks from the left end of the wall. We use a hashmap to store the count of cracks at each distance. By finding the distance with the maximum number of cracks, we can determine the minimum number of bricks that need to be crossed, which is equal to the total number of rows minus the maximum count of cracks at any distance.

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // Create a hashmap to store the count of cracks at each distance.
        unordered_map<int, int> cracksAtDistanceNumOfRowsHavingCrack;
        
        // Get the total number of rows in the wall.
        int rows = wall.size();
        
        // Initialize 'mini' to the maximum possible value.
        int mini = rows;
        
        // Loop through each row in the wall.
        for (int row = 0; row < rows; row++) {
            int crackDistance = 0; // Distance at which a crack has occurred.
            
            // Loop through the bricks in a particular row.
            // We go up to 'wall[row].size() - 1' because we don't consider the last brick's right edge.
            for (int bricks = 0; bricks < wall[row].size() - 1; bricks++) {
                crackDistance += wall[row][bricks]; // Add the length of the brick where a crack occurred.
                
                // Increment the hashmap with the frequency of the crack distance.
                cracksAtDistanceNumOfRowsHavingCrack[crackDistance]++;
                
                // Update 'mini' with the minimum of maximum bricks that can be passed through
                // and those actually had to be passed through.
                mini = min(mini, rows - cracksAtDistanceNumOfRowsHavingCrack[crackDistance]);
            }
        }
        
        // Return the minimum number of bricks that need to be crossed.
        return mini;
    }
};

// Time Complexity: O(total bricks in the wall)
// Space Complexity: O(maximum number of bricks in a row)
