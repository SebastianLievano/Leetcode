class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int right = nums.size()-1, left = 0, pivot;
        while(left <= right){
            pivot = left + (right-left)/2;
            if(nums[pivot] == target) return pivot;
            else if(nums[pivot] > target) right = pivot - 1;
            else left = pivot + 1;
        }
        return left;
    }
};