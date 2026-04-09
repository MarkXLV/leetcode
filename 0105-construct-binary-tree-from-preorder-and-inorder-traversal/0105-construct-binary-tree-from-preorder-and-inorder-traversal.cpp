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
    int preorderindex;
    unordered_map<int,int>index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n=preorder.size();

        preorderindex=0;
        for(int i=0;i<n;i++)
            index[inorder[i]]=i;

        return build(preorder,0,n-1);
    }

    TreeNode* build(vector<int>& preorder,int left,int right)
    {
        if(left>right)return NULL;
        TreeNode* root=new TreeNode(preorder[preorderindex++]);
        int idx=index[root->val];
        root->left=build(preorder,left,idx-1);
        root->right=build(preorder,idx+1,right);
        return root;
    }
};