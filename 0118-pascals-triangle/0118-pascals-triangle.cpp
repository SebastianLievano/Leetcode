class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        vector<int> newRow(1);
        newRow[0] = 1;
        ans[0] = newRow;
        
        for(int i = 1; i < numRows; i++){
            vector<int> newRow(i+1);
            newRow[0] = 1;
            newRow[i] = 1;
            for(int j = 1; j < i; j++){
                // 1 2 1
                //1 3 3 1 for 3: = 
                newRow[j] = (ans[i-1][j-1] + ans[i-1][j]);
            }
            ans[i] = newRow;
        }
        return ans;
    }
};