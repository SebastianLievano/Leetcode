class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return {-1};
        map<int, int> startToIdx; //map of end of interval to index
        for(int i = 0; i < intervals.size(); ++i){  //nlogn
            startToIdx[intervals[i][0]] = i;
        }
        vector<int> ans(intervals.size());
        for(int i = 0; i < intervals.size(); ++i){
            //Getting lower bound in map
            auto right = startToIdx.lower_bound(intervals[i][1]);
            
            //If not found, ans = -1, else answer is idx from map
            ans[i] = (right == startToIdx.end()) ? -1 : right->second;
        }
        return ans;
    }
};