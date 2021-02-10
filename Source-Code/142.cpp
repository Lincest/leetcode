/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        do {
            if (!fast || !fast->next) return nullptr;
            fast = fast->next->next;  // 快指针每次移动两格
            slow = slow->next;  // 慢指针每次移动一格
        } while (fast != slow);
        //  fast与slow相遇
        fast = head; // fast移动到起点
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};