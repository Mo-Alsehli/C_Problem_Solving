/*
-- Description:
Given a n-ary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

Example1:
Input: root = [1,null,3,2,4,null,5,6]
Output: 3

Example2:
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 5

LeetCode: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/

-- Solution:
Traverse throw each child branch and count max Depth.

-- Complexity
Time complexity: O(n) --> n: number of nodes
Space complexity: O(h) --> h: max Depth of tree
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a Node.
struct Node
{
    int val;
    int numChildren;
    struct Node **children;
};

int maxDepth(struct Node *root)
{
    if (root == NULL)
        return 0;
    int max_child_depth = 0;
    for (int i = 0; i < root->numChildren; i++)
    {
        int child_depth = maxDepth(root->children[i]);
        if (child_depth > max_child_depth)
        {
            max_child_depth = child_depth;
        }
    }
    return max_child_depth + 1;
}

struct Node *createNode(int val, int numChildren)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->numChildren = numChildren;
    newNode->children = (struct Node **)malloc(numChildren * sizeof(struct Node *));
    return newNode;
}

int main()
{
    // Example 1: [1,null,3,2,4,null,5,6]
    struct Node *root = createNode(1, 3);
    root->children[0] = createNode(3, 2);
    root->children[1] = createNode(2, 0);
    root->children[2] = createNode(4, 0);
    root->children[0]->children[0] = createNode(5, 0);
    root->children[0]->children[1] = createNode(6, 0);

    int depth = maxDepth(root);
    printf("Max Depth: %d\n", depth); // Expected Output: 3

    return 0;
}
