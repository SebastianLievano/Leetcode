class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        int ml = magazine.length(), rnl = ransomNote.length();
        if(rnl > ml) return false;
        for(int i = 0; i < ml; i++){
            map[magazine[i]]++;
        }
        for(int i = 0; i < rnl; i++){
            map[ransomNote[i]]--;
            if(map[ransomNote[i]] < 0) return false;
        }
        return true;
        
    }
};