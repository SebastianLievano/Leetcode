class Solution {
public:
    string reverseWords(string s) {
        int j = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                j = i;
                while(s[j] != ' ' && j < s.length()){
                    j++;
                }
                reverse(s.begin() + i, s.begin() + j);
                i = j;
            }
        }
        return s;
    }
};