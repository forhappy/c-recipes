class Solution {
private:
    bool isMirrorOfEachOther(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if ((p != NULL && q == NULL) || (p == NULL && q != NULL)) {
            return false;
        }
        return isMirrorOfEachOther(p->left, q->right)
                && isMirrorOfEachOther(p->right, q->left)
                && (p->val == q->val);
    }

public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return isMirrorOfEachOther(root->left, root->right);
    }
};
