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
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        do {
            if (slow == nullptr) {
                return nullptr;
            }
            slow = slow->next;
            if (fast == nullptr || fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
        } while (fast != slow);
        if (slow != fast) return nullptr;
        fast = head;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
