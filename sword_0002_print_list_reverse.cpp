class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> s;
        while (head != nullptr) {
            s.push(head->val);
            head = head->next;
        }
        vector<int> vec;
        while (! s.empty()) {
            vec.push_back(s.top());
            s.pop();
        }
        return vec;
    }
};
