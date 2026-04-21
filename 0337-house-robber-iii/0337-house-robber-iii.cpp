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
    int rob(TreeNode* root) {
        auto [rt,rs]=solve(root);
        return max(rt,rs);
    }
    pair<int,int>solve(TreeNode* root)
    {
        if(!root)return {0,0};
        auto [lt,ls]=solve(root->left);
        auto [rt,rs]=solve(root->right);
        int take=root->val+ls+rs;
        int notake=max(lt,ls)+max(rt,rs);
        return {take,notake};
    }
};