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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* before_left = nullptr;
        ListNode* p = dummy;
        ListNode* q = nullptr;
        int cnt = left;
        while (p != nullptr && cnt > 0) {
            q = p;
            p = p->next;
            --cnt;
        }
        before_left = q;
        ListNode* begin_node = p;
        if (p == nullptr) return head;
        q = p;
        p = p->next;
        ListNode* ptr = nullptr;
        while (p != nullptr && left < right) {
            //cout << "val: " << p->val << endl;
            ptr = p->next;
            p->next = q;
            q = p;
            p = ptr;
            ++left;
        }
        before_left->next = q;
        begin_node->next = p;
        return dummy->next;
    }
};
