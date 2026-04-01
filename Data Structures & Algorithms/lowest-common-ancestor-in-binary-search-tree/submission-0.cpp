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
map<TreeNode*, TreeNode*> mp;
map<TreeNode*, int> vis;
void traverse(TreeNode* node, TreeNode* par) {
    if(node == nullptr) return;
    mp[node] = par;
    vis[node] = 0;
    traverse(node->left, node);
    traverse(node->right, node);
}
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traverse(root, nullptr);
        vis[p] = 1;
        vis[q] = 1;
        bool pchain = false;
        while(p != q) {
            if(mp[p]!=nullptr) {
                p = mp[p];
                if(vis[p]) {
                    pchain = true;
                    break;
                }
                vis[p] = 1;
            }
            if(mp[q]!=nullptr) {
                q = mp[q];
                if(vis[q]) {
                    break;
                }
                vis[q] = 1;
            }
        }
        if(pchain) return p;
        return q;
    }
};
