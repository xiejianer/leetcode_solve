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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;
        int len = k - 1;
        ListNode* ptr = head;
        while (len > 0 && ptr != nullptr){
            ptr = ptr->next;
            --len;
        }
        if (ptr == nullptr) return head;
        ListNode* ptr2 = ptr->next;
        ptr->next = nullptr;
        ListNode* ptr1 = reverseList(head);
        head->next = reverseKGroup(ptr2, k);
        return ptr1;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        if (head->next == nullptr) return head;
        ListNode* ptr1 = head->next;
        ListNode* ptr2 = reverseList(ptr1);
        ptr1->next = head;
        return ptr2;
    }
};
