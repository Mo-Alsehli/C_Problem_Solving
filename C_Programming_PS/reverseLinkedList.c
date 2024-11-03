#include <stdio.h>
#include <stdlib.h>

/*
-- Description:
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    // Using Recursion
    /*  // Base case: empty list or single node
     if (head == NULL || head->next == NULL) {
         return head;
     }

     // Recursively reverse the rest of the list
     struct ListNode* reversedList = reverseList(head->next);

     // Adjust the next pointer of the current node
     head->next->next = head;
     head->next = NULL;

     return reversedList; */

    struct ListNode *p = NULL;
    struct ListNode *q = NULL;

    while (head != NULL)
    {
        p = q;
        q = head;
        head = head->next;
        q->next = p;
    }

    return q;
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
    // Create the linked list
    struct ListNode *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Print the original linked list
    printf("Original List: ");
    printLinkedList(head);

    // Reverse the linked list
    struct ListNode *reversedList = reverseList(head);

    // Print the reversed linked list
    printf("Reversed List: ");
    printLinkedList(reversedList);

    return 0;
}
