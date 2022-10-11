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
    int target;
public:
    void addToPath(TreeNode* node, vector<int> path, int currentSum){
        if(node == nullptr) return;
        if(node->left == nullptr && node->right==nullptr){
            if(currentSum + node->val == target){
                path.push_back(node->val);
                ans.push_back(path);
            }
            return;
        }
        currentSum += node->val;
        path.push_back(node->val);
        addToPath(node->left, path, currentSum);
        addToPath(node->right, path, currentSum);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};;
        vector<int> start {root->val};
        target = targetSum;
        if(root->left == nullptr && root->right == nullptr){
            if(root->val == targetSum){
                ans.push_back({root->val});
            }
        }
        addToPath(root->left, start, root->val);
        addToPath(root->right, start, root->val);
        return ans;
    }
};