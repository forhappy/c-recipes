// http://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical/
// sameTree(tree1, tree2)
// 1. If both trees are empty then return 1.
// 2. Else If both trees are non -empty
//      (a) Check data of the root nodes (tree1->data ==  tree2->data)
//      (b) Check left subtrees recursively  i.e., call sameTree(
//           tree1->left_subtree, tree2->left_subtree)
//      (c) Check right subtrees recursively  i.e., call sameTree(
//           tree1->right_subtree, tree2->right_subtree)
//      (d) If a,b and c are true then return 1.
// 3  Else return 0 (one is empty and other is not)

#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                             malloc(sizeof(struct node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;

    return(node);
}

/* Given two trees, return true if they are
 structurally identical */
int identicalTrees(struct node* a, struct node* b)
{
    /*1. both empty */
    if (a==NULL && b==NULL)
        return 1;

    /* 2. both non-empty -> compare them */
    else if (a!=NULL && b!=NULL)
   {
        return
        (
            a->data == b->data &&
            identicalTrees(a->left, b->left) &&
            identicalTrees(a->right, b->right)
        );
    }
    /* 3. one empty, one not -> false */
    else return 0;
}

/* Driver program to test identicalTrees function*/
int main()
{
    struct node *root1 = newNode(1);
    struct node *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5); 

    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5); 

    if(identicalTrees(root1, root2))
        printf("Both tree are identical.");
    else
        printf("Trees are not identical.");

    getchar();
  return 0;
}
