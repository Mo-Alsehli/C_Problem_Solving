#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *createNode(int val)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

bool isPalindrome(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true; // Empty list or single node list is a palindrome
    }

    // Find the middle of the linked list using the slow and fast pointer technique
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *prevSlow = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prevSlow = slow;
        slow = slow->next;
    }

    // Reverse the second half of the linked list starting from the slow pointer
    struct ListNode *current = slow;
    struct ListNode *prev = NULL;
    struct ListNode *nextNode = NULL;

    while (current != NULL)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    // Compare the first half (head to prevSlow) with the second half (prev to NULL)
    struct ListNode *firstHalf = head;
    struct ListNode *secondHalf = prev;

    while (secondHalf != NULL)
    {
        if (firstHalf->val != secondHalf->val)
        {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

void printLinkedList(struct ListNode *head)
{
    struct ListNode *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

void freeLinkedList(struct ListNode *head)
{
    struct ListNode *current = head;
    while (current != NULL)
    {
        struct ListNode *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    struct ListNode *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    printf("Original Linked List: ");
    printLinkedList(head);

    bool result = isPalindrome(head);

    printf("Is palindrome: %s\n", result ? "true" : "false");

    freeLinkedList(head);

    return 0;
}
