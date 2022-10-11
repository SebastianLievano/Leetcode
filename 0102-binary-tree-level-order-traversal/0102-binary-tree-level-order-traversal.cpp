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
    vector<vector<int>> ans;
public:
    void insertLvls(int depth, TreeNode* ptr){
        if(!ptr) return;
        if(ans.size() == depth){
            ans.push_back({ptr->val});
        }
        else{
            ans[depth].push_back(ptr->val);
        }
        insertLvls(depth+1, ptr->left);
        insertLvls(depth+1, ptr->right);
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        ans.push_back({root->val});
        insertLvls(1, root->left);
        insertLvls(1, root->right);
        return ans;
    }
};