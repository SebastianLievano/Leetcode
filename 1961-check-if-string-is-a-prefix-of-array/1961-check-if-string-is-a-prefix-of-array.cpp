class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        bool success = false;
        int idx = 0;
        auto it = words.begin();
        for(int i = 0; i < s.length(); ++i){
            if(idx == it->length()){
                it++;
                idx = 0;
                if(it == words.end()) return false; //If out of words
            }
            if(s[i] != it->at(idx)) return false;
            idx++;
        }
        if(idx != it->length()) return false;
        return true;
    }
};