class Solution {
    int m;
    int n;
    string s;
public:
    
    //Recursively searches from vector
    bool searchFrom(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, int next_idx){
        if(next_idx == s.length()){
            return true;
        }
        //marking visited
        visited[i][j] = true;
        //Horizontal searches
        for(int a = i - 1; a < i + 2; a +=2){
            if(a < 0 || a >= m) continue;   //bounds checking
            if(!visited[a][j] && board[a][j] == s[next_idx]){
                //If found later down return true
                if(searchFrom(board, visited, a, j, next_idx+1)) return true;
            }
        }
        
        //vertical searches
        for(int a = j - 1; a < j + 2; a +=2){
            if(a < 0 || a >= n) continue;
            if(!visited[i][a] && board[i][a] == s[next_idx]){
                if(searchFrom(board, visited, i, a, next_idx+1)) return true;
            }
        }
        
        //marking false
        visited[i][j] = false;
        
        return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        //initializing member vars
        s = word;
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> vis;
        vis.resize(m);
        //initializing visited array
        for(int i = 0; i < m;++i){
            vis[i].resize(n);
            for(auto it : vis[i]){
                it = false;
            }
        }
        
        //searching from every square that contains first letter
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == word[0]){
                    if(searchFrom(board, vis, i, j, 1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};