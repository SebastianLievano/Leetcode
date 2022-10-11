class Solution {
public:
    int getWrappedCoordinate(int og, int shift, int size){
        int loc = shift + og;
        if(loc < size){
            return loc;
        } else {
            while(loc >= size){
                loc -= size;
            }
            return loc;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        if(nums.size() < 2) return;
        vector<int> ans(nums.size(), 0);
        for(int i = 0; i < nums.size(); ++i){
            ans[getWrappedCoordinate(i, k, nums.size())] = nums[i];
        }
        swap(ans, nums);
    }
};

/*
size = 7 k = 3
0 1 2 3 4 5 6
A B C D E F G
E F G A B C D

n - 7


*/