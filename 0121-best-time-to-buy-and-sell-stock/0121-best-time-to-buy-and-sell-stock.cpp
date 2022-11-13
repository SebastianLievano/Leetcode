class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0, minEl = INT32_MAX;
        for(auto it:prices){
            minEl = min(minEl, it);
            maxPro = max(maxPro, it-minEl);
        }
        return maxPro;
    }
};