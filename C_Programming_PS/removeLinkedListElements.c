/*
Definition:
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Solution:
- To remove all the nodes in a linked list that have a given value, you can traverse the linked list while keeping track of the previous node. If a node has the target value, you skip it by adjusting the pointers.
- In this code, we define the removeElements function that takes the head of a linked list and an integer value val. We create a dummy node at the beginning to handle the case when the head itself needs to be removed. We traverse the linked list using two pointers, prev and current. If the value of the current node matches val, we skip it by adjusting the pointers and freeing the memory. If the value does not match, we move the pointers forward. After traversing the entire list, we update the head to the next node of the dummy node and free the dummy node.


*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val)
{
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode *prev = dummy;
    struct ListNode *current = head;

    while (current != NULL)
    {
        if (current->val == val)
        {
            prev->next = current->next;
            struct ListNode *temp = current;
            current = current->next;
            free(temp);
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }

    struct ListNode *newHead = dummy->next;
    free(dummy);

    return newHead;
}

// Helper function to create a new node in the linked list
struct ListNode *createNode(int val)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the linked list
void printLinkedList(struct ListNode *head)
{
    struct ListNode *current = head;

    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    // Create a sample linked list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    struct ListNode *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(6);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(6);

    printf("Original Linked List: ");
    printLinkedList(head);

    int val = 6;
    struct ListNode *newHead = removeElements(head, val);

    printf("Linked List after removing %d: ", val);
    printLinkedList(newHead);

    return 0;
}
