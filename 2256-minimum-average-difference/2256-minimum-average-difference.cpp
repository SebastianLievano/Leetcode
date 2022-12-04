class Solution {
public:
    int getDiff(int i, vector<long long int>& nums){
        long long int L, R, n = nums.size();
        L = floor(nums[i]/(i+1));
        if(i+1 == n) R = 0;
        else R = floor((nums.back() - nums[i])/(n-(i+1)));
       // cout << "DIFF at " << i << " is " << abs(L-R) << endl;
        return abs(L-R);
    }
    
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long> pSum(nums.size());
        long long int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            pSum[i] = sum;
        }
        int minDiff = INT_MAX, lowestIdx, newDiff;
        for(int i = 0; i < nums.size(); ++i){
            newDiff = getDiff(i, pSum);
            if(minDiff > newDiff){
                minDiff = newDiff;
                lowestIdx = i;
            }
        }
        return lowestIdx;
    }
};