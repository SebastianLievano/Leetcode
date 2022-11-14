class Solution {
    unordered_map<int, int> rowG, colG;
    unordered_map<int, unordered_set<int>> G;
    unordered_set<int> groups;
    
public:
    void mergeGroups(int a, int b){
      //  cout << "Merge group " << b << " into " << a << endl;
        for(auto it:G[b]){
            //cout << "Moving " << it << endl;
            G[a].insert(it);
            if(it >= 0){
                rowG[it] = a;
            } else {
                colG[(it*-1) - 1] = a;
            }
        }
        groups.erase(b);
    }
    
    void insertRow(int gr, int r){
        G[gr].insert(r);
    }
    void insertCol(int gr, int c){
        G[gr].insert((c+1)*-1);
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int r, c, groupNum = 1;
        for(auto it:stones){
            r = rowG[it[0]];
            c = colG[it[1]];
            if(r && c){ //If both row and column are in a group
                if(r == c) continue;
                //Merge groups
                mergeGroups(r, c);
            } else if (r){
                colG[it[1]] = r;
                insertCol(r, it[1]);
            } else if (c){
                rowG[it[0]] = c;
                insertRow(c, it[0]);
            } else {
                //cout << "New group " << groupNum << endl;
                groups.insert(groupNum);
                rowG[it[0]] = colG[it[1]] = groupNum;
                insertRow(groupNum, it[0]);
                insertCol(groupNum, it[1]);
                groupNum++;
            }
        }
        groupNum = groups.size();
        //cout << "Numgroups: " <<groupNum << endl;
        return stones.size() - groupNum;
    }
};