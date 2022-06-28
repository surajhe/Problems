// Problem Description
// Sort a linked list, A in O(n log n) time using constant space complexity.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 ListNode* mergeTwoLists(ListNode* A, ListNode* B) {

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

ListNode* getMiddle(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* Solution::sortList(ListNode* A) {

    if(A == NULL || A->next == NULL)
    {
        return A;
    }

    ListNode* h1 = A;
    ListNode* h2;

    ListNode* c1 = getMiddle(h1);
    h2 = c1->next;
    c1->next = NULL;

    h1 = sortList(h1);
    h2 = sortList(h2);

    return mergeTwoLists(h1, h2);
}
