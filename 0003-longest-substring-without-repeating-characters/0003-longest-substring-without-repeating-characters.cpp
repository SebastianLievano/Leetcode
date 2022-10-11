class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       std::unordered_map<char, int> last;
        int length = 0, maxLength = 0, startIdx = 0;
        for(auto it:s){
            //Bringing start forward until last repeat gone
            while(last[it]){
                last[s[startIdx]]--;
                startIdx++;
                length--;
            }
            length++;
            last[it]++;
            maxLength = max(length, maxLength);
        }
        return maxLength;
    }
};