// http://www.geeksforgeeks.org/in-place-conversion-of-sorted-dll-to-balanced-bst/
// Given a Doubly Linked List which has data members sorted in ascending order.
// Construct a Balanced Binary Search Tree which has same data members as
// the given Doubly Linked List. The tree must be constructed in-place
// (No new node should be allocated for tree conversion)
//
// 1) Get the Middle of the linked list and make it root.
// 2) Recursively do same for left half and right half.
//        a) Get the middle of left half and make it left child of the root
//           created in step 1.
//        b) Get the middle of right half and make it right child of the
//           root created in step 1.


// In this method, we construct from leaves to root. The idea is to insert
// nodes in BST in the same order as the appear in Doubly Linked List, so
// that the tree can be constructed in O(n) time complexity. We first count
// the number of nodes in the given Linked List. Let the count be n. After
// counting nodes, we take left n/2 nodes and recursively construct the left
// subtree. After left subtree is constructed, we assign middle node to root
// and link the left subtree with root. Finally, we recursively construct
// the right subtree and link it with root.
//
// While constructing the BST, we also keep moving the list head pointer
// to next so that we have the appropriate pointer in each recursive call.

#include<stdio.h>
#include<stdlib.h>
 
/* A Doubly Linked List node that will also be used as a tree node */
struct Node
{
    int data;
 
    // For tree, next pointer can be used as left subtree pointer
    struct Node* next;
 
    // For tree, prev pointer can be used as right subtree pointer
    struct Node* prev;
};
 
 
// A utility function to count nodes in a Linked List
int countNodes(struct Node *head);
 
struct Node* sortedListToBSTRecur(struct Node **head_ref, int n);
 
/* This function counts the number of nodes in Linked List and then calls
   sortedListToBSTRecur() to construct BST */
struct Node* sortedListToBST(struct Node *head)
{
    /*Count the number of nodes in Linked List */
    int n = countNodes(head);
 
    /* Construct BST */
    return sortedListToBSTRecur(&head, n);
}
 
/* The main function that constructs balanced BST and returns root of it.
       head_ref -->  Pointer to pointer to head node of Doubly linked list
       n  --> No. of nodes in the Doubly Linked List */
struct Node* sortedListToBSTRecur(struct Node **head_ref, int n)
{
    /* Base Case */
    if (n <= 0)
        return NULL;
 
    /* Recursively construct the left subtree */
    struct Node *left = sortedListToBSTRecur(head_ref, n/2);
 
    /* head_ref now refers to middle node, make middle node as root of BST*/
    struct Node *root = *head_ref;
 
    // Set pointer to left subtree
    root->prev = left;
 
    /* Change head pointer of Linked List for parent recursive calls */
    *head_ref = (*head_ref)->next;
 
    /* Recursively construct the right subtree and link it with root
      The number of nodes in right subtree  is total nodes - nodes in
      left subtree - 1 (for root) */
    root->next = sortedListToBSTRecur(head_ref, n-n/2-1);
 
    return root;
}
 
/* UTILITY FUNCTIONS */
/* A utility function that returns count of nodes in a given Linked List */
int countNodes(struct Node *head)
{
    int count = 0;
    struct Node *temp = head;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
 
/* Function to insert a node at the beginging of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* since we are adding at the begining,
      prev is always NULL */
    new_node->prev = NULL;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* change prev of head node to new node */
    if((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while(node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* A utility function to print preorder traversal of BST */
void preOrder(struct Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->prev);
    preOrder(node->next);
}
 
/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    /* Let us create a sorted linked list to test the functions
     Created linked list will be 7->6->5->4->3->2->1 */
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    printf("\n Given Linked List ");
    printList(head);
 
    /* Convert List to BST */
    struct Node *root = sortedListToBST(head);
    printf("\n PreOrder Traversal of constructed BST ");
    preOrder(root);
 
    return 0;
}
