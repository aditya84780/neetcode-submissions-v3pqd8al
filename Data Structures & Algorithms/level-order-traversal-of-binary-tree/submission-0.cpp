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
public:
map<int, vector<int>> mp;
    void dfs(TreeNode* node, int dep) {
        if(!node) return;
        mp[dep].push_back(node->val);
        dfs(node->left, dep+1);
        dfs(node->right, dep+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 1);
        vector<vector<int>> ans;
        for(auto v: mp) {
            ans.push_back(v.second);
        }
        return ans;
    }
};
