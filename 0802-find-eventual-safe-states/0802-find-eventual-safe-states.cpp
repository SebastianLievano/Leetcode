class Solution {
    #define SAFE 1
    #define UNSURE 0
    #define NOTSAFE -1
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //If graph[i].size() == 0, it is terminal node
        set<int> safe;
        queue<int> lookAt;
        vector<bool> visited;
        vector<vector<int>> edges;
        //Reversing edges (edges[i] is a list of all nodes with edges to i)
        edges.resize(graph.size());
        for(int i = 0; i < graph.size(); ++i){
            visited.push_back(false);
            for(auto it:graph[i]){
                edges[it].push_back(i);
            }
            if(graph[i].size() == 0){
                lookAt.push(i);
            }
        }
        int node;
        //lookAt is a q of safe nodes (no outgoing nodes). We remove all edges to these nodes from graph,
        //and if the node has no more outgoing edges, we add them to q,
        //No need to change edges[node] as we never go back to it
        while(!lookAt.empty()){
            node = lookAt.front();
            safe.insert(node);
            lookAt.pop();
            visited[node] = true;
            for(auto it : edges[node]){
                //removing the edge (we know it exists)
                if(visited[it]) continue;
                graph[it].erase(lower_bound(graph[it].begin(), graph[it].end(), node));
                if(graph[it].size() == 0) lookAt.push(it);
            }
        }
        vector<int> ans(safe.begin(), safe.end());
        return ans;
        
    }
};