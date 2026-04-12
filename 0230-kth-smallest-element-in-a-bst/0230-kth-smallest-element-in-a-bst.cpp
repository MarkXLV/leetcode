class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> stack;
        TreeNode* current = root;
        int count = 0;
        
        while (current != nullptr || !stack.empty()) {
            while (current != nullptr) {
                stack.push(current);
                current = current->left;
            }
            current = stack.top();
            stack.pop();
            count++;
            if (count == k) return current->val;
            current = current->right;
        }
        return -1; // This line should not be reached if k is valid
    }
};