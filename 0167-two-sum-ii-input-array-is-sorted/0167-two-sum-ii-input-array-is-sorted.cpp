class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int l = 0, r = numbers.size()-1, sum;
        while(l != r){
            sum = numbers[l] + numbers[r];
            if(sum > target) r--;
            else if(sum < target) l++;
            else if(sum == target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;
            }
        }
        return ans;
    }
};


