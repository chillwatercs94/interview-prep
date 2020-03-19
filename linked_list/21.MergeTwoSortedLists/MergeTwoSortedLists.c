
/*
 * 1. Forgot about empty input case
 * 2. Forgot about l1->val == l2->val case
 * 3. while loop can be simplified, combining
 *    - l1->val == l2->val
 *    - l2->val > l2->val
 */

#if 1
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode nodeToHead = {.next = NULL};
    struct ListNode *currNode = &nodeToHead;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            currNode->next = l1;
            l1 = l1->next;
        } else {
            currNode->next = l2;
            l2 = l2->next;
        }
        currNode = currNode->next;
    }
    
    if (l1 != NULL)
        currNode->next = l1;
    if (l2 != NULL)
        currNode->next = l2;

    return nodeToHead.next;
}

#else

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode nodeToHead = {.next = NULL};
    struct ListNode *currNode = &nodeToHead;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            currNode->next = l1;
            l1 = l1->next;
            currNode = currNode->next;
        } else if (l1->val > l2->val) {
            currNode->next = l2;
            l2 = l2->next;
            currNode = currNode->next;
        } else {
            currNode->next = l1;
            l1 = l1->next;
            currNode = currNode->next;

            currNode->next = l2;
            l2 = l2->next;
            currNode = currNode->next;
        }
    }
    
    if (l1 != NULL)
        currNode->next = l1;
    if (l2 != NULL)
        currNode->next = l2;

    return nodeToHead.next;

}

#endif
