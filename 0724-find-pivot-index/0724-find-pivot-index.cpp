class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //Maintain left side sum and right side sum. As we move pivots, add to left, or right
        int L = 0, R = 0;
        for(int i = 1; i < nums.size(); ++i){
            R += nums[i];
        }
        if(R == 0) return 0;
        for(int i = 1; i < nums.size(); ++i){
            L += nums[i - 1];
            R -= nums[i];
            if(L == R) return i;
        }
        return -1;
    }
};