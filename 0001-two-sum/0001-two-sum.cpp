class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer (2);
        for(int i=0; i < nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if(j!=i){
                    if(nums[j]+nums[i] == target){
                        answer[0]=i;
                        answer[1]=j;
                        return answer;
                    }
                }
                
            }
        }
    return answer;  
    }    
};