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
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* dummy = new ListNode(head->val - 1, head);
        ListNode* p = head;
        ListNode* q = dummy;
        while (p->next != nullptr) {
            if (p->val != p->next->val) {
                q = p;
                p = p->next;
            } else {
                while (p->next != nullptr) {
                    if (p->val == p->next->val) {
                        p = p->next;
                    } else {
                        break;
                    }
                }
                if (p->next == nullptr) {
                    q->next = p->next;
                    break;
                } else {
                    p = p->next;
                    q->next = p;
                }
            }
        }
        return dummy->next;
    }
};
