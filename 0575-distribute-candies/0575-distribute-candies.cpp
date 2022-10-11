class Solution {
public:
    //If numTypes > numAbleTo Eat, return NumAble
    //Else if numAble > numTypes, return NUmTypes
    
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> types;
        //
        for(auto it : candyType){
            types.insert(it);
        }
        return min(candyType.size()/2, types.size());
    }
};