//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

#include <stack>
#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* next;
};

Node* reverse(Node* node) {
    Node* next = node->next;
    if (next != nullptr)
    {
        Node* head = reverse(next);
        next->next = node;
        node->next = nullptr;
        return head;
    }
    else
    {
        node->next = nullptr;
        return node;
    }
}
