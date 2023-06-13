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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        if (head->next == nullptr) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* ptr = head->next->next;
        head->next->next = head;
        dummy->next = head->next;
        head->next = swapPairs(ptr);
        return dummy->next;
    }
};
