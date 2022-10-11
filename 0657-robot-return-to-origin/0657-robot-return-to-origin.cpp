class Solution {
public:
    bool judgeCircle(string moves) {
        int vCtr = 0, hCtr = 0;
        for(auto it : moves){
            if(it == 'U')
                vCtr++;
            else if(it == 'D')
                vCtr--;
            else if(it == 'L')
                hCtr--;
            else
                hCtr++;
        }
        return(!hCtr && !vCtr);
    }
};