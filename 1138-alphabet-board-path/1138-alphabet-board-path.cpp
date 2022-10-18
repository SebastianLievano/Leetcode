class Solution {
public:
    
    //Returns row of character
    int getRow(char c){
        return (int)(c - 'a')/5;
    }
    
    //Returns column of character
    int getCol(char c){
        return (int)(c-'a')%5;
    }
    
    string horMove(char curr, char goal){
        string move = "";
        int diff = getCol(curr) - getCol(goal);
        char m = (diff < 0) ? 'R':'L';
        diff = abs(diff);
        for(int i = 0; i < diff; ++i) move = move+m;
        return move;
    }
    
    string verMove(char curr, char goal){
        string move = "";
        int diff = getRow(curr) - getRow(goal);
        char m = (diff < 0) ? 'D':'U';
        diff = abs(diff);
        for(int i = 0; i < diff; ++i) move = move+m;
        return move;
    }
    
    //returns a string that is move from curr to goal.
    //Edge case: if goal is z, do horizontal first, else if curr is z, do vertical first.
    string makeMove(char curr, char goal){
        string move = "";
        if(curr == 'z'){
            move = verMove(curr, goal) + horMove(curr, goal) + '!';
        } else {
            move = horMove(curr, goal) + verMove(curr, goal) + '!';
        }
        return move;
    }
    
    string alphabetBoardPath(string target) {
        string ans = makeMove('a', target[0]);
        if(target.length() == 1) return ans;
        for(int i = 0; i < target.length()-1; ++i){
            ans = ans + makeMove(target[i], target[i+1]);
        }
        return ans;
    }
};