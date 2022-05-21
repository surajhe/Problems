// Deep copy of Linked List with gine *next and *random pointers refer bewlo structure of Node.

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {

    RandomListNode* head1 = A;
    struct RandomListNode* head2 = NULL;
    map<RandomListNode*, RandomListNode*> mp;

    head2 = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
    head2->label = head1->label;

    RandomListNode* h1;
    RandomListNode* h2;
    RandomListNode* h3;

    h1 = head1;
    h2 = h3 = head2;

    mp.insert({h1, h2});

    h1 = h1->next;

    while(h1 != NULL)
    {
        struct RandomListNode* newNode = NULL;
        newNode = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
        newNode->label = h1->label;
        h2->next = newNode;
        mp.insert({h1,h2->next});
        h1 = h1->next;
        h2 = h2->next;
    }

    h2->next = NULL;

    while(head1 != NULL)
    {
       RandomListNode* node = mp[head1->random];
       head2->random = node;
       head1 = head1->next;
       head2 = head2->next;
    }

    return h3;
}
