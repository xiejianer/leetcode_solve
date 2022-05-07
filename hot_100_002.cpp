#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr = new ListNode();
        int num1 = 0;
        int num2 = 0;
        int num = 0;
        int plus = 0;
        ListNode* phead = ptr;
		ListNode* prev = nullptr;
        while (l1 != nullptr or l2 != nullptr or plus > 0) {
            num1 = 0;
            num2 = 0;
            if (l1 != nullptr) {
                num1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                num2 = l2->val;
                l2 = l2->next;
            }
            num = num1 + num2 + plus;
            plus = num / 10;
            num = num % 10;
            ptr->val = num;
            ptr->next = new ListNode();
			prev = ptr;
            ptr = ptr->next;
        }
		prev->next = nullptr;
		delete ptr;
        return phead;
    }
};

int main()
{
    return  0;
}
