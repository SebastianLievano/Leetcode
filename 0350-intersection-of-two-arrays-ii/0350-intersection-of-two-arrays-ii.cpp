class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++){
            map[nums1[i]]++;
        }
        for(int j = 0; j < nums2.size(); j++){
            if(map[nums2[j]]){
                ans.push_back(nums2[j]);
                map[nums2[j]]--;
            }
        }
        return ans;
    }
};