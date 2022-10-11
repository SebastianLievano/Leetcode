class Solution {
public:
    vector<string>ans;
    void sol(int i,unordered_map<char,string>&mp,string op,string digits){
        if(i>=digits.size()){
            ans.push_back(op);
            return;
        }
        string val=mp[digits[i]];
        for(int j=0;j<val.size();j++){
            op.push_back(val[j]);
            sol(i+1,mp,op,digits);
            op.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
      if(digits.size()==0){
          return ans;
      }
        unordered_map<char,string>mp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        string op;
        int i=0;
        sol(i,mp,op,digits);
        return ans;
    }
};