class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int counter = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0){
                ++counter;
                // 4 0 5 0 
                // 4 5 0
                nums.erase(nums.begin()+ i);
                i--;
            }
        }
        if(counter){
            nums.push_back(0);
            if(--counter){
                nums.insert(nums.end(), counter, 0);
            }
        }
    }
};