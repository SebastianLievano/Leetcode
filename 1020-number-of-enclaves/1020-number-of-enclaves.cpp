#define NOTEDGE 3
#define EDGE -1
#define VIS_EDGE -2

class Solution {
    vector<vector<int>> dir = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
public:
    bool inBounds(int i, int j){
        return !(i < 0 || i > m -1 || j < 0 || j > n-1);
    }
    
    void propogateEdge(int i, int j, vector<vector<int>>& g){
        //if not in bounds or not a new 1
        if(!inBounds(i,j) || g[i][j] != 1) return;
        g[i][j] = EDGE;
        for(auto it:dir){
            propogateEdge(i + it[0], j + it[1], g);
        }
    }
    
    
    int numEnclaves(vector<vector<int>>& g) {
        m = g.size();
        n = g[0].size();
        int numIso = 0;
        //Changing all lands on edge of board to EDGES
        for(int i = 0; i < m; ++i){
            propogateEdge(i, 0, g);
            propogateEdge(i, n-1, g);
        }
        for(int j = 0; j < n; ++j){
            propogateEdge(0, j, g);
            propogateEdge(m-1, j, g);
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(g[i][j] == 1) numIso++;
            }
        }
        return numIso;
    }
};