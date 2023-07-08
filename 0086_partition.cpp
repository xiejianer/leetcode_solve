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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(x - 1, nullptr);
        dummy->next = head;
        ListNode* r = dummy;
        ListNode* p = head;
        // 找到第一个比x大的节点的前一个位置
        while (p != nullptr) {
            if (p->val >= x) {
                break;
            } else {
                r = p;
                p = p->next;
            }
        }
        if (r == nullptr || r->next == nullptr) return head;
        ListNode* q = r;
        p = r->next;
        while (p != nullptr) {
            if (p->val < x) {
                break;
            } else {
                q = p;
                p = p->next;
            }
        }
        while (p != nullptr) {
            ListNode* ptr = p;
            if (p->val < x) {
                q->next = p->next;
                p->next = r->next;
                r->next = p;
                r = r->next;
            }
            q = ptr;
            if (q != nullptr) {
                p = q->next;
            }
            while (p != nullptr) {
                if (p->val < x) {
                    break;
                } else {
                    q = p;
                    p = p->next;
                }
            }
        }
        return dummy->next;
    }
};
控制台

