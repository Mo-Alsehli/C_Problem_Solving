/*
intersectionOfTwoLinkedLists.c
Mohamed Magdi

- Description.
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'

- Solution:
First using constant space check for last element of both lists.
If tails of both lists are different then return NULL

Now we know that intersection length will be same for both lists. So we want to make length prior to the intersection also equal.
Head pointer of the longer list is moved to next till length of both lists become equal

NOW we will have intersetion point at the same distance from head for both the lists.

Now keep comparing heads till match found.
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    struct ListNode *Intersection = NULL;
    struct ListNode *ptrA = headA;
    struct ListNode *ptrB = headB;
    int aLen = 0, bLen = 0;

    while (ptrA->next != NULL)
    {
        ptrA = ptrA->next;
        aLen++;
    }
    while (ptrB->next != NULL)
    {
        ptrB = ptrB->next;
        bLen++;
    }

    if (ptrA->val != ptrB->val)
    {
        printf("Here\n");
        return NULL;
    }
    ptrA = headA;
    ptrB = headB;

    if (aLen > bLen)
    {
        while (aLen != bLen)
        {
            ptrA = ptrA->next;
            aLen--;
        }
    }
    else
    {
        while (aLen != bLen)
        {
            ptrB = ptrB->next;
            bLen--;
        }
    }

    while (ptrB != ptrA)
    {
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }

    return ptrA;
}

// Helper Functions Using Chatgbt

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
    // Create the linked lists
    struct ListNode *listA = createNode(4);
    listA->next = createNode(1);
    listA->next->next = createNode(8);
    listA->next->next->next = createNode(4);
    listA->next->next->next->next = createNode(5);

    struct ListNode *listB = createNode(5);
    listB->next = createNode(6);
    listB->next->next = createNode(1);
    listB->next->next->next = createNode(8);
    listB->next->next->next->next = createNode(4);
    listB->next->next->next->next->next = createNode(5);

    // Set the intersection point
    struct ListNode *intersectNode = listA->next->next;
    listB->next->next->next->next->next->next = intersectNode;

    // Print the linked lists
    printf("List A: ");
    printLinkedList(listA);

    printf("List B: ");
    printLinkedList(listB);

    // Find the intersection point
    struct ListNode *intersection = getIntersectionNode(listA, listB);

    if (intersection != NULL)
    {
        printf("Intersected at '%d'\n", intersection->val);
    }
    else
    {
        printf("No intersection found\n");
    }

    return 0;
}
