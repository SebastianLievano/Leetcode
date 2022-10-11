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
    vector<double> sum;
    vector<int> num;
public:
    void addNode(TreeNode* node, int depth){
        if(!node) return;
        if(sum.size() == depth){
            sum.push_back(node->val);
            num.push_back(1);
        } else {
            sum[depth] += node->val;
            num[depth]++;
        }
        depth++;
        addNode(node->right, depth);
        addNode(node->left, depth);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        addNode(root, 0);
        for(int i = 0; i < num.size(); ++i){
            sum[i] = sum[i]/num[i];
        }
        return sum;
    }
};