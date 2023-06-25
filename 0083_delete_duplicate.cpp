/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* q = head;
        ListNode* p = head->next;
        while (p != nullptr) {
            if (q->val == p->val) {
                p = p->next;
            } else {
                q->next = p;
                q = p;
                p = p->next;
            }
        }
        q->next = p;
        return head;
    }
};
