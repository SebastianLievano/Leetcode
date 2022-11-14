typedef int prodId;

//trie node
struct node{
    node* next[26];
    char c; //Used for printing
    bool end;
    string ends_here;
    
    //Constructor
    node(char ch){
        for(int i = 0; i < 26; ++i){
            next[i] = nullptr;
        }
        end = false;
        ends_here = "";
        c = ch;
    }
    
    //Loads word from given idx into trie
    void loadWord(string word, int idx, string id){
        if(idx == word.length()){
            end = true;
            ends_here = id;
            return;
        }
        int cIdx = word[idx] - 'a';
        if(!next[cIdx]) next[cIdx] = new node(word[idx]);
        next[cIdx]->loadWord(word, idx+1, id);
    }
    
    //Find numToFind strings
    void find(string & word, vector<string> & result){
        //cout << "Finding from " << c << endl;
        if(result.size() == 3) return;
        if(end){
            result.push_back(word);
        }
        for(char c = 'a'; c <= 'z'; c++){
            if(next[c - 'a']){
                word += c;
                next[c-'a'] -> find(word, result);
                word.pop_back();
            }
        }
    }
    
};

class Solution {
    node* head; //Head of trie
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        head = new node('H');
        //Loading words
        for(prodId i = 0; i < products.size(); ++i){
            head->loadWord(products[i], 0, products[i]);
        }        
        vector<vector<string>> ans(searchWord.size());
        //vector<string> dummy;
        string prefix = "";
        node* prefixNode = head;
        int cIdx;
        //finding words
        for(int i = 0; i < searchWord.size(); ++i){
            //dummy.clear();
            prefix += searchWord[i];
            //cout << prefix << endl; 
            cIdx = searchWord[i] - 'a';
            prefixNode = prefixNode -> next[cIdx];
            if(!prefixNode) break;
            prefixNode -> find(prefix, ans[i]);
           // ans.push_back(dummy);
        }
        return ans;
    }
};