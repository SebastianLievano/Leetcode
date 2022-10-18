class Solution {
public:
  
    //Reads integer and turns it into appropriate string
    string processInteger(string n){
        string s = "";
        char curr;
        int idx = 0, ctr = 0, l = n.length();
        while(idx < l){ //Iterating through
            curr = n[idx];
            ctr = 1;
            idx++;
            while(idx < l && n[idx] == curr){
                //While character is same, adding to ctr
                ctr++;
                idx++;
            }
            //Adding ctr and character to string end.
            s = s + to_string(ctr) + curr;
        }
        return s;
    }
    
    string countAndSay(int n) {
        string a = "1";
        for(int i = 1; i < n; ++i){
            a = processInteger(a);
        }
        return a;
    }
};