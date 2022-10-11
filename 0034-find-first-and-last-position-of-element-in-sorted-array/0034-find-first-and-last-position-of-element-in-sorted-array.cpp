class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //Binary search
        auto low = lower_bound(nums.begin(),  nums.end(), target);
        if(low == nums.end() || *low != target) return {-1,-1};
        int l = low - nums.begin();
        int h = l;
        while(h < nums.size() && nums[h] == target){
            h++;
        }
        h--;
        return {l,h};
    }
};