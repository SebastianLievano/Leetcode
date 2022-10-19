class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        bool g1 = true, g2 = true;
        //sorting
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        //if either is less than, it can no longer break the other
        for(int i = 0; i <s1.length(); ++i){
            if(s1[i] == s2[i]) continue;
            if(s1[i] > s2[i]) g2 = false;
            else g1 = false;
        }
        //if either one was always greater or equal to, return true
        return (g1 || g2);
    }
};