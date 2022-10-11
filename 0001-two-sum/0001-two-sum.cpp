class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); ++i){
            if(m[nums[i]]){
                vector<int> ans {i, m[nums[i]]-1};
                return ans;
            }
            m[target - nums[i]] = i+1;
        }
        return {0,0};
    }    
};