#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ptr = nullptr;
		ListNode* pHead = nullptr;
		int plus = 0;
		int val = 0;
		int sum = 0;
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		sum = l1->val + l2->val + plus;
		plus = sum / 10;
		val = sum % 10;
		pHead = new ListNode(val, nullptr);
		ptr = pHead;
		l1 = l1->next;
		l2 = l2->next;
		while (l1 != nullptr && l2 != nullptr) {
			sum = l1->val + l2->val + plus;
			plus = sum / 10;
			val = sum % 10;
			ptr->next = new ListNode(val, nullptr);
			ptr = ptr->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		ptr->next = (l1 == nullptr) ? l2: l1;
		if (ptr->next == nullptr) {
			if (plus != 0) {
				ptr->next = new ListNode(plus, nullptr);
			}
			return pHead;
		}
		ptr = ptr->next;
		ListNode* ptr1 = nullptr;
		while (ptr != nullptr && plus != 0) {
			sum = ptr->val + plus;
			ptr->val = sum % 10;
			plus = sum / 10;
			ptr1 = ptr;
			ptr = ptr->next;
		}
		if (plus != 0) {
			ptr1->next = new ListNode(plus, nullptr);
		}
		return pHead;
	}
}; 

int main()
{
	
	return 0;
}
