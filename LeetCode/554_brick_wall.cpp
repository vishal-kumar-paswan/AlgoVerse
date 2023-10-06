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

