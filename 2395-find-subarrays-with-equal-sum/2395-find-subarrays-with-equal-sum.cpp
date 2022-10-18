class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> vals;
        for(int i = 0; i < nums.size()-1; ++i){
            if(vals.count(nums[i]+nums[i+1])) return true;
            vals.insert(nums[i]+nums[i+1]);
        }
        return false;
    }
};