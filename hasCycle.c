#include <stdlib.h>
#include <stdio.h>

/*
Problem Description:
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.

Solution:
To determine if a linked list has a cycle, you can use the Floyd's cycle-finding algorithm, also known as the "tortoise and hare" algorithm. The idea is to have two pointers, one moving at a slower pace (tortoise) and another moving at a faster pace (hare). If there is a cycle in the linked list, eventually the hare will catch up to the tortoise.
*/

typedef enum bool
{
    false,
    true
} bool;

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        // Empty list or only one node, no cycle
        return false;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            // Cycle detected
            return true;
        }
    }

    // No cycle found
    return false;
}

int

main()
{

    // Create a linked list with a cycle

    struct ListNode node1, node2, node3, node4;

    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node4.val = 4;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node2;
    // Create a cycle from node4 to node2

    // Test the hasCycle function

    bool result = hasCycle(&node1);

    printf("Cycle detected: %s\n", result ? "true" : "false");

    return 0;
}
