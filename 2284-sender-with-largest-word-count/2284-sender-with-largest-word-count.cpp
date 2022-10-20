class Solution {
public:
    //num words in a message is number of spaces + 1
    int getNumWords(string& mssg){
        int sum = 0;
        for(auto it : mssg){
            if(it == ' ') sum++;
        }
        return sum+1;
    }
    
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> words;
        for(int i = 0; i < messages.size(); ++i){
            words[senders[i]] += getNumWords(messages[i]);
        }
        string top = "";
        int most = -1;
        //Iterate through map. If most words, or equal num words and lexicographically larger, set new max to compare to
        for(auto it : words){
            if(it.second > most ||(it.second == most && it.first > top) ){
                top = it.first;
                most = it.second;
            }
        }
        return top;
    }
};