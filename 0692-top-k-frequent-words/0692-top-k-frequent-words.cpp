class Solution {
public:
    bool cmp(pair<string, int>& a, pair<string, int>& b){
        return a.second < b.second;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> f;
        for(auto it : words){
            f[it]++;
        }   
        vector<pair<string,int>> ans;
        for(auto& it : f){
            ans.push_back(it);
        }
        
        //Sorting the vector of pairs with custom comparator. if values are same, then returning lexicographically first string
        sort(ans.begin(), ans.end(), [=](std::pair<string, int>& a, std::pair<string, int>& b)
        {
            if(a.second == b.second) return a.first < b.first;
            if(a.second > b.second){
                return true;
            }
            return false;
        }
        );
        vector<string> fin;
        for(int i = 0; i < k; ++i)
        {
            fin.push_back(ans[i].first);
        }  
        return fin;
    }
};