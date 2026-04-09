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
    bool valid(TreeNode* root,long mn,long mx)
    {
        if(!root)return true;
        if(root->val>=mx or root->val<=mn)return false;

        return valid(root->left,mn,root->val) && valid(root->right,root->val,mx);
    }
    bool isValidBST(TreeNode* root) {
        return valid(root,-1e15,1e15);
    }
};