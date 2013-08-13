Node *LCA(Node *root, Node *p, Node *q) {
    if (!root || !p || !q) return NULL;
    if (max(p->data, q->data) < root->data)
        return LCA(root->left, p, q);
    else if (min(p->data, q->data) > root->data)
        return LCA(root->right, p, q);
    else
        return root;
}
