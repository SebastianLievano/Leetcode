class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> neg_vals;
        int maxFound = -1;
        for(auto it : nums){
            if(it < 0){
                neg_vals.insert(it);
            }
        }
        for(auto it : nums){
            if(it > maxFound && neg_vals.count((it*-1))){
                maxFound = it;
            }
        }
        return maxFound;
    }
};