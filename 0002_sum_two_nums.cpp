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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        int num = l1->val + l2->val;
        int bonus = num / 10;
        num = num % 10;
        ListNode* pNode = new ListNode(num);
        l1 = l1->next;
        l2 = l2->next;
        ListNode* curr = pNode;
        while (l1 != nullptr && l2 != nullptr) {
            num = l1->val + l2->val + bonus;
            bonus = num / 10;
            num = num % 10;
            curr->next = new ListNode(num);
            l1 = l1->next;
            l2 = l2->next;
            curr = curr->next;
        }
        if (l1 == nullptr) {
            curr->next = l2;
        }
        else if (l2 == nullptr) {
            curr->next = l1;
        }
        ListNode* prev = curr;
        curr = curr->next;
        while (curr != nullptr && bonus != 0) {
            bonus = (curr->val + bonus) / 10;
            curr->val = (curr->val + bonus) % 10;
            prev = curr;
            curr = curr->next;
        }
        if (bonus != 0) {
            prev->next = new ListNode(bonus);
        }
        return pNode;
    }
};
