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
class Solution {
private:
    string ans = "Empty";
    
public:
    //Returns if node is a leaf or not
    bool isLeaf(TreeNode* node){
        return(!node->left && !node->right);    
    }
    
    //searches from node, string is passed down and extended.
    void search(TreeNode* node, string s){
        if(!node) return;
        s = (char)(node->val + 'a') + s;    //concatenating to string
        if(isLeaf(node)){
            //If leaf string and less than ans, adding
            if(s < ans || ans == "Empty") ans = s;
            return;
        }
        search(node->right, s);
        search(node->left, s);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        search(root, "");
        return ans;
    }
};