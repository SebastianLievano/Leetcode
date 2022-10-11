class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int minVal = matrix[0][cols-1], ansRow = -1, ansCol = -1;
        for(int i = 0; i < rows; i++){
           if(matrix[i][cols-1] >= target){
               ansRow = i;
               break;
           }
        }
        if(ansRow == -1){
            return false;
        }
        return binary_search(matrix[ansRow].begin(), matrix[ansRow].end(), target);
    }
};