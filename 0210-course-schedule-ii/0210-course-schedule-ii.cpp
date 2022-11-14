struct Course{
    int num;
    vector<int> prereqs;
    vector<int> unlocks;
};


class Solution {
    
public:
    bool canTake(vector<bool>& taken, Course& c){
        for(auto it:c.prereqs){
            if(!taken[it]) return false;
        }
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        vector<Course> c(numCourses);
        for(int i = 0; i < numCourses; ++i) c[i].num = i;
        vector<int> order;
        vector<bool> taken(numCourses);
        for(auto it:prereq){
            c[it[0]].prereqs.push_back(it[1]);
            c[it[1]].unlocks.push_back(it[0]);
        }
        queue<int> q;
        for(auto it:c){
            if(it.prereqs.size() == 0){
                q.push(it.num);
                taken[it.num] = true;
                order.push_back(it.num);
            }
        }
        if(q.empty()) return {};
        int curr;
        while(!q.empty()){
            curr = q.front(); q.pop();
            for(auto it:c[curr].unlocks){
                if(taken[it]) continue;
                if(canTake(taken, c[it])){
                    taken[it] = true;
                    order.push_back(it);
                    q.push(it);
                }
            }
        }
        if(order.size() < numCourses) return {};
        return order;
        
    }
};