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
    unordered_map<string,int>mp;
    vector<TreeNode*>res;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        mp.clear();
        res.clear();
        serelize(root);
        return res;
    }

    string serelize(TreeNode* root)
    {
        if(!root)return "N";
        string l=serelize(root->left);
        string r=serelize(root->right);
        string curr=to_string(root->val)+","+l+","+r;
        mp[curr]++;
        if(mp[curr]==2)
        {
            res.push_back(root);
        }
        return curr;
    }
};