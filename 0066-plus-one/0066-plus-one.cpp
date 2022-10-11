class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        digits[i]++;
        while(digits[i] == 10){
            digits[i] = 0;
            if(i == 0){
                digits.insert(digits.begin(), 1);
                break;
            }
            i--;
            digits[i]++;
        }
        return digits;
    }
};