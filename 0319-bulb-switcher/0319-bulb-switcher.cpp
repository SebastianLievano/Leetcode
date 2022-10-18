class Solution {
public:
    int bulbSwitch(int n) {
        //Each bulb is toggled whenever its divisors appear. 
        //For example, bulb 6 is toggled at the 1,2,3,6, so due to even number of toggles, its off
        //This is because each factor pair toggles it on and then off
        //So only bulbs with an odd number of factors will be on
        //Perfect squares (4, 9 etc..) have an odd number of factors: 4 -> 1,4,2 16 -> 1,2,4,8,16
        //Therefore any perfect square number bulbs will be on after n bulbs, so the sqrt n is solution
        return sqrt(n);
    }
};