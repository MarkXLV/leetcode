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
    unordered_map<int,int>index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n=preorder.size();

        for(int i=0;i<n;i++)
            index[inorder[i]]=i;

        return build(preorder,inorder,0,n-1,0,n-1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int ins,int ine,int prs,int pre)
    {
        if(ins>ine or prs>pre)return NULL;
        TreeNode* root=new TreeNode(preorder[prs]);
        int idx=index[preorder[prs]];
        root->left=build(preorder,inorder,ins,idx-1,prs+1,prs+(idx-ins));
        root->right=build(preorder,inorder,idx+1,ine,prs+(idx-ins)+1,pre);
        return root;
    }
};