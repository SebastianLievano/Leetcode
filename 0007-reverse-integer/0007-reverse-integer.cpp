class Solution {
public:
    int reverse(int x) {
        //Initial val
        int rev = 0;
        while (x != 0) {
            int next_dig = x % 10;
            x /= 10;
            //Checking bounds
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && next_dig > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && next_dig < -8)) return 0;
            //Adding
            rev = rev * 10 + next_dig;
        }
        return rev;
    }
};