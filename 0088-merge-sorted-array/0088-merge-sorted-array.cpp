class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto it = nums1.begin();
        for(int i = 0; i < n; i++){
            while(nums2[i] > *it){
                if(it == nums1.begin() + m){
                    break;
                }
                it++;
            }
            nums1.insert(it, nums2[i]);
            m++;
            nums1.pop_back();
            it = nums1.begin() +i;
        }
        
    }
};