#include <iostream>

using namespace std;

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        int num = l1->val + l2->val;
        int bonus = num / 10;
        num = num % 10;
        ListNode* pHead = new ListNode(num);
        ListNode* ptr = pHead;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 != nullptr && l2 != nullptr) {
            num = l1->val + l2->val + bonus;
            bonus = num / 10;
            num = num % 10;
            ptr->next = new ListNode(num);
            ptr = ptr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == nullptr) {
            ptr->next = l2;
        }
        if (l2 == nullptr) {
            ptr->next = l1;
        }
        ListNode* prev = ptr;
        ptr = ptr->next;
        while (ptr != nullptr) {
            ptr->val = ptr->val + bonus;
            bonus = ptr->val / 10;
            ptr->val %= 10;
            prev = ptr;
            ptr = ptr->next;
        }
        if (bonus != 0) {
            prev->next = new ListNode(bonus);
        }
        return pHead;
    }
};

int main()
{
    return 0;
}
