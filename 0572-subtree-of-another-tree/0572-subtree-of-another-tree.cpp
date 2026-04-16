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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        mp.clear();
        string ssub=serelize(subRoot);
        string sroot=serelize(root);
        if(mp[ssub]>1)return true;
        return false; 
    }
    string serelize(TreeNode* root)
    {
        if(!root)return "N";
        string l=serelize(root->left);
        string r=serelize(root->right);
        string c=to_string(root->val)+","+l+","+r;
        mp[c]++;
        return c;
    }

};