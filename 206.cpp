class Solution {
    ListNode *p;
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};