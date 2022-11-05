struct node{
    node* next[26];
    string endsHere = "";
    bool end;
    
    node(){
        end = false;
        endsHere = "";
        for(int i = 0; i < 26; ++i){
            next[i] = nullptr;
        }
    }
    
    void insert(string word, int idx){
        if(idx == word.length()){
            endsHere = word;
            end = true;
            return;
        }
        int cIdx = word[idx] - 'a';
        if(!next[cIdx]){
            next[cIdx] = new node ();
        }
        assert(next[cIdx]);
        next[cIdx]->insert(word, idx+1);
    }
    
    
};

class Solution {
    set<string> ans;    //Set to store answers
    vector<vector<bool>> vis;   //Visited vector
    int m, n;   //Sizes
public:
    //Search algorithm
    void search(int i, int j, node* last, vector <vector<char>>& board){
        //Checking bounds
        if(i < 0 || i >=m || j < 0 || j >= n){
            return;
        }
        //If visited
        if(vis[i][j]){
            return;
        }
            
        node* tn = last->next[board[i][j]-'a'];
        if(!tn)
            return;
        //If word ends here
        if(tn->end){
            ans.insert(tn->endsHere);
        }
        vis[i][j] = true;
        //Searching adjacents
        search(i+1, j, tn, board);
        search(i-1, j, tn, board);
        search(i, j+1, tn, board);
        search(i, j-1, tn, board);
        vis[i][j] = false;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        node* head = new node();
        m = board.size();
        n = board[0].size();
        vis.resize(m);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                vis[i].push_back(false);
            }
        }
        for(auto it:words){
            head->insert(it, 0);
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                search(i, j, head, board);
            }
        }
        vector<string> vAns (ans.begin(), ans.end());
        return vAns;
        
    }
};