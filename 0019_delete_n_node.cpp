#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int num): val(num), next(nullptr) {}
    ListNode(): val(0), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return head;
        } 
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* q = dummy;
        while (n > 0 && p != nullptr) {
            p = p->next;
            --n;
        }
        if (n >= 0 && p == nullptr) {
            return dummy->next;
        }
        if (n == 0 && p != nullptr) {
            p = p->next;
        }
        while (p != nullptr) {
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;
        return dummy->next;
    }
};

int main()
{
    ListNode * head = new ListNode(1);
    Solution s;
    ListNode* ptr = s.removeNthFromEnd(head, 1);
    if (ptr != nullptr) {
        cout << ptr->val << endl;
    } else {
        cout << "empty list" << endl;
    }
    return 0;
}