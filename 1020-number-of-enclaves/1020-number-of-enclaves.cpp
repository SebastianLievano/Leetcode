#define NOTEDGE 3
#define EDGE -1
#define VISITED 2

class Solution {
    vector<vector<int>> dir = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
public:
    bool inBounds(int i, int j){
        return !(i < 0 || i > m -1 || j < 0 || j > n-1);
    }
    
    int numIsolated(int i, int j, vector<vector<int>>&g){
        //If out of bounds or visited or zero, return 0
        if(!inBounds(i, j) || !g[i][j] || g[i][j] == VISITED) return 0;
        
        //If edge, return edge
        if(g[i][j] == EDGE) return EDGE;
        
        int ret, size = 1;
        
        //Marking cell as visited
        g[i][j] = VISITED;
        for(auto it:dir){
            //Recursively searching around island
            ret = numIsolated(i + it[0], j + it[1], g);
            if(ret == EDGE){
                //If any adjacent is an edge, setting this island to edge and returning
                g[i][j] = EDGE;
                return EDGE;
            }
            //If not, adding size of bordering landmass
            else size += ret;
        }
        return size;
    }
    
    
    int numEnclaves(vector<vector<int>>& g) {
        m = g.size();
        n = g[0].size();
        int numIso = 0;
        //Changing all lands on edge of board to EDGES
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                //If grid is a one and on edge, set it as an edge
                if(g[i][j] &&  (j == 0 || j == n-1|| i == 0 || i == m -1))
                    g[i][j] = EDGE;
            }
        }
        int ret;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                //For all ones run search algorithm from their location
                if(g[i][j] == 1){
                    ret = numIsolated(i, j, g);
                    //If search algo does not return as an edge, add size to total
                    if(ret != EDGE) numIso += ret;
                }
            }
        }
        return numIso;
    }
};