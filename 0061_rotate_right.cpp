class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr) return head;
        int len = 0;
        ListNode* ptr = head;
        ListNode* tail = nullptr;
        while (ptr != nullptr) {
            ++len;
            tail = ptr;
            ptr = ptr->next;
        }
        cout << "tail: " << tail->val << endl;
        if (len == 1) return head;
        k = k % len;
        if (k == 0) return head;
        k = len - k;
        ptr = head;
        cout << "k = " << k << "\tlen = " << len << endl;
        while (k > 1) {
            ptr = ptr->next;
            cout << ptr->val << endl;
            --k;
        }
        tail->next = head;
        ListNode* newhead = ptr->next;
        ptr->next = nullptr;
        ListNode* p1 = newhead;
        cout << "debug"<< endl;
        while (p1) {
            cout << p1->val << endl;
            p1=p1->next;
        }
        return newhead;
    }
};
