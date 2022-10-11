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
    int max;
public:
    void calcDepth(int d, TreeNode* node){
        if(!node){
            return;
        }
        max = std::max(d, max);
        d++;
        calcDepth(d, node->left);
        calcDepth(d, node->right);
    }
    
    int maxDepth(TreeNode* root) {
        max = -1;
        if(!root){
            return 0;
        }
        calcDepth(1, root);
        return max;
    }
};