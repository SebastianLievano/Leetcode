class Solution {
public:
    //Returns vector of all adjacent strings in words
    //Seems inefficient but is 25*10 -> 250 checks per word
    //Well bounded
    vector<string> getAdj(string w, unordered_set<string>& words){
        vector<string> ans;
        string dummy = w;
        for(int i = 0; i < w.length(); ++i){
            for(char c = 'a'; c <= 'z'; ++c){
                if(c == w[i]) continue;
                dummy[i] = c;
                if(words.count(dummy)) ans.push_back(dummy);
            }
            dummy[i] = w[i];
        }
        return ans;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> words(wordList.begin(), wordList.end());
        unordered_map<string, int> dist; string curr;
        q.push(beginWord);
        dist[beginWord] = 1;
        words.erase(beginWord);
        while(!q.empty()){
            curr = q.front(); q.pop();
            for(auto it:getAdj(curr, words)){
                words.erase(it);
                q.push(it);
                dist[it] = dist[curr]+1;
                if(it == endWord) return dist[it];
            }
        }
        return dist[endWord];
    }
};