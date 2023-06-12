class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];
        ListNode* ptr1 = mergeKLists(lists, 0, lists.size() / 2 - 1);
        ListNode* ptr2 = mergeKLists(lists, lists.size() / 2, lists.size() - 1);
        return merge2Lists(ptr1, ptr2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists, int left, int right) {
        if (left > right) return nullptr;
        if (left == right) return lists[left];
        return merge2Lists(mergeKLists(lists, left, (right + left) / 2), mergeKLists(lists, (right + left) / 2 + 1, right));
    }

    ListNode* merge2Lists(ListNode* ptr1, ListNode* ptr2) {
        ListNode* dummy = new ListNode();
        ListNode* ptr = dummy;
        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1->val <= ptr2->val) {
                ptr->next = ptr1;
                ptr1 = ptr1->next;
            } else {
                ptr->next = ptr2;
                ptr2 = ptr2->next;
            }
            ptr = ptr->next;
        }
        ptr->next = (ptr1 == nullptr) ? ptr2: ptr1;
        return dummy->next;
    }
};
