class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int aplusb;
        
        //Rule for triangle is sum of two smaller sides is greater than longest side
        for(int i = nums.size()-1; i > 1; --i){
            aplusb = nums[i-1] + nums[i-2];
            if(nums[i] < aplusb)
                return nums[i] + aplusb;
        }
        return 0;
    }
};