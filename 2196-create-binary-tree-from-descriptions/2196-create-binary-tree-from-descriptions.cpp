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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,vector<pair<int,int>>>mp;
        unordered_set<int>st;
        for(auto x:descriptions)
        {
            st.insert(x[1]);
            st.insert(x[0]);
        }
        for(auto x:descriptions)
        {
            mp[x[0]].push_back({x[1],x[2]});
            st.erase(x[1]);
        }
        
        TreeNode* root=new TreeNode(*st.begin());
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int k=q.size();
            while(k--)
            {
                auto x=q.front();
                q.pop();
                for(auto xx:mp[x->val])
                {
                    int child=xx.first;
                    int isleft=xx.second;
                    if(isleft)
                    {
                        x->left=new TreeNode(child);
                        q.push(x->left);
                    }else
                    {
                        x->right=new TreeNode(child);
                        q.push(x->right);
                    }
                }
            }
        }
        return root;
        
    }
};