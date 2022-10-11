class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> m;
        m.insert(nums[0]);
        for(int i = 1; i < nums.size(); i++){
        if(m.count(nums[i])) return true;
        else m.insert(nums[i]);
        }
        return false;
    }
};