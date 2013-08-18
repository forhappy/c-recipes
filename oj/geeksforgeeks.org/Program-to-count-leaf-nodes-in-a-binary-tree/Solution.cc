// http://www.geeksforgeeks.org/write-a-c-program-to-get-count-of-leaf-nodes-in-a-binary-tree/
// getLeafCount(node)
// 1) If node is NULL then return 0.
// 2) Else If left and right child nodes are NULL return 1.
// 3) Else recursively calculate leaf count of the tree using below formula.
//     Leaf count of a tree = Leaf count of left subtree +
//                                  Leaf count of right subtree

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

/* Function to get the count of leaf nodes in a binary tree*/
unsigned int getLeafCount(struct node* node)
{
  if(node == NULL)       
    return 0;
  if(node->left == NULL && node->right==NULL)      
    return 1;            
  else 
    return getLeafCount(node->left)+
           getLeafCount(node->right);      
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data) 
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  
  return(node);
}

/*Driver program to test above functions*/  
int main()
{
  /*create a tree*/  
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);    
  
  /*get leaf count of the above created tree*/
  printf("Leaf count of the tree is %d", getLeafCount(root));
  
  getchar();
  return 0;
}
