class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long int trueSum = 0, arrSum = 0;
        for(int i = 0; i < nums.size(); ++i){
            trueSum += i+1;
            arrSum += nums[i];
        }
        return (trueSum - arrSum);
    }
};