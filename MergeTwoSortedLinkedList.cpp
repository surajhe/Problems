// Problem Description
// Merge two sorted linked lists, A and B, and return it as a new list.

// The new list should be made by splicing together the nodes of the first two lists and should also be sorted.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {

    ListNode* h1 = A;
    ListNode* h2 = B;
    ListNode* h3;
    ListNode* l;

    if(h1 == NULL)
    {
        return h2;
    }
    if(h2 == NULL)
    {
        return h1;
    }

    if(h1->val < h2->val)
    {
        h3 = l = h1;
        h1 = h1-> next;
    }
    else
    {
        h3 = l = h2;
        h2 = h2->next;

    }

    while(h1 != NULL && h2 != NULL)
    {
        if(h1->val > h2->val)
        {
            l->next = h2;
            h2 = h2->next;
        }
        else
        {
            l->next = h1;
            h1 = h1->next;
        }

        l = l->next;

    }

    if(h1 == NULL)
    {
        l->next  = h2;

    }

    if(h2 == NULL)
    {
        l->next  = h1;    
    }

    return h3;
}
