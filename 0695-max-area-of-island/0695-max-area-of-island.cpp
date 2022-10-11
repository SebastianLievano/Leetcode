class Solution {
    int m;
    int n;
    int maxArea;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        maxArea = -1;
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j]){
                    maxArea = max(maxArea, area(grid, i, j));
                }
            }
        }
        if(maxArea == -1){
            return 0;
        }
        return maxArea;
        
    }
    
    int area(vector<vector<int>>& grid, int i, int j) {
        //Checking bounds
        if(i < 0 || j < 0 || i >= m || j >= n){
            return 0;
        }
        //Making sure its island
        if(grid[i][j] == 0){
            return 0;
        }
        grid[i][j] = 0;
        int consecutiveAreas = (area(grid, i+1, j) + area(grid, i-1, j) + area(grid, i, j + 1) + area(grid, i, j -1));
        return consecutiveAreas +1;
    }
};