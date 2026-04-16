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
private:
    std::unordered_set<std::string> subtreeHashes;

    std::string serializeAndHash(TreeNode* node) {
        if (!node) return "#";
        std::string leftHash = serializeAndHash(node->left);
        std::string rightHash = serializeAndHash(node->right);
        std::string currentHash = std::to_string(node->val) + "," + leftHash + "," + rightHash;
        subtreeHashes.insert(currentHash);
        return currentHash;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        std::string subRootHash = serializeAndHash(subRoot);
        subtreeHashes.clear();
        serializeAndHash(root);
        return subtreeHashes.find(subRootHash) != subtreeHashes.end();
    }
};