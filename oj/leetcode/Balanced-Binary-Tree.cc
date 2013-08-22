class Solution {
public:
    int height(TreeNode *root) {
        if (root == NULL) return 0;
        return std::max(height(root->left), height(root->right)) + 1;
    }

    bool isBalanced(TreeNode *root) {
        if (root == NULL) return true;

        while(root != NULL)
        {
            if (std::abs(height(root->left) - height(root->right)) >= 2)
                return false;
            else
                return isBalanced(root->left) && isBalanced(root->right);
        }
    }
};
