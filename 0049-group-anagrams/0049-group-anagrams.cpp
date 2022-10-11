#include <unordered_set>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_set<string>m;
        string storage;
        vector<string> ansStorage;
        vector<vector<string>> ans ;
        int i;
        vector<string>* a;
        for(int i = 0; i < strs.size(); i++){
            storage = strs[i];
            sort(strs[i].begin(), strs[i].end());
            if(m.count(strs[i])){
                //is anagram of already found
                for(int j = 0; j < ansStorage.size(); j++){
                    if(ansStorage[j] == strs[i]){
                        ans[j].push_back(storage);
                    }
                }
            }
            else{
                //New term
                m.insert(strs[i]);
                ansStorage.push_back(strs[i]);
                a = new vector<string>;
                a->push_back(storage);
                ans.push_back(*a);
            }
        }
        return ans;
        }
};