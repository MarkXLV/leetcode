/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout<<data<<endl;
        queue<string>q;
        string token;
        stringstream ss(data);
        while(getline(ss,token,','))
        {
            q.push(token);
        }
        return helper(q);
    }

    TreeNode* helper(queue<string>&q)
    {
        string val=q.front();
        q.pop();
        if(val=="#")return NULL;
        TreeNode* root=new TreeNode(stoi(val));
        root->left=helper(q);
        root->right=helper(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));