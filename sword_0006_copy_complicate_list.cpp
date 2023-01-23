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
        if (head == nullptr) return nullptr;
        Node* curr = head;
        Node* pnext = head->next;
        Node* phead = nullptr;
        // insert node
        while (curr != nullptr) {
            Node* tmp = new Node(curr->val);
            if (phead == nullptr) {
                // save the first insert node
                phead = tmp;
            }
            curr->next = tmp;
            tmp->next = pnext;
            curr = pnext;
            if (pnext != nullptr) {
                pnext = pnext->next;
            }
        }
        // copy random pointer
        Node* ptr1 = head;
        Node* ptr2 = head->next;
        while (ptr1 != nullptr) {
            if (ptr1->random != nullptr) {
                ptr2->random = ptr1->random->next;
            }
            ptr1 = ptr2->next;
            if (ptr1 != nullptr) {
                ptr2 = ptr1->next;
            }
        }
        // split the list
        ptr1 = head;
        ptr2 = head->next;
        while (ptr1 != nullptr) {
            ptr1->next = ptr2->next;
            Node* tmp = ptr2->next;
            ptr1 = tmp;
            if (tmp != nullptr) {
                ptr2->next = tmp->next;
                ptr2 = tmp->next;
            }
        }
        return phead;
    }
};
