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
private:
    bool sum(TreeNode* current, std::vector<TreeNode*> path, int sum) {
        int target_sum = current->val;
        for (int i = 0; i < path.size(); i++) {
            target_sum += (path[i])->val;
        }
        if (sum == target_sum) return true;
        return false;
    }

public:
    vector<vector<int> > pathSum(TreeNode *root, int target) {
        if (root == NULL) return std::vector<std::vector<int> >();
        std::vector<std::vector<int> > results;
        std::vector<TreeNode*> nodeptr_stack;
        std::vector<TreeNode*> path_stack;

        nodeptr_stack.push_back(root);
        while(!nodeptr_stack.empty()) {
            TreeNode* current = nodeptr_stack.back();
            nodeptr_stack.pop_back();
            if (current != NULL &&
                    (current->left != NULL || current->right != NULL)) {
                path_stack.push_back(current);
                if (current->right != NULL) {
                    nodeptr_stack.push_back(current->right);
                }
                if (current->left != NULL) {
                    nodeptr_stack.push_back(current->left);
                }
            } else if (current != NULL &&
                    (current->left == NULL && current->right == NULL)
                    && ((path_stack.empty()) || (!path_stack.empty() && ((path_stack.back())->left == current
                        || (path_stack.back())->right == current)))) {
                if (sum(current, path_stack, target) == true) {
                    std::vector<int> result;
                    for (int i = 0; i < path_stack.size(); i++) {
                        result.push_back((path_stack[i])->val);
                    }
                    result.push_back(current->val);
                    results.push_back(result);
                }
            } else if (current != NULL
                    && ((path_stack.back())->left != current
                        || (path_stack.back())->right != current)) {
                path_stack.pop_back();
                while(((path_stack.back())->left != current
                            || (path_stack.back())->right != current)) {
                    path_stack.pop_back();
                }
                path_stack.push_back(current);
                if (current->right != NULL) {
                    nodeptr_stack.push_back(current->right);
                }
                if (current->left != NULL) {
                    nodeptr_stack.push_back(current->left);
                }
            }
        }
        return results;
    }
};
