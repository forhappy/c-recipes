/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        std::vector<int> result;
        std::stack<TreeNode*> aux_stack;
        while(root != NULL || !aux_stack.empty()) {
            if (root != NULL) {
                aux_stack.push(root);
                root = root->left;
            } else {
                TreeNode* node = aux_stack.top();
                aux_stack.pop();
                result.push_back(node->val);
                if (node->right != NULL) {
                    root = node->right;
                } else root = NULL;
            }
        }
        return result;
    }

    vector<int> preorderTraversal(TreeNode *root) {
        std::vector<int> result;
        std::stack<TreeNode*> aux_stack;
        while(root != NULL || !aux_stack.empty()) {
            if (root != NULL) {
                result.push_back(root->val);
                aux_stack.push(root);
                root = root->left;
            } else {
                TreeNode *node = aux_stack.top();
                aux_stack.pop();
                root = node->right;
            }
        }
        return result;
    }

};
