class Solution {
public:
int divide(int dividend, int divisor) {
long long int ans = (long int)dividend/divisor;
if(ans>INT_MAX)
return INT_MAX;
if(ans<INT_MIN)
return INT_MIN;
return ans;

}
};