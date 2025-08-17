#include <stdlib.h>

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

static struct ListNode* newNode(int v)
{
    struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));
    n->val = v;
    n->next = NULL;
    return n;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    // Dummy head 
    struct ListNode dummy = {0, NULL};
    struct ListNode* tail = &dummy;

    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int x = (l1 ? l1->val : 0);
        int y = (l2 ? l2->val : 0);
        int sum = x + y + carry;

        tail->next = newNode(sum % 10); // current digit
        tail = tail->next;

        carry = sum / 10;               // next carry

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    return dummy.next; // skip dummy
}
