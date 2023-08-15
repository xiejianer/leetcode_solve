/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // copy list
        if (head == nullptr) return head;
        Node* ptr = head;
        while (ptr != nullptr) {
            Node* p = new Node(ptr->val);
            p->next = ptr->next;
            ptr->next = p;
            ptr = ptr->next->next;
        }
        ptr = head;
        Node* p = nullptr;
        while (ptr != nullptr) {
            p = ptr->next;
            if (ptr->random == nullptr) {
                p->random = nullptr;
            } else {
                p->random = ptr->random->next;
            }
            ptr = p->next;
        }
        ptr = head;
        Node* copy_head = head->next;
        while (ptr != nullptr) {
            p = ptr->next;
            if (p == nullptr) {
                break;
            }
            ptr->next = p->next;
            ptr = p;
        }
        return copy_head;
    }
};
