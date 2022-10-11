class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, currentMax = 0;
        for(auto c : nums){
            currentMax = max(c, currentMax + c);
            maxSum = max(maxSum, currentMax);
        }
        return maxSum;
    }
};