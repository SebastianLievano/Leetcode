class Solution {
private:
    int num;
    int m;
    int n;
    
public:
    int numIslands(vector<vector<char>>& grid) {
        //At each one, add to the number of islands and run a recursive search
        num = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    num++;
                    islandSearch(grid, i, j);
                }
            }
        }
        return num;
        
        
    }
    
    void islandSearch(vector<vector<char>>& grid, int i, int j){
        //Returning if out of bounds
        if(i < 0 || i >= m || j < 0 || j >= n)
            return;
        if(grid[i][j] == '1'){
            grid[i][j] = '0';
            islandSearch(grid, i, j -1);
            islandSearch(grid, i, j + 1);
            islandSearch(grid, i -1, j);
            islandSearch(grid, i+1, j);
        }
    }
};