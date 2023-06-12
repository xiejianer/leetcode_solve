class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(); 
        ListNode* ptr = dummy; 
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }      
        ptr->next = (list1 == nullptr) ? list2: list1;
        return dummy->next;
    }
};