// https://www.geeksforgeeks.org/problems/flattening-a-linked-list--170645/1?page=4&company=Goldman%20Sachs&sortBy=submissions

class Solution {
  public:
    Node *flatten(Node *root) {
        Node* dummy = new Node(-1);
        Node* last = dummy;
        while (root != nullptr) {
            Node* c1 = root;
            Node* c2 = nullptr;
            Node* m1 = c1;
            Node* m2 = nullptr;
            while (c1 != nullptr) {
                if (c1->data < m1->data) {
                    m1 = c1;
                    m2 = c2;
                }
                c2 = c1;
                c1 = c1->next;
            }
            
            if (m2 != nullptr) {
                if (m1->bottom != nullptr) {
                    m2->next = m1->bottom;
                    m1->bottom->next = m1->next;
                } else {
                    m2->next = m1->next;
                }
            } else {
                if (m1->bottom != nullptr) {
                    m1->bottom->next = m1->next;
                    root = m1->bottom;
                } else {
                    root = m1->next;
                }
            }
            m1->next = nullptr;
            m1->bottom = nullptr;
            last->bottom = m1;
            last = m1;
        }
        return dummy->bottom;
    }
};
