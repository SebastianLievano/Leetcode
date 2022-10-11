/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    int currIdx;
    std::vector<int> vals;
    
public:
    void loadVals(TreeNode* current){
        if(current == nullptr) return;
        loadVals(current->left);
        vals.push_back(current->val);
        loadVals(current->right);
    }
    
    BSTIterator(TreeNode* root) {
        loadVals(root);
        currIdx = -1;
    }

    int next() {
        currIdx++;
        return vals[currIdx];
    }
    
    bool hasNext() {
        return(currIdx != vals.size()-1);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */