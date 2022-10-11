class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> ss;
        for(auto it : s){
            ss[it]++;
        }
        for(auto it : t){
            ss[it]--;
        }
        for(auto it : ss){
            if(it.second != 0){
                return false;
            }
        }
        return true;
    }
};