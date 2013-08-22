class Solution {
private:
    bool hasPathSumImpl(TreeNode *root, int sum) {
        if (root->left == NULL
                && root->right == NULL && root->val == sum) {
                    return true;
        } else if (root->left == NULL && root->right != NULL) {
            return hasPathSumImpl(root->right, (sum - root->val));
        } else if (root->left != NULL && root->right == NULL) {
            return hasPathSumImpl(root->left, (sum - root->val));
        } else if (root->left != NULL && root->right != NULL) {
            return hasPathSumImpl(root->left, (sum - root->val))
                || hasPathSumImpl(root->right, (sum - root->val));
        } else return false;
    }

public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        else return hasPathSumImpl(root, sum);
    }
};
