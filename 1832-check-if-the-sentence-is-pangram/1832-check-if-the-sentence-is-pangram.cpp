class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.length() < 26) return false; //none
        int num = 0;    //Number of unique chars seen
        unordered_set<char> s;
        for(auto it:sentence){
            if(!s.count(it)){
                num++;
                if(num == 26) return true;
                s.insert(it);
            }
        }
        return false;
    }
};