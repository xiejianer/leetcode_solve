class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* pNext = head;
        pNext->next = nullptr;
        while (curr != nullptr) {
            pNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = pNext;
        }
        return prev;
    }
};
