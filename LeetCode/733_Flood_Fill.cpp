/*
QUESTION : https://leetcode.com/problems/flood-fill/

INTUTION :
=> The floodFill function takes in a 2D vector image, starting row sr, starting column sc, and a target color.
=> It initializes initialColor with the color of the starting cell.
=> It creates a copy of the original image called ans.
=> It defines the possible movements for the algorithm (delRow and delCol arrays), which are up, right, down, and left.
=> It calls the dfs function to start the flood-fill process. The dfs function performs the following steps:
- Marks the current cell with the new color.
- Checks all neighboring cells for eligibility for color change based on certain conditions.
- Recursively calls itself for eligible neighboring cells.
=> Once the dfs function completes, the modified ans grid is returned.

TC = O(n*m)
SC = O(n*m)
*/

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>&image, int color, vector<vector<int>>&ans,
    int delr[], int delc[], int initial)
    {
        ans[row][col] = color;
        int n=image.size();
        int m=image[0].size();

        for(int i=0;i<4;i++)
        {
            int nr=row +delr[i];
            int nc=col +delc[i];

            if(nr>=0 && nc>=0 && nr<n && nc<m && image[nr][nc]==initial && ans[nr][nc]!=color)
                dfs(nr,nc,image,color,ans,delr,delc,initial);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial = image[sr][sc];
        vector<vector<int>>ans=image;

        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};

        dfs(sr,sc,image, color, ans,delr,delc,initial);

        return ans;
    }
};