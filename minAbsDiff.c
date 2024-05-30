/*
-- Description:
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
Input: root = [4,2,6,1,3]
Output: 1

-- LeetCode: https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

-- Solution:
In-order Traversal:
We traverse the BST in in-order fashion (left subtree, root, right subtree).
During the traversal, we keep track of the previous node value using the prev variable.
For each node, we calculate the difference between the current node's value and the previous node's value. If this difference is smaller than the current minimum difference (minDiff), we update minDiff.
We update the prev variable to the current node's value.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to perform in-order traversal
void inorderTraversal(struct TreeNode *root, int *prev, int *minDiff)
{
    if (root == NULL)
        return;

    // Traverse left subtree
    inorderTraversal(root->left, prev, minDiff);

    // Update the minimum difference
    if (*prev != -1)
    {
        int diff = root->val - *prev;
        if (diff < *minDiff)
        {
            *minDiff = diff;
        }
    }

    // Update previous node value
    *prev = root->val;

    // Traverse right subtree
    inorderTraversal(root->right, prev, minDiff);
}

// Function to find the minimum absolute difference
int getMinimumDifference(struct TreeNode *root)
{
    int minDiff = INT_MAX;
    int prev = -1; // Initialize previous node value as -1 (or any invalid value)
    inorderTraversal(root, &prev, &minDiff);
    return minDiff;
}

// Helper function to create a new tree node
struct TreeNode *newTreeNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Main function to test the code
int main()
{
    // Example 1
    struct TreeNode *root1 = newTreeNode(4);
    root1->left = newTreeNode(2);
    root1->right = newTreeNode(6);
    root1->left->left = newTreeNode(1);
    root1->left->right = newTreeNode(3);

    printf("Minimum difference in Example 1: %d\n", getMinimumDifference(root1));

    struct TreeNode *root2 = newTreeNode(1);
    root2->left = newTreeNode(0);
    root2->right = newTreeNode(48);
    root2->right->left = newTreeNode(12);
    root2->right->right = newTreeNode(49);

    printf("Minimum difference in Example 2: %d\n", getMinimumDifference(root2));

    return 0;
}
